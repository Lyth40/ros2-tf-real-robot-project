#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include "my_robot_interfaces/action/simple_navigation.hpp"
#include "my_robot_interfaces/srv/simple_trajectory.hpp"
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

using namespace std::chrono_literals;
using SimpleNavigation = my_robot_interfaces::action::SimpleNavigation;
using SimpleTrajectory = my_robot_interfaces::srv::SimpleTrajectory;
using GoalHandleSimpleNavigation = rclcpp_action::ServerGoalHandle<SimpleNavigation>;

class SimpleNavigationActionServer : public rclcpp::Node {
public:
    SimpleNavigationActionServer()
    : Node("simple_navigation_action_server"),
      tf_buffer_(this->get_clock()),
      tf_listener_(tf_buffer_)
    {
    

        navigation_srv_ = rclcpp_action::create_server<SimpleNavigation>(
            this,
            "/simple_navigation",
            std::bind(&SimpleNavigationActionServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&SimpleNavigationActionServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&SimpleNavigationActionServer::handle_accepted, this, std::placeholders::_1)
        );

        trajectory_client_ = this->create_client<SimpleTrajectory>("/simple_trajectory");
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        RCLCPP_INFO(this->get_logger(), "SimpleNavigation Action Server initialized.");
    }

private:
    rclcpp_action::Server<SimpleNavigation>::SharedPtr navigation_srv_;
    rclcpp::Client<SimpleTrajectory>::SharedPtr trajectory_client_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &,
        std::shared_ptr<const SimpleNavigation::Goal> goal)
    {
        RCLCPP_INFO(this->get_logger(), "Received goal: start=%d clockwise=%d", goal->start, goal->clockwise);
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleSimpleNavigation> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Goal canceled.");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleSimpleNavigation> goal_handle)
    {
        std::thread{std::bind(&SimpleNavigationActionServer::execute, this, goal_handle)}.detach();
    }

    void execute(const std::shared_ptr<GoalHandleSimpleNavigation> goal_handle)
    {
        auto goal = goal_handle->get_goal();
        auto result = std::make_shared<SimpleNavigation::Result>();
        auto feedback = std::make_shared<SimpleNavigation::Feedback>();

        if (!trajectory_client_->wait_for_service(5s)) {
            RCLCPP_ERROR(this->get_logger(), "Trajectory service not available.");
            result->completed = false;
            goal_handle->abort(result);
            return;
        }

       
        while (rclcpp::ok() && this->get_clock()->now().nanoseconds() == 0) {
            RCLCPP_WARN(this->get_logger(), "Waiting for clock to become valid...");
            rclcpp::sleep_for(100ms);
        }

        auto request = std::make_shared<SimpleTrajectory::Request>();
        request->start = goal->start;
        request->clockwise = goal->clockwise;
        auto future = trajectory_client_->async_send_request(request);

        RCLCPP_INFO(this->get_logger(), "Waiting for 'waypoint_frame' to appear...");
        int attempts = 0;
        while (!tf_buffer_.canTransform("start_feature", "waypoint_frame", rclcpp::Time(0)) && rclcpp::ok() && attempts < 100) {
            rclcpp::sleep_for(100ms);
            attempts++;
        }
        if (attempts >= 100) {
            RCLCPP_ERROR(this->get_logger(), "Timeout waiting for waypoint_frame.");
            result->completed = false;
            goal_handle->abort(result);
            return;
        }

        rclcpp::Rate rate(10);
        const std::string base_frame = "base_link";
        const std::string waypoint_frame = "waypoint_frame";
        const std::string start_frame = "start_feature";

        bool lap_completed = false;
        bool left_start_area = false;

        while (rclcpp::ok()) {
            if (goal_handle->is_canceling()) {
                result->completed = false;
                goal_handle->canceled(result);
                RCLCPP_INFO(this->get_logger(), "Goal canceled.");
                return;
            }

            geometry_msgs::msg::TransformStamped tf_wp;
            geometry_msgs::msg::TransformStamped tf_start;
            try {
                tf_wp = tf_buffer_.lookupTransform(base_frame, waypoint_frame, rclcpp::Time(0));
                tf_start = tf_buffer_.lookupTransform(base_frame, start_frame, rclcpp::Time(0));
            } catch (tf2::TransformException &ex) {
                RCLCPP_WARN(this->get_logger(), "TF error: %s", ex.what());
                rate.sleep();
                continue;
            }

            double dx = tf_wp.transform.translation.x;
            double dy = tf_wp.transform.translation.y;
            double distance = sqrt(dx * dx + dy * dy);
            feedback->current_distance = distance;
            goal_handle->publish_feedback(feedback);

            geometry_msgs::msg::Twist cmd_vel;
            double linear_speed = 0.5 * distance;
            double angular_speed = 2.0 * std::atan2(dy, dx);
            linear_speed = std::min(linear_speed, 0.5);
            angular_speed = std::clamp(angular_speed, -1.0, 1.0);

            cmd_vel.linear.x = linear_speed;
            cmd_vel.angular.z = angular_speed;
            cmd_vel_publisher_->publish(cmd_vel);
            geometry_msgs::msg::Twist stop_cmd;

            if (distance < 0.1) {
                
                cmd_vel_publisher_->publish(stop_cmd);
            }

            double dx_start = tf_start.transform.translation.x;
            double dy_start = tf_start.transform.translation.y;
            double dist_to_start = sqrt(dx_start * dx_start + dy_start * dy_start);

            if (dist_to_start > 0.5) {
                left_start_area = true;
            }

            if (left_start_area && dist_to_start < 0.3) {
                lap_completed = true;
                cmd_vel_publisher_->publish(stop_cmd);
                break;
            }

            rate.sleep();
        }

        if (lap_completed) {
            result->completed = true;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Navigation goal succeeded. Lap complete.");
        } else {
            result->completed = false;
            goal_handle->abort(result);
            RCLCPP_WARN(this->get_logger(), "Navigation goal aborted.");
        }
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleNavigationActionServer>());
    rclcpp::shutdown();
    return 0;
}
