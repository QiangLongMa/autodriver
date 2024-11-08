// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__MESSAGE__TRAITS_HPP_
#define GNSS__MSG__DETAIL__MESSAGE__TRAITS_HPP_

#include "gnss/msg/detail/message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'array'
#include "std_msgs/msg/detail/float64_multi_array__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gnss::msg::Message>()
{
  return "gnss::msg::Message";
}

template<>
inline const char * name<gnss::msg::Message>()
{
  return "gnss/msg/Message";
}

template<>
struct has_fixed_size<gnss::msg::Message>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Float64MultiArray>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<gnss::msg::Message>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Float64MultiArray>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<gnss::msg::Message>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GNSS__MSG__DETAIL__MESSAGE__TRAITS_HPP_
