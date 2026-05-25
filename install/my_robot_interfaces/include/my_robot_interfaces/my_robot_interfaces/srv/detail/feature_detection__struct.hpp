// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:srv/FeatureDetection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureDetection_Request_
{
  using Type = FeatureDetection_Request_<ContainerAllocator>;

  explicit FeatureDetection_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feature = "";
      this->feature_id = "";
    }
  }

  explicit FeatureDetection_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : feature(_alloc),
    feature_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->feature = "";
      this->feature_id = "";
    }
  }

  // field types and members
  using _feature_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feature_type feature;
  using _feature_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _feature_id_type feature_id;

  // setters for named parameter idiom
  Type & set__feature(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feature = _arg;
    return *this;
  }
  Type & set__feature_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->feature_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Request
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Request
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureDetection_Request_ & other) const
  {
    if (this->feature != other.feature) {
      return false;
    }
    if (this->feature_id != other.feature_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureDetection_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureDetection_Request_

// alias to use template instance with default allocator
using FeatureDetection_Request =
  my_robot_interfaces::srv::FeatureDetection_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces


// Include directives for member types
// Member 'positions'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct FeatureDetection_Response_
{
  using Type = FeatureDetection_Response_<ContainerAllocator>;

  explicit FeatureDetection_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->message = "";
    }
  }

  explicit FeatureDetection_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->message = "";
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _positions_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _positions_type positions;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__positions(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Response
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__FeatureDetection_Response
    std::shared_ptr<my_robot_interfaces::srv::FeatureDetection_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FeatureDetection_Response_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->positions != other.positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const FeatureDetection_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FeatureDetection_Response_

// alias to use template instance with default allocator
using FeatureDetection_Response =
  my_robot_interfaces::srv::FeatureDetection_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace srv
{

struct FeatureDetection
{
  using Request = my_robot_interfaces::srv::FeatureDetection_Request;
  using Response = my_robot_interfaces::srv::FeatureDetection_Response;
};

}  // namespace srv

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_HPP_
