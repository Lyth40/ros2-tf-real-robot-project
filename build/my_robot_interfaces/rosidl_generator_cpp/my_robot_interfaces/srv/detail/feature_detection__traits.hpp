// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_robot_interfaces:srv/FeatureDetection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__TRAITS_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_robot_interfaces/srv/detail/feature_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureDetection_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: feature
  {
    out << "feature: ";
    rosidl_generator_traits::value_to_yaml(msg.feature, out);
    out << ", ";
  }

  // member: feature_id
  {
    out << "feature_id: ";
    rosidl_generator_traits::value_to_yaml(msg.feature_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureDetection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feature: ";
    rosidl_generator_traits::value_to_yaml(msg.feature, out);
    out << "\n";
  }

  // member: feature_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feature_id: ";
    rosidl_generator_traits::value_to_yaml(msg.feature_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureDetection_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::srv::FeatureDetection_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::srv::FeatureDetection_Request & msg)
{
  return my_robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::srv::FeatureDetection_Request>()
{
  return "my_robot_interfaces::srv::FeatureDetection_Request";
}

template<>
inline const char * name<my_robot_interfaces::srv::FeatureDetection_Request>()
{
  return "my_robot_interfaces/srv/FeatureDetection_Request";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::FeatureDetection_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::srv::FeatureDetection_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::srv::FeatureDetection_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'positions'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace my_robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const FeatureDetection_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FeatureDetection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FeatureDetection_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_robot_interfaces::srv::FeatureDetection_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_robot_interfaces::srv::FeatureDetection_Response & msg)
{
  return my_robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_robot_interfaces::srv::FeatureDetection_Response>()
{
  return "my_robot_interfaces::srv::FeatureDetection_Response";
}

template<>
inline const char * name<my_robot_interfaces::srv::FeatureDetection_Response>()
{
  return "my_robot_interfaces/srv/FeatureDetection_Response";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::FeatureDetection_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_robot_interfaces::srv::FeatureDetection_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_robot_interfaces::srv::FeatureDetection_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_robot_interfaces::srv::FeatureDetection>()
{
  return "my_robot_interfaces::srv::FeatureDetection";
}

template<>
inline const char * name<my_robot_interfaces::srv::FeatureDetection>()
{
  return "my_robot_interfaces/srv/FeatureDetection";
}

template<>
struct has_fixed_size<my_robot_interfaces::srv::FeatureDetection>
  : std::integral_constant<
    bool,
    has_fixed_size<my_robot_interfaces::srv::FeatureDetection_Request>::value &&
    has_fixed_size<my_robot_interfaces::srv::FeatureDetection_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_robot_interfaces::srv::FeatureDetection>
  : std::integral_constant<
    bool,
    has_bounded_size<my_robot_interfaces::srv::FeatureDetection_Request>::value &&
    has_bounded_size<my_robot_interfaces::srv::FeatureDetection_Response>::value
  >
{
};

template<>
struct is_service<my_robot_interfaces::srv::FeatureDetection>
  : std::true_type
{
};

template<>
struct is_service_request<my_robot_interfaces::srv::FeatureDetection_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_robot_interfaces::srv::FeatureDetection_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__TRAITS_HPP_
