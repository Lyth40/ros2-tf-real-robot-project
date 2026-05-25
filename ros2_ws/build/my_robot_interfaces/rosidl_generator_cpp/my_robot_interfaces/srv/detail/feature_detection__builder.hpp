// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/FeatureDetection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/feature_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_FeatureDetection_Request_feature_id
{
public:
  explicit Init_FeatureDetection_Request_feature_id(::my_robot_interfaces::srv::FeatureDetection_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::FeatureDetection_Request feature_id(::my_robot_interfaces::srv::FeatureDetection_Request::_feature_id_type arg)
  {
    msg_.feature_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::FeatureDetection_Request msg_;
};

class Init_FeatureDetection_Request_feature
{
public:
  Init_FeatureDetection_Request_feature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureDetection_Request_feature_id feature(::my_robot_interfaces::srv::FeatureDetection_Request::_feature_type arg)
  {
    msg_.feature = std::move(arg);
    return Init_FeatureDetection_Request_feature_id(msg_);
  }

private:
  ::my_robot_interfaces::srv::FeatureDetection_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::FeatureDetection_Request>()
{
  return my_robot_interfaces::srv::builder::Init_FeatureDetection_Request_feature();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_FeatureDetection_Response_positions
{
public:
  explicit Init_FeatureDetection_Response_positions(::my_robot_interfaces::srv::FeatureDetection_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::FeatureDetection_Response positions(::my_robot_interfaces::srv::FeatureDetection_Response::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::FeatureDetection_Response msg_;
};

class Init_FeatureDetection_Response_message
{
public:
  explicit Init_FeatureDetection_Response_message(::my_robot_interfaces::srv::FeatureDetection_Response & msg)
  : msg_(msg)
  {}
  Init_FeatureDetection_Response_positions message(::my_robot_interfaces::srv::FeatureDetection_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_FeatureDetection_Response_positions(msg_);
  }

private:
  ::my_robot_interfaces::srv::FeatureDetection_Response msg_;
};

class Init_FeatureDetection_Response_detected
{
public:
  Init_FeatureDetection_Response_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FeatureDetection_Response_message detected(::my_robot_interfaces::srv::FeatureDetection_Response::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_FeatureDetection_Response_message(msg_);
  }

private:
  ::my_robot_interfaces::srv::FeatureDetection_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::FeatureDetection_Response>()
{
  return my_robot_interfaces::srv::builder::Init_FeatureDetection_Response_detected();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__BUILDER_HPP_
