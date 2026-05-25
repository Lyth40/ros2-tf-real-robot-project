// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:srv/SimpleTrajectory.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__SIMPLE_TRAJECTORY__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__SIMPLE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/srv/detail/simple_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SimpleTrajectory_Request_clockwise
{
public:
  explicit Init_SimpleTrajectory_Request_clockwise(::my_robot_interfaces::srv::SimpleTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::SimpleTrajectory_Request clockwise(::my_robot_interfaces::srv::SimpleTrajectory_Request::_clockwise_type arg)
  {
    msg_.clockwise = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::SimpleTrajectory_Request msg_;
};

class Init_SimpleTrajectory_Request_start
{
public:
  Init_SimpleTrajectory_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleTrajectory_Request_clockwise start(::my_robot_interfaces::srv::SimpleTrajectory_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_SimpleTrajectory_Request_clockwise(msg_);
  }

private:
  ::my_robot_interfaces::srv::SimpleTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::SimpleTrajectory_Request>()
{
  return my_robot_interfaces::srv::builder::Init_SimpleTrajectory_Request_start();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_SimpleTrajectory_Response_message
{
public:
  explicit Init_SimpleTrajectory_Response_message(::my_robot_interfaces::srv::SimpleTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::srv::SimpleTrajectory_Response message(::my_robot_interfaces::srv::SimpleTrajectory_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::srv::SimpleTrajectory_Response msg_;
};

class Init_SimpleTrajectory_Response_completed
{
public:
  Init_SimpleTrajectory_Response_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleTrajectory_Response_message completed(::my_robot_interfaces::srv::SimpleTrajectory_Response::_completed_type arg)
  {
    msg_.completed = std::move(arg);
    return Init_SimpleTrajectory_Response_message(msg_);
  }

private:
  ::my_robot_interfaces::srv::SimpleTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::srv::SimpleTrajectory_Response>()
{
  return my_robot_interfaces::srv::builder::Init_SimpleTrajectory_Response_completed();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__SIMPLE_TRAJECTORY__BUILDER_HPP_
