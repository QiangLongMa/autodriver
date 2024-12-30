// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__INS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GNSS__MSG__DETAIL__INS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gnss/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "gnss/msg/detail/ins__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace gnss
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
cdr_serialize(
  const gnss::msg::Ins & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gnss::msg::Ins & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
get_serialized_size(
  const gnss::msg::Ins & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
max_serialized_size_Ins(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gnss

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gnss, msg, Ins)();

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__INS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
