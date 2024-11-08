// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gnss/msg/detail/message__rosidl_typesupport_introspection_c.h"
#include "gnss/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gnss/msg/detail/message__functions.h"
#include "gnss/msg/detail/message__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `array`
#include "std_msgs/msg/float64_multi_array.h"
// Member `array`
#include "std_msgs/msg/detail/float64_multi_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Message__rosidl_typesupport_introspection_c__Message_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gnss__msg__Message__init(message_memory);
}

void Message__rosidl_typesupport_introspection_c__Message_fini_function(void * message_memory)
{
  gnss__msg__Message__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Message__rosidl_typesupport_introspection_c__Message_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gnss__msg__Message, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gnss__msg__Message, array),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Message__rosidl_typesupport_introspection_c__Message_message_members = {
  "gnss__msg",  // message namespace
  "Message",  // message name
  2,  // number of fields
  sizeof(gnss__msg__Message),
  Message__rosidl_typesupport_introspection_c__Message_message_member_array,  // message members
  Message__rosidl_typesupport_introspection_c__Message_init_function,  // function to initialize message memory (memory has to be allocated)
  Message__rosidl_typesupport_introspection_c__Message_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Message__rosidl_typesupport_introspection_c__Message_message_type_support_handle = {
  0,
  &Message__rosidl_typesupport_introspection_c__Message_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gnss
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gnss, msg, Message)() {
  Message__rosidl_typesupport_introspection_c__Message_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  Message__rosidl_typesupport_introspection_c__Message_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float64MultiArray)();
  if (!Message__rosidl_typesupport_introspection_c__Message_message_type_support_handle.typesupport_identifier) {
    Message__rosidl_typesupport_introspection_c__Message_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Message__rosidl_typesupport_introspection_c__Message_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
