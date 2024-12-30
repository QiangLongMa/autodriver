// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice
#include "ros2_path_interfaces/srv/detail/path_interfaces__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros2_path_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_path_interfaces/srv/detail/path_interfaces__struct.h"
#include "ros2_path_interfaces/srv/detail/path_interfaces__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PathInterfaces_Request__ros_msg_type = ros2_path_interfaces__srv__PathInterfaces_Request;

static bool _PathInterfaces_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PathInterfaces_Request__ros_msg_type * ros_message = static_cast<const _PathInterfaces_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: global_request
  {
    cdr << ros_message->global_request;
  }

  return true;
}

static bool _PathInterfaces_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PathInterfaces_Request__ros_msg_type * ros_message = static_cast<_PathInterfaces_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: global_request
  {
    cdr >> ros_message->global_request;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_path_interfaces
size_t get_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PathInterfaces_Request__ros_msg_type * ros_message = static_cast<const _PathInterfaces_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name global_request
  {
    size_t item_size = sizeof(ros_message->global_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PathInterfaces_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_path_interfaces
size_t max_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: global_request
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PathInterfaces_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PathInterfaces_Request = {
  "ros2_path_interfaces::srv",
  "PathInterfaces_Request",
  _PathInterfaces_Request__cdr_serialize,
  _PathInterfaces_Request__cdr_deserialize,
  _PathInterfaces_Request__get_serialized_size,
  _PathInterfaces_Request__max_serialized_size
};

static rosidl_message_type_support_t _PathInterfaces_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PathInterfaces_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_path_interfaces, srv, PathInterfaces_Request)() {
  return &_PathInterfaces_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ros2_path_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__struct.h"
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // data
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // data

// forward declare type support functions


using _PathInterfaces_Response__ros_msg_type = ros2_path_interfaces__srv__PathInterfaces_Response;

static bool _PathInterfaces_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PathInterfaces_Response__ros_msg_type * ros_message = static_cast<const _PathInterfaces_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: local_response
  {
    cdr << ros_message->local_response;
  }

  // Field name: data
  {
    size_t size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _PathInterfaces_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PathInterfaces_Response__ros_msg_type * ros_message = static_cast<_PathInterfaces_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: local_response
  {
    cdr >> ros_message->local_response;
  }

  // Field name: data
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->data.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->data);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->data, size)) {
      return "failed to create array for field 'data'";
    }
    auto array_ptr = ros_message->data.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_path_interfaces
size_t get_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PathInterfaces_Response__ros_msg_type * ros_message = static_cast<const _PathInterfaces_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name local_response
  {
    size_t item_size = sizeof(ros_message->local_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name data
  {
    size_t array_size = ros_message->data.size;
    auto array_ptr = ros_message->data.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PathInterfaces_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros2_path_interfaces
size_t max_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: local_response
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: data
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _PathInterfaces_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ros2_path_interfaces__srv__PathInterfaces_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PathInterfaces_Response = {
  "ros2_path_interfaces::srv",
  "PathInterfaces_Response",
  _PathInterfaces_Response__cdr_serialize,
  _PathInterfaces_Response__cdr_deserialize,
  _PathInterfaces_Response__get_serialized_size,
  _PathInterfaces_Response__max_serialized_size
};

static rosidl_message_type_support_t _PathInterfaces_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PathInterfaces_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_path_interfaces, srv, PathInterfaces_Response)() {
  return &_PathInterfaces_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ros2_path_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros2_path_interfaces/srv/path_interfaces.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PathInterfaces__callbacks = {
  "ros2_path_interfaces::srv",
  "PathInterfaces",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_path_interfaces, srv, PathInterfaces_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_path_interfaces, srv, PathInterfaces_Response)(),
};

static rosidl_service_type_support_t PathInterfaces__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PathInterfaces__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros2_path_interfaces, srv, PathInterfaces)() {
  return &PathInterfaces__handle;
}

#if defined(__cplusplus)
}
#endif
