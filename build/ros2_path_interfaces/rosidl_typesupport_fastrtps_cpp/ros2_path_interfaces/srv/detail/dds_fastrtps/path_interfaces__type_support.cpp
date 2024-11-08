// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice
#include "ros2_path_interfaces/srv/detail/path_interfaces__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_path_interfaces/srv/detail/path_interfaces__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_path_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
cdr_serialize(
  const ros2_path_interfaces::srv::PathInterfaces_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: global_request
  cdr << ros_message.global_request;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_path_interfaces::srv::PathInterfaces_Request & ros_message)
{
  // Member: global_request
  cdr >> ros_message.global_request;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
get_serialized_size(
  const ros2_path_interfaces::srv::PathInterfaces_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: global_request
  {
    size_t item_size = sizeof(ros_message.global_request);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
max_serialized_size_PathInterfaces_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: global_request
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _PathInterfaces_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_path_interfaces::srv::PathInterfaces_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PathInterfaces_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_path_interfaces::srv::PathInterfaces_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PathInterfaces_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_path_interfaces::srv::PathInterfaces_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PathInterfaces_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PathInterfaces_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _PathInterfaces_Request__callbacks = {
  "ros2_path_interfaces::srv",
  "PathInterfaces_Request",
  _PathInterfaces_Request__cdr_serialize,
  _PathInterfaces_Request__cdr_deserialize,
  _PathInterfaces_Request__get_serialized_size,
  _PathInterfaces_Request__max_serialized_size
};

static rosidl_message_type_support_t _PathInterfaces_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PathInterfaces_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_path_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_path_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_path_interfaces::srv::PathInterfaces_Request>()
{
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_path_interfaces, srv, PathInterfaces_Request)() {
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ros2_path_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
cdr_serialize(
  const ros2_path_interfaces::srv::PathInterfaces_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: local_response
  cdr << ros_message.local_response;
  // Member: data
  {
    cdr << ros_message.data;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_path_interfaces::srv::PathInterfaces_Response & ros_message)
{
  // Member: local_response
  cdr >> ros_message.local_response;

  // Member: data
  {
    cdr >> ros_message.data;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
get_serialized_size(
  const ros2_path_interfaces::srv::PathInterfaces_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: local_response
  {
    size_t item_size = sizeof(ros_message.local_response);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: data
  {
    size_t array_size = ros_message.data.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.data[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_path_interfaces
max_serialized_size_PathInterfaces_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: local_response
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: data
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

static bool _PathInterfaces_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_path_interfaces::srv::PathInterfaces_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PathInterfaces_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_path_interfaces::srv::PathInterfaces_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PathInterfaces_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_path_interfaces::srv::PathInterfaces_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PathInterfaces_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PathInterfaces_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _PathInterfaces_Response__callbacks = {
  "ros2_path_interfaces::srv",
  "PathInterfaces_Response",
  _PathInterfaces_Response__cdr_serialize,
  _PathInterfaces_Response__cdr_deserialize,
  _PathInterfaces_Response__get_serialized_size,
  _PathInterfaces_Response__max_serialized_size
};

static rosidl_message_type_support_t _PathInterfaces_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PathInterfaces_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_path_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_path_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_path_interfaces::srv::PathInterfaces_Response>()
{
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_path_interfaces, srv, PathInterfaces_Response)() {
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace ros2_path_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _PathInterfaces__callbacks = {
  "ros2_path_interfaces::srv",
  "PathInterfaces",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_path_interfaces, srv, PathInterfaces_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_path_interfaces, srv, PathInterfaces_Response)(),
};

static rosidl_service_type_support_t _PathInterfaces__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PathInterfaces__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace ros2_path_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_path_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<ros2_path_interfaces::srv::PathInterfaces>()
{
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_path_interfaces, srv, PathInterfaces)() {
  return &ros2_path_interfaces::srv::typesupport_fastrtps_cpp::_PathInterfaces__handle;
}

#ifdef __cplusplus
}
#endif
