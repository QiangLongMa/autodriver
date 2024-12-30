// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros2_path_interfaces/srv/detail/path_interfaces__rosidl_typesupport_introspection_c.h"
#include "ros2_path_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros2_path_interfaces/srv/detail/path_interfaces__functions.h"
#include "ros2_path_interfaces/srv/detail/path_interfaces__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_path_interfaces__srv__PathInterfaces_Request__init(message_memory);
}

void PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_fini_function(void * message_memory)
{
  ros2_path_interfaces__srv__PathInterfaces_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_member_array[1] = {
  {
    "global_request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_path_interfaces__srv__PathInterfaces_Request, global_request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_members = {
  "ros2_path_interfaces__srv",  // message namespace
  "PathInterfaces_Request",  // message name
  1,  // number of fields
  sizeof(ros2_path_interfaces__srv__PathInterfaces_Request),
  PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_member_array,  // message members
  PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_type_support_handle = {
  0,
  &PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_path_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Request)() {
  if (!PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_type_support_handle.typesupport_identifier) {
    PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PathInterfaces_Request__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros2_path_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__functions.h"
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros2_path_interfaces__srv__PathInterfaces_Response__init(message_memory);
}

void PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_fini_function(void * message_memory)
{
  ros2_path_interfaces__srv__PathInterfaces_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_member_array[2] = {
  {
    "local_response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_path_interfaces__srv__PathInterfaces_Response, local_response),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros2_path_interfaces__srv__PathInterfaces_Response, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_members = {
  "ros2_path_interfaces__srv",  // message namespace
  "PathInterfaces_Response",  // message name
  2,  // number of fields
  sizeof(ros2_path_interfaces__srv__PathInterfaces_Response),
  PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_member_array,  // message members
  PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_type_support_handle = {
  0,
  &PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_path_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Response)() {
  if (!PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_type_support_handle.typesupport_identifier) {
    PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PathInterfaces_Response__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros2_path_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ros2_path_interfaces/srv/detail/path_interfaces__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_members = {
  "ros2_path_interfaces__srv",  // service namespace
  "PathInterfaces",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_Request_message_type_support_handle,
  NULL  // response message
  // ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_Response_message_type_support_handle
};

static rosidl_service_type_support_t ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_type_support_handle = {
  0,
  &ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros2_path_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces)() {
  if (!ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_type_support_handle.typesupport_identifier) {
    ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros2_path_interfaces, srv, PathInterfaces_Response)()->data;
  }

  return &ros2_path_interfaces__srv__detail__path_interfaces__rosidl_typesupport_introspection_c__PathInterfaces_service_type_support_handle;
}
