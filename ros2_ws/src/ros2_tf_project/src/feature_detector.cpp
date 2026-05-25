#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/transform.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include "my_robot_interfaces/srv/feature_detection.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <cmath>

using FeatureDetection = my_robot_interfaces::srv::FeatureDetection;

class FeatureDetector : public rclcpp::Node {
public:
    FeatureDetector()
        : Node("feature_detector"), tf_buffer_(this->get_clock()), tf_listener_(tf_buffer_) {
        scan_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, std::bind(&FeatureDetector::scanCallback, this, std::placeholders::_1));

        feature_srv_ = this->create_service<FeatureDetection>(
            "/feature_detection",std::bind(&FeatureDetector::handleFeatureDetection, this, std::placeholders::_1, std::placeholders::_2));

        static_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
        RCLCPP_INFO(this->get_logger(), "Feature Detector Initialized");
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_sub_;
    rclcpp::Service<FeatureDetection>::SharedPtr feature_srv_;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> static_broadcaster_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    sensor_msgs::msg::LaserScan::SharedPtr last_scan_;
    std::vector<std::pair<std::string, geometry_msgs::msg::Point>> detected_features_;

    void saveFeaturesToYaml(const std::vector<std::pair<std::string, geometry_msgs::msg::Point>>& features, const std::string& filename)
    {
        YAML::Node root;
        YAML::Node feature_frames = YAML::Node(YAML::NodeType::Sequence);

        for (const auto& f : features) {
            YAML::Node item;
            item["feature"] = f.first;
            item["position"]["x"] = f.second.x;
            item["position"]["y"] = f.second.y;
            item["position"]["z"] = f.second.z;
            feature_frames.push_back(item);
        }

        root["feature_frames"] = feature_frames;

        std::ofstream fout(filename);
        if (!fout.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open YAML file for writing: %s", filename.c_str());
            return;
        }
        fout << root;
        fout.close();
    }

    void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        last_scan_ = msg;
    }

    cv::Vec4f fitLine(const std::vector<cv::Point2f>& points) {
        cv::Vec4f line;
        cv::fitLine(points, line, cv::DIST_L2, 0, 0.01, 0.01);
        return line;
    }

    float pointLineDistance(const cv::Point2f& pt, const cv::Vec4f& line) {
        float vx = line[0], vy = line[1];
        float x0 = line[2], y0 = line[3];
        return std::abs(vy * pt.x - vx * pt.y + (vx * y0 - vy * x0)) / std::sqrt(vx * vx + vy * vy);
    }

    int splitAndMerge(const std::vector<cv::Point2f>& points,
                   std::vector<std::vector<cv::Point2f>>& segments,
                   float threshold) {
        if (points.size() < 2) return 0;

        cv::Vec4f line = fitLine(points);

        float maxDist = 0.0f;
        size_t index = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            float dist = pointLineDistance(points[i], line);
            if (dist > maxDist) {
                maxDist = dist;
                RCLCPP_WARN(this->get_logger(), "distance: %f", dist);
                index = i;

            }
        }
        
        if (maxDist > threshold  && index > 0 && index < points.size() - 1) {
            std::vector<cv::Point2f> left(points.begin(), points.begin() + index + 1);
            std::vector<cv::Point2f> right(points.begin() + index, points.end());
            splitAndMerge(left, segments, threshold);
            splitAndMerge(left, segments, threshold);
        } else {
            segments.push_back(points);
        }
        RCLCPP_INFO(this->get_logger(), "index: %d", index);
        return static_cast<int>(index); 
    }

    void handleFeatureDetection(
        const std::shared_ptr<FeatureDetection::Request> request,
        std::shared_ptr<FeatureDetection::Response> response)
        {
        if (!last_scan_) {
            response->detected = false;
            response->message = "No scan data received yet.";
            return;
        }

        auto scan = last_scan_;
        double angle_min = scan->angle_min;
        double angle_increment = scan->angle_increment;

        int center_idx = std::round((0.0 - angle_min) / angle_increment);
        int offset = std::round((M_PI / 4) / angle_increment);  // ±45°
        int start_idx = center_idx - offset;
        int end_idx = center_idx + offset;
        float angle=0;
        float range=0;
        RCLCPP_INFO(this->get_logger(), "start: %d", start_idx);
        RCLCPP_INFO(this->get_logger(), "end: %d", end_idx);
        std::vector<cv::Point2f> points;


        bool found = false;
        geometry_msgs::msg::Point best_point;

        if(request->feature =="corner" )
        {

            for (int i = start_idx; i <= end_idx; ++i) {
                if (i < 0 || i >= static_cast<int>(scan->ranges.size()))
                    continue;
                    float r = scan->ranges[i];
                    // if (r < 0.1 || r > 0.8) continue;
                    angle = scan->angle_min + i * scan->angle_increment;
                    points.emplace_back(r * cos(angle), r * sin(angle));
            }
            
            
            std::vector<std::vector<cv::Point2f>> segments;
            int index = splitAndMerge(points, segments, 0.5) + start_idx;
             angle = angle_min + index* angle_increment;
             range = scan->ranges[index];
        }else if(request->feature =="obstacle"){
             angle = angle_min + center_idx* angle_increment;
             range = scan->ranges[center_idx];}

        
        geometry_msgs::msg::Point p;
        p.x = range * cos(angle);
        p.y = range * sin(angle);
        p.z = 0.0;

                // Transform point to odom frame
        geometry_msgs::msg::PoseStamped scan_pose, odom_pose;
        scan_pose.header.frame_id = scan->header.frame_id;
        scan_pose.header.stamp = scan->header.stamp;
        scan_pose.pose.position = p;
        scan_pose.pose.orientation.w = 1.0;

        try {
            odom_pose = tf_buffer_.transform(scan_pose, "odom");
            best_point = odom_pose.pose.position;
            found = true;

                    // Optional: Broadcast static TF for feature
            geometry_msgs::msg::TransformStamped static_tf;
            static_tf.header.stamp = now();
            static_tf.header.frame_id = "odom";
            static_tf.child_frame_id = request->feature + "_" + request->feature_id;

            static_tf.transform.translation.x = best_point.x;
            static_tf.transform.translation.y = best_point.y;
            static_tf.transform.translation.z = best_point.z;
            static_tf.transform.rotation.w = 1.0;

            static_broadcaster_->sendTransform(static_tf);
            
        } catch (const tf2::TransformException &ex) {
            RCLCPP_WARN(this->get_logger(), "TF Error: %s", ex.what());
        }
        response->detected = found;
        if (found) {
            response->message = "Feature detected: " + request->feature + " [" + request->feature_id + "]";
            // response->positions.push_back(best_point);  
            std::string feature_name = request->feature+"_"+request->feature_id+"_frame" ;
            auto it = std::find_if(detected_features_.begin(), detected_features_.end(),
                           [&feature_name](const auto& f){ return f.first == feature_name; });
            if (it != detected_features_.end()) {
                it->second = best_point;  // update existing
            } else {
                detected_features_.emplace_back(feature_name, best_point);
            }
            saveFeaturesToYaml(detected_features_,
                 "/home/latih/ros2-tf-real-robot-project/ros2_ws/src/ros2_tf_project/frames/static_frames_sim.yaml");

            
            response->positions.push_back(best_point);


        } else {
            response->message = "No feature detected in frontal range.";
        }
    }

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FeatureDetector>());
    rclcpp::shutdown();
    return 0;
}
