// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_robot_interfaces:srv/FeatureDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_robot_interfaces/srv/detail/feature_detection__rosidl_typesupport_introspection_c.h"
#include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_robot_interfaces/srv/detail/feature_detection__functions.h"
#include "my_robot_interfaces/srv/detail/feature_detection__struct.h"


// Include directives for member types
// Member `feature`
// Member `feature_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__srv__FeatureDetection_Request__init(message_memory);
}

void my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_fini_function(void * message_memory)
{
  my_robot_interfaces__srv__FeatureDetection_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_member_array[2] = {
  {
    "feature",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__srv__FeatureDetection_Request, feature),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feature_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__srv__FeatureDetection_Request, feature_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_members = {
  "my_robot_interfaces__srv",  // message namespace
  "FeatureDetection_Request",  // message name
  2,  // number of fields
  sizeof(my_robot_interfaces__srv__FeatureDetection_Request),
  my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_member_array,  // message members
  my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_type_support_handle = {
  0,
  &my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Request)() {
  if (!my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__srv__FeatureDetection_Request__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "my_robot_interfaces/srv/detail/feature_detection__rosidl_typesupport_introspection_c.h"
// already included above
// #include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "my_robot_interfaces/srv/detail/feature_detection__functions.h"
// already included above
// #include "my_robot_interfaces/srv/detail/feature_detection__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `positions`
#include "geometry_msgs/msg/point.h"
// Member `positions`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_robot_interfaces__srv__FeatureDetection_Response__init(message_memory);
}

void my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_fini_function(void * message_memory)
{
  my_robot_interfaces__srv__FeatureDetection_Response__fini(message_memory);
}

size_t my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__size_function__FeatureDetection_Response__positions(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_const_function__FeatureDetection_Response__positions(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_function__FeatureDetection_Response__positions(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__fetch_function__FeatureDetection_Response__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_const_function__FeatureDetection_Response__positions(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__assign_function__FeatureDetection_Response__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_function__FeatureDetection_Response__positions(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__resize_function__FeatureDetection_Response__positions(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_member_array[3] = {
  {
    "detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__srv__FeatureDetection_Response, detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__srv__FeatureDetection_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces__srv__FeatureDetection_Response, positions),  // bytes offset in struct
    NULL,  // default value
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__size_function__FeatureDetection_Response__positions,  // size() function pointer
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_const_function__FeatureDetection_Response__positions,  // get_const(index) function pointer
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__get_function__FeatureDetection_Response__positions,  // get(index) function pointer
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__fetch_function__FeatureDetection_Response__positions,  // fetch(index, &value) function pointer
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__assign_function__FeatureDetection_Response__positions,  // assign(index, value) function pointer
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__resize_function__FeatureDetection_Response__positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_members = {
  "my_robot_interfaces__srv",  // message namespace
  "FeatureDetection_Response",  // message name
  3,  // number of fields
  sizeof(my_robot_interfaces__srv__FeatureDetection_Response),
  my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_member_array,  // message members
  my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_type_support_handle = {
  0,
  &my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Response)() {
  my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_robot_interfaces__srv__FeatureDetection_Response__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "my_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "my_robot_interfaces/srv/detail/feature_detection__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_members = {
  "my_robot_interfaces__srv",  // service namespace
  "FeatureDetection",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_Request_message_type_support_handle,
  NULL  // response message
  // my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_Response_message_type_support_handle
};

static rosidl_service_type_support_t my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_type_support_handle = {
  0,
  &my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_robot_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection)() {
  if (!my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_type_support_handle.typesupport_identifier) {
    my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_robot_interfaces, srv, FeatureDetection_Response)()->data;
  }

  return &my_robot_interfaces__srv__detail__feature_detection__rosidl_typesupport_introspection_c__FeatureDetection_service_type_support_handle;
}
