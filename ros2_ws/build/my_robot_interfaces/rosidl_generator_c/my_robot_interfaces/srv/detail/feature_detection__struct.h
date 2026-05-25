// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/FeatureDetection.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'feature'
// Member 'feature_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/FeatureDetection in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__FeatureDetection_Request
{
  rosidl_runtime_c__String feature;
  rosidl_runtime_c__String feature_id;
} my_robot_interfaces__srv__FeatureDetection_Request;

// Struct for a sequence of my_robot_interfaces__srv__FeatureDetection_Request.
typedef struct my_robot_interfaces__srv__FeatureDetection_Request__Sequence
{
  my_robot_interfaces__srv__FeatureDetection_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__FeatureDetection_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'positions'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/FeatureDetection in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__FeatureDetection_Response
{
  bool detected;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__Point__Sequence positions;
} my_robot_interfaces__srv__FeatureDetection_Response;

// Struct for a sequence of my_robot_interfaces__srv__FeatureDetection_Response.
typedef struct my_robot_interfaces__srv__FeatureDetection_Response__Sequence
{
  my_robot_interfaces__srv__FeatureDetection_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__FeatureDetection_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__FEATURE_DETECTION__STRUCT_H_
