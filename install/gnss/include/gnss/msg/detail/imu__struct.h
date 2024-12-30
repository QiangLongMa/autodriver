// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gnss:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__IMU__STRUCT_H_
#define GNSS__MSG__DETAIL__IMU__STRUCT_H_

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

// Struct defined in msg/Imu in the package gnss.
typedef struct gnss__msg__Imu
{
  std_msgs__msg__Header header;
  double x_linear_acceleration;
  double y_linear_acceleration;
  double z_linear_acceleration;
  double x_angular_velocity;
  double y_angular_velocity;
  double z_angular_velocity;
} gnss__msg__Imu;

// Struct for a sequence of gnss__msg__Imu.
typedef struct gnss__msg__Imu__Sequence
{
  gnss__msg__Imu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gnss__msg__Imu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__IMU__STRUCT_H_
