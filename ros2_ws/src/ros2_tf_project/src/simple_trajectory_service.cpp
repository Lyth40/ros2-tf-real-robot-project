#include <rclcpp/rclcpp.hpp>
#include "my_robot_interfaces/srv/simple_trajectory.hpp"
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_ros/transform_broadcaster.h> 
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

// Shortcut
using namespace std::chrono_literals;
using SimpleTrajectory = my_robot_interfaces::srv::SimpleTrajectory;

class SimpleTrajectoryService : public rclcpp::Node {
public:
    SimpleTrajectoryService()
    : Node("simple_trajectory_service"), 
      tf_buffer_(this->get_clock()),
      tf_listener_(tf_buffer_)
    {
        trajectory_srv_ = this->create_service<SimpleTrajectory>(
            "/simple_trajectory",
            std::bind(&SimpleTrajectoryService::handleSimpleTrajectory, this,
                      std::placeholders::_1, std::placeholders::_2)
        );

        static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
        tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        RCLCPP_INFO(this->get_logger(), "Simple Trajectory Service Initialized");

        broadcast_features();
        trajectory();
    }

private:
    rclcpp::Service<SimpleTrajectory>::SharedPtr trajectory_srv_;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> static_broadcaster_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    // tf2_ros::TransformBroadcaster tf_broadcaster_
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    std::vector<geometry_msgs::msg::Point> path;
    double x_center = 0;
    double y_center = 0;

    struct Feature {
        std::string name;
        geometry_msgs::msg::Point position;
    };

    void broadcast_features()
    {
        YAML::Node root = YAML::LoadFile(
            "/home/latih/ros2-tf-real-robot-project/ros2_ws/src/ros2_tf_project/frames/static_frames_sim.yaml");
        YAML::Node feature_frames = root["feature_frames"];

        for (const auto &item : feature_frames)
        {
            Feature f;
            f.name = item["feature"].as<std::string>();
            f.position.x = item["position"]["x"].as<double>();
            f.position.y = item["position"]["y"].as<double>();
            f.position.z = item["position"]["z"].as<double>();

            geometry_msgs::msg::TransformStamped static_tf;
            static_tf.header.stamp = rclcpp::Time(0);
            static_tf.header.frame_id = "odom";
            static_tf.child_frame_id = f.name;

            static_tf.transform.translation.x = f.position.x;
            static_tf.transform.translation.y = f.position.y;
            static_tf.transform.translation.z = f.position.z;
            static_tf.transform.rotation.w = 1.0;  // Identity quaternion

            static_broadcaster_->sendTransform(static_tf);
            rclcpp::sleep_for(std::chrono::milliseconds(10));  // Sleep for 500 milliseconds

        }
        double sum_x = 0.0, sum_y = 0.0;
        int count = 0;
        for(const auto &item:feature_frames)
        {   
            std::string name = item["feature"].as<std::string>();
            if(name.find("corner") != std::string::npos)
            {
                double x = item["position"]["x"].as<double>();
                double y = item["position"]["y"].as<double>();
                sum_x += x;
                sum_y += y;
                count++;
            }
        }
        if (count > 0) {
            x_center = sum_x / count;
            y_center = sum_y / count;

            RCLCPP_INFO(this->get_logger(), "Arena center in odom frame: (%.2f, %.2f)", x_center, y_center);
            geometry_msgs::msg::TransformStamped static_tf;
            static_tf.header.stamp =rclcpp::Time(0);
            static_tf.header.frame_id = "odom";
            static_tf.child_frame_id = "center";

            static_tf.transform.translation.x = x_center;
            static_tf.transform.translation.y = y_center;
            static_tf.transform.translation.z = 0.18891701572230546;
            static_tf.transform.rotation.w = 1.0;  // Identity quaternion

            static_broadcaster_->sendTransform(static_tf);
        }
        rclcpp::sleep_for(std::chrono::milliseconds(10));
    }

