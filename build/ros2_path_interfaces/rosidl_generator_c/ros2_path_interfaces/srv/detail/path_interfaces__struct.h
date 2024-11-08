// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_H_
#define ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/PathInterfaces in the package ros2_path_interfaces.
typedef struct ros2_path_interfaces__srv__PathInterfaces_Request
{
  int32_t global_request;
} ros2_path_interfaces__srv__PathInterfaces_Request;

// Struct for a sequence of ros2_path_interfaces__srv__PathInterfaces_Request.
typedef struct ros2_path_interfaces__srv__PathInterfaces_Request__Sequence
{
  ros2_path_interfaces__srv__PathInterfaces_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_path_interfaces__srv__PathInterfaces_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/PathInterfaces in the package ros2_path_interfaces.
typedef struct ros2_path_interfaces__srv__PathInterfaces_Response
{
  int32_t local_response;
  rosidl_runtime_c__double__Sequence data;
} ros2_path_interfaces__srv__PathInterfaces_Response;

// Struct for a sequence of ros2_path_interfaces__srv__PathInterfaces_Response.
typedef struct ros2_path_interfaces__srv__PathInterfaces_Response__Sequence
{
  ros2_path_interfaces__srv__PathInterfaces_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_path_interfaces__srv__PathInterfaces_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_H_
