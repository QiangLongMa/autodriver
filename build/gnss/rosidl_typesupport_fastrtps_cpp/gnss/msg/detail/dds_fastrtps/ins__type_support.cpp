// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice
#include "gnss/msg/detail/ins__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gnss/msg/detail/ins__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: latitude
  cdr << ros_message.latitude;
  // Member: longitude
  cdr << ros_message.longitude;
  // Member: height
  cdr << ros_message.height;
  // Member: undulation
  cdr << ros_message.undulation;
  // Member: north_velocity
  cdr << ros_message.north_velocity;
  // Member: east_velocity
  cdr << ros_message.east_velocity;
  // Member: up_velocity
  cdr << ros_message.up_velocity;
  // Member: roll
  cdr << ros_message.roll;
  // Member: pitch
  cdr << ros_message.pitch;
  // Member: azimuth
  cdr << ros_message.azimuth;
  // Member: latitude_std
  cdr << ros_message.latitude_std;
  // Member: longitude_std
  cdr << ros_message.longitude_std;
  // Member: height_std
  cdr << ros_message.height_std;
  // Member: north_velocity_std
  cdr << ros_message.north_velocity_std;
  // Member: east_velocity_std
  cdr << ros_message.east_velocity_std;
  // Member: up_velocity_std
  cdr << ros_message.up_velocity_std;
  // Member: roll_std
  cdr << ros_message.roll_std;
  // Member: pitch_std
  cdr << ros_message.pitch_std;
  // Member: azimuth_std
  cdr << ros_message.azimuth_std;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gnss::msg::Ins & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: latitude
  cdr >> ros_message.latitude;

  // Member: longitude
  cdr >> ros_message.longitude;

  // Member: height
  cdr >> ros_message.height;

  // Member: undulation
  cdr >> ros_message.undulation;

  // Member: north_velocity
  cdr >> ros_message.north_velocity;

  // Member: east_velocity
  cdr >> ros_message.east_velocity;

  // Member: up_velocity
  cdr >> ros_message.up_velocity;

  // Member: roll
  cdr >> ros_message.roll;

  // Member: pitch
  cdr >> ros_message.pitch;

  // Member: azimuth
  cdr >> ros_message.azimuth;

  // Member: latitude_std
  cdr >> ros_message.latitude_std;

  // Member: longitude_std
  cdr >> ros_message.longitude_std;

  // Member: height_std
  cdr >> ros_message.height_std;

  // Member: north_velocity_std
  cdr >> ros_message.north_velocity_std;

  // Member: east_velocity_std
  cdr >> ros_message.east_velocity_std;

  // Member: up_velocity_std
  cdr >> ros_message.up_velocity_std;

  // Member: roll_std
  cdr >> ros_message.roll_std;

  // Member: pitch_std
  cdr >> ros_message.pitch_std;

  // Member: azimuth_std
  cdr >> ros_message.azimuth_std;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
get_serialized_size(
  const gnss::msg::Ins & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: latitude
  {
    size_t item_size = sizeof(ros_message.latitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: longitude
  {
    size_t item_size = sizeof(ros_message.longitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: height
  {
    size_t item_size = sizeof(ros_message.height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: undulation
  {
    size_t item_size = sizeof(ros_message.undulation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: north_velocity
  {
    size_t item_size = sizeof(ros_message.north_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: east_velocity
  {
    size_t item_size = sizeof(ros_message.east_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: up_velocity
  {
    size_t item_size = sizeof(ros_message.up_velocity);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll
  {
    size_t item_size = sizeof(ros_message.roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch
  {
    size_t item_size = sizeof(ros_message.pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: azimuth
  {
    size_t item_size = sizeof(ros_message.azimuth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: latitude_std
  {
    size_t item_size = sizeof(ros_message.latitude_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: longitude_std
  {
    size_t item_size = sizeof(ros_message.longitude_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: height_std
  {
    size_t item_size = sizeof(ros_message.height_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: north_velocity_std
  {
    size_t item_size = sizeof(ros_message.north_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: east_velocity_std
  {
    size_t item_size = sizeof(ros_message.east_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: up_velocity_std
  {
    size_t item_size = sizeof(ros_message.up_velocity_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll_std
  {
    size_t item_size = sizeof(ros_message.roll_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pitch_std
  {
    size_t item_size = sizeof(ros_message.pitch_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: azimuth_std
  {
    size_t item_size = sizeof(ros_message.azimuth_std);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gnss
max_serialized_size_Ins(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: latitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: longitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: undulation
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: north_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: east_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: up_velocity
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: roll
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pitch
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: azimuth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: latitude_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: longitude_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: height_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: north_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: east_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: up_velocity_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: roll_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pitch_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: azimuth_std
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Ins__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gnss::msg::Ins *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Ins__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gnss::msg::Ins *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Ins__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gnss::msg::Ins *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Ins__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_Ins(full_bounded, 0);
}

static message_type_support_callbacks_t _Ins__callbacks = {
  "gnss::msg",
  "Ins",
  _Ins__cdr_serialize,
  _Ins__cdr_deserialize,
  _Ins__get_serialized_size,
  _Ins__max_serialized_size
};

static rosidl_message_type_support_t _Ins__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Ins__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gnss

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gnss
const rosidl_message_type_support_t *
get_message_type_support_handle<gnss::msg::Ins>()
{
  return &gnss::msg::typesupport_fastrtps_cpp::_Ins__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gnss, msg, Ins)() {
  return &gnss::msg::typesupport_fastrtps_cpp::_Ins__handle;
}

#ifdef __cplusplus
}
#endif
