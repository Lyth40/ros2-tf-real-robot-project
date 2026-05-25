// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:action/SimpleNavigation.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__ACTION__DETAIL__SIMPLE_NAVIGATION__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__ACTION__DETAIL__SIMPLE_NAVIGATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/action/detail/simple_navigation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_Goal_clockwise
{
public:
  explicit Init_SimpleNavigation_Goal_clockwise(::my_robot_interfaces::action::SimpleNavigation_Goal & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_Goal clockwise(::my_robot_interfaces::action::SimpleNavigation_Goal::_clockwise_type arg)
  {
    msg_.clockwise = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Goal msg_;
};

class Init_SimpleNavigation_Goal_start
{
public:
  Init_SimpleNavigation_Goal_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_Goal_clockwise start(::my_robot_interfaces::action::SimpleNavigation_Goal::_start_type arg)
  {
    msg_.start = std::move(arg);
    return Init_SimpleNavigation_Goal_clockwise(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_Goal>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_Goal_start();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_Result_total_distance
{
public:
  explicit Init_SimpleNavigation_Result_total_distance(::my_robot_interfaces::action::SimpleNavigation_Result & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_Result total_distance(::my_robot_interfaces::action::SimpleNavigation_Result::_total_distance_type arg)
  {
    msg_.total_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Result msg_;
};

class Init_SimpleNavigation_Result_message
{
public:
  explicit Init_SimpleNavigation_Result_message(::my_robot_interfaces::action::SimpleNavigation_Result & msg)
  : msg_(msg)
  {}
  Init_SimpleNavigation_Result_total_distance message(::my_robot_interfaces::action::SimpleNavigation_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_SimpleNavigation_Result_total_distance(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Result msg_;
};

class Init_SimpleNavigation_Result_completed
{
public:
  Init_SimpleNavigation_Result_completed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_Result_message completed(::my_robot_interfaces::action::SimpleNavigation_Result::_completed_type arg)
  {
    msg_.completed = std::move(arg);
    return Init_SimpleNavigation_Result_message(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_Result>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_Result_completed();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_Feedback_current_distance
{
public:
  Init_SimpleNavigation_Feedback_current_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_Feedback current_distance(::my_robot_interfaces::action::SimpleNavigation_Feedback::_current_distance_type arg)
  {
    msg_.current_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_Feedback>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_Feedback_current_distance();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_SendGoal_Request_goal
{
public:
  explicit Init_SimpleNavigation_SendGoal_Request_goal(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request goal(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request msg_;
};

class Init_SimpleNavigation_SendGoal_Request_goal_id
{
public:
  Init_SimpleNavigation_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_SendGoal_Request_goal goal_id(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SimpleNavigation_SendGoal_Request_goal(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_SendGoal_Request>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_SendGoal_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_SendGoal_Response_stamp
{
public:
  explicit Init_SimpleNavigation_SendGoal_Response_stamp(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response stamp(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response msg_;
};

class Init_SimpleNavigation_SendGoal_Response_accepted
{
public:
  Init_SimpleNavigation_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_SendGoal_Response_stamp accepted(::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SimpleNavigation_SendGoal_Response_stamp(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_SendGoal_Response>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_SendGoal_Response_accepted();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_GetResult_Request_goal_id
{
public:
  Init_SimpleNavigation_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_GetResult_Request goal_id(::my_robot_interfaces::action::SimpleNavigation_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_GetResult_Request>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_GetResult_Request_goal_id();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_GetResult_Response_result
{
public:
  explicit Init_SimpleNavigation_GetResult_Response_result(::my_robot_interfaces::action::SimpleNavigation_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_GetResult_Response result(::my_robot_interfaces::action::SimpleNavigation_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_GetResult_Response msg_;
};

class Init_SimpleNavigation_GetResult_Response_status
{
public:
  Init_SimpleNavigation_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_GetResult_Response_result status(::my_robot_interfaces::action::SimpleNavigation_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SimpleNavigation_GetResult_Response_result(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_GetResult_Response>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_GetResult_Response_status();
}

}  // namespace my_robot_interfaces


namespace my_robot_interfaces
{

namespace action
{

namespace builder
{

class Init_SimpleNavigation_FeedbackMessage_feedback
{
public:
  explicit Init_SimpleNavigation_FeedbackMessage_feedback(::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage feedback(::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage msg_;
};

class Init_SimpleNavigation_FeedbackMessage_goal_id
{
public:
  Init_SimpleNavigation_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SimpleNavigation_FeedbackMessage_feedback goal_id(::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SimpleNavigation_FeedbackMessage_feedback(msg_);
  }

private:
  ::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::action::SimpleNavigation_FeedbackMessage>()
{
  return my_robot_interfaces::action::builder::Init_SimpleNavigation_FeedbackMessage_goal_id();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__ACTION__DETAIL__SIMPLE_NAVIGATION__BUILDER_HPP_
