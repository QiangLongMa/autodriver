// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice
#include "gnss/msg/detail/ins__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "gnss/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "gnss/msg/detail/ins__struct.h"
#include "gnss/msg/detail/ins__functions.h"
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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gnss
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gnss
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_gnss
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _Ins__ros_msg_type = gnss__msg__Ins;

static bool _Ins__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Ins__ros_msg_type * ros_message = static_cast<const _Ins__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: latitude
  {
    cdr << ros_message->latitude;
  }

  // Field name: longitude
  {
    cdr << ros_message->longitude;
  }

  // Field name: height
  {
    cdr << ros_message->height;
  }

  // Field name: undulation
  {
    cdr << ros_message->undulation;
  }

  // Field name: north_velocity
  {
    cdr << ros_message->north_velocity;
  }

  // Field name: east_velocity
  {
    cdr << ros_message->east_velocity;
  }

  // Field name: up_velocity
  {
    cdr << ros_message->up_velocity;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: azimuth
  {
    cdr << ros_message->azimuth;
  }

  // Field name: latitude_std
  {
    cdr << ros_message->latitude_std;
  }

  // Field name: longitude_std
  {
    cdr << ros_message->longitude_std;
  }

  // Field name: height_std
  {
    cdr << ros_message->height_std;
  }

  // Field name: north_velocity_std
  {
    cdr << ros_message->north_velocity_std;
  }

  // Field name: east_velocity_std
  {
    cdr << ros_message->east_velocity_std;
  }

  // Field name: up_velocity_std
  {
    cdr << ros_message->up_velocity_std;
  }

  // Field name: roll_std
  {
    cdr << ros_message->roll_std;
  }

  // Field name: pitch_std
  {
    cdr << ros_message->pitch_std;
  }

  // Field name: azimuth_std
  {
    cdr << ros_message->azimuth_std;
  }

  return true;
}

static bool _Ins__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Ins__ros_msg_type * ros_message = static_cast<_Ins__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: latitude
  {
    cdr >> ros_message->latitude;
  }

  // Field name: longitude
  {
    cdr >> ros_message->longitude;
  }

  // Field name: height
  {
    cdr >> ros_message->height;
  }

  // Field name: undulation
  {
    cdr >> ros_message->undulation;
  }

  // Field name: north_velocity
  {
    cdr >> ros_message->north_velocity;
  }

  // Field name: east_velocity
  {
    cdr >> ros_message->east_velocity;
  }

  // Field name: up_velocity
  {
    cdr >> ros_message->up_velocity;
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: azimuth
  {
    cdr >> ros_message->azimuth;
  }

  // Field name: latitude_std
  {
    cdr >> ros_message->latitude_std;
  }

  // Field name: longitude_std
  {
    cdr >> ros_message->longitude_std;
  }

  // Field name: height_std
  {
    cdr >> ros_message->height_std;
  }

  // Field name: north_velocity_std
  {
    cdr >> ros_message->north_velocity_std;
  }

  // Field name: east_velocity_std
  {
    cdr >> ros_message->east_velocity_std;
  }

  // Field name: up_velocity_std
  {
    cdr >> ros_message->up_velocity_std;
  }

  // Field name: roll_std
  {
    cdr >> ros_message->roll_std;
  }

  // Field name: pitch_std
  {
    cdr >> ros_message->pitch_std;
  }

  // Field name: azimuth_std
  {
    cdr >> ros_message->azimuth_std;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gnss
size_t get_serialized_size_gnss__msg__Ins(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Ins__ros_msg_type * ros_message = static_cast<const _Ins__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name latitude
  {
    size_t item_size = sizeof(ros_message->latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name longitude
  {
    size_t item_size = sizeof(ros_message->longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name height
  {
    size_t item_size = sizeof(ros_message->height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name undulation
  {
    size_t item_size = sizeof(ros_message->undulation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name north_velocity
  {
    size_t item_size = sizeof(ros_message->north_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name east_velocity
  {
    size_t item_size = sizeof(ros_message->east_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name up_velocity
  {
    size_t item_size = sizeof(ros_message->up_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name azimuth
  {
    size_t item_size = sizeof(ros_message->azimuth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name latitude_std
  {
    size_t item_size = sizeof(ros_message->latitude_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name longitude_std
  {
    size_t item_size = sizeof(ros_message->longitude_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name height_std
  {
    size_t item_size = sizeof(ros_message->height_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name north_velocity_std
  {
    size_t item_size = sizeof(ros_message->north_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name east_velocity_std
  {
    size_t item_size = sizeof(ros_message->east_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name up_velocity_std
  {
    size_t item_size = sizeof(ros_message->up_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll_std
  {
    size_t item_size = sizeof(ros_message->roll_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_std
  {
    size_t item_size = sizeof(ros_message->pitch_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name azimuth_std
  {
    size_t item_size = sizeof(ros_message->azimuth_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Ins__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_gnss__msg__Ins(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_gnss
size_t max_serialized_size_gnss__msg__Ins(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: undulation
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: north_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: east_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: up_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: roll
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pitch
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: azimuth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: latitude_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: longitude_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: height_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: north_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: east_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: up_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: roll_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: azimuth_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Ins__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_gnss__msg__Ins(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Ins = {
  "gnss::msg",
  "Ins",
  _Ins__cdr_serialize,
  _Ins__cdr_deserialize,
  _Ins__get_serialized_size,
  _Ins__max_serialized_size
};

static rosidl_message_type_support_t _Ins__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Ins,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, gnss, msg, Ins)() {
  return &_Ins__type_support;
}

#if defined(__cplusplus)
}
#endif
