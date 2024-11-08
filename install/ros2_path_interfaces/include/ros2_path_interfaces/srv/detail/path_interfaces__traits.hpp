// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__TRAITS_HPP_
#define ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__TRAITS_HPP_

#include "ros2_path_interfaces/srv/detail/path_interfaces__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_path_interfaces::srv::PathInterfaces_Request>()
{
  return "ros2_path_interfaces::srv::PathInterfaces_Request";
}

template<>
inline const char * name<ros2_path_interfaces::srv::PathInterfaces_Request>()
{
  return "ros2_path_interfaces/srv/PathInterfaces_Request";
}

template<>
struct has_fixed_size<ros2_path_interfaces::srv::PathInterfaces_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_path_interfaces::srv::PathInterfaces_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_path_interfaces::srv::PathInterfaces_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_path_interfaces::srv::PathInterfaces_Response>()
{
  return "ros2_path_interfaces::srv::PathInterfaces_Response";
}

template<>
inline const char * name<ros2_path_interfaces::srv::PathInterfaces_Response>()
{
  return "ros2_path_interfaces/srv/PathInterfaces_Response";
}

template<>
struct has_fixed_size<ros2_path_interfaces::srv::PathInterfaces_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_path_interfaces::srv::PathInterfaces_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_path_interfaces::srv::PathInterfaces_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_path_interfaces::srv::PathInterfaces>()
{
  return "ros2_path_interfaces::srv::PathInterfaces";
}

template<>
inline const char * name<ros2_path_interfaces::srv::PathInterfaces>()
{
  return "ros2_path_interfaces/srv/PathInterfaces";
}

template<>
struct has_fixed_size<ros2_path_interfaces::srv::PathInterfaces>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_path_interfaces::srv::PathInterfaces_Request>::value &&
    has_fixed_size<ros2_path_interfaces::srv::PathInterfaces_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_path_interfaces::srv::PathInterfaces>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_path_interfaces::srv::PathInterfaces_Request>::value &&
    has_bounded_size<ros2_path_interfaces::srv::PathInterfaces_Response>::value
  >
{
};

template<>
struct is_service<ros2_path_interfaces::srv::PathInterfaces>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_path_interfaces::srv::PathInterfaces_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_path_interfaces::srv::PathInterfaces_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__TRAITS_HPP_
