// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__MESSAGE__STRUCT_H_
#define GNSS__MSG__DETAIL__MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'array'
#include "std_msgs/msg/detail/float64_multi_array__struct.h"

// Struct defined in msg/Message in the package gnss.
typedef struct gnss__msg__Message
{
  std_msgs__msg__Header header;
  std_msgs__msg__Float64MultiArray array;
} gnss__msg__Message;

// Struct for a sequence of gnss__msg__Message.
typedef struct gnss__msg__Message__Sequence
{
  gnss__msg__Message * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gnss__msg__Message__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__MESSAGE__STRUCT_H_
