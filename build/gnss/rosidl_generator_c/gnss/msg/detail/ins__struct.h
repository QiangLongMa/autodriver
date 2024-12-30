// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__INS__STRUCT_H_
#define GNSS__MSG__DETAIL__INS__STRUCT_H_

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

// Struct defined in msg/Ins in the package gnss.
typedef struct gnss__msg__Ins
{
  std_msgs__msg__Header header;
  double latitude;
  double longitude;
  double height;
  float undulation;
  double north_velocity;
  double east_velocity;
  double up_velocity;
  double roll;
  double pitch;
  double azimuth;
  float latitude_std;
  float longitude_std;
  float height_std;
  float north_velocity_std;
  float east_velocity_std;
  float up_velocity_std;
  float roll_std;
  float pitch_std;
  float azimuth_std;
} gnss__msg__Ins;

// Struct for a sequence of gnss__msg__Ins.
typedef struct gnss__msg__Ins__Sequence
{
  gnss__msg__Ins * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gnss__msg__Ins__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__INS__STRUCT_H_