    void trajectory()
    {
        double w=1.8;
        double h=1.2;
        double r=0.2;
        int arc_points = 10;
        double z_map = 0.18891701572230546;

        double x_min = x_center - (w/2) +r;
        double x_max = x_center - 0.2 + (w/2) -r;
        double y_min = y_center - (h/2) +r;
        double y_max = y_center + 0.16 + (h/2) -r;
        geometry_msgs::msg::Point p;

        for (double x = x_max; x >= x_min; x -= 0.05) {
            p.x = x;
            p.y = y_min -r;
            p.z = z_map;
            path.push_back(p);

            

        }

        for (int i = 0; i <= arc_points; ++i) {
            double theta = M_PI * (1.5 - i / (double)arc_points * 0.5);
            p.x = x_min + r * cos(theta);
            p.y = y_min + r * sin(theta);
            p.z = z_map;
            path.push_back(p);
        }

        for (double y = y_min; y <= y_max; y += 0.05) {
            p.x = x_min - r;
            p.y = y;
            p.z = z_map;
            path.push_back(p);
        }

        for (int i = 0; i <= arc_points; ++i) {
            double theta = M_PI * (1.0 - i / (double)arc_points * 0.5);
            p.x = x_min + r * cos(theta);
            p.y = y_max + r * sin(theta);
            p.z = z_map;
            path.push_back(p);
        }

        for (double x = x_min; x <= x_max; x += 0.05) {
            p.x = x;
            p.y = y_max + r;
            p.z = z_map;
            path.push_back(p);
        }

        for (int i = 0; i <= arc_points; ++i) {
            double theta = M_PI * (0.5 - i / (double)arc_points * 0.5);
            p.x = x_max + r * cos(theta);
            p.y = y_max + r * sin(theta);
            p.z = z_map;
            path.push_back(p);
        }

        for (double y = y_max; y >= y_min; y -= 0.05) {
            p.x = x_max+r;
            p.y = y;
            p.z = z_map;
            path.push_back(p);
        }

        for (int i = 0; i <= arc_points; ++i) {
            double theta = - i / (double)arc_points * M_PI * 0.5;
            p.x = x_max + r * cos(theta);
            p.y = y_min + r * sin(theta);
            p.z = z_map;
            path.push_back(p);
        }

    }

   void handleSimpleTrajectory(
    const std::shared_ptr<SimpleTrajectory::Request> request,
    std::shared_ptr<SimpleTrajectory::Response> response)
    {
        if (!request->start) return;

        std::thread([=]() {
            if (request->clockwise) {
                for (auto point : path) {
                    geometry_msgs::msg::TransformStamped tf;
                    tf.header.stamp = this->get_clock()->now();  // ✅ correct timestamp
                    tf.header.frame_id = "center";
                    tf.child_frame_id = "waypoint_frame";
                    tf.transform.translation.x = point.x;
                    tf.transform.translation.y = point.y;
                    tf.transform.translation.z = 0.0;
                    tf.transform.rotation.w = 1.0;
                    tf_broadcaster_->sendTransform(tf);
                    rclcpp::sleep_for(500ms);  // ~10Hz
                }
            } else {
                for (auto it = path.rbegin(); it != path.rend(); ++it) {
                    geometry_msgs::msg::TransformStamped tf;
                    tf.header.stamp = this->get_clock()->now();
                    tf.header.frame_id = "center";
                    tf.child_frame_id = "waypoint_frame";
                    tf.transform.translation.x = it->x;
                    tf.transform.translation.y = it->y;
                    tf.transform.translation.z = 0.0;
                    tf.transform.rotation.w = 1.0;
                    tf_broadcaster_->sendTransform(tf);
                    rclcpp::sleep_for(500ms);
                }
            }
        }).detach();

        RCLCPP_INFO(this->get_logger(), "Waypoint broadcasting started.");
        response->completed = true;
        response->message = "Trajectory completed.";
    }


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleTrajectoryService>());
    rclcpp::shutdown();
    return 0;
}
