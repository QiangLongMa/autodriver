// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__MESSAGE__BUILDER_HPP_
#define GNSS__MSG__DETAIL__MESSAGE__BUILDER_HPP_

#include "gnss/msg/detail/message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace gnss
{

namespace msg
{

namespace builder
{

class Init_Message_array
{
public:
  explicit Init_Message_array(::gnss::msg::Message & msg)
  : msg_(msg)
  {}
  ::gnss::msg::Message array(::gnss::msg::Message::_array_type arg)
  {
    msg_.array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gnss::msg::Message msg_;
};

class Init_Message_header
{
public:
  Init_Message_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Message_array header(::gnss::msg::Message::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Message_array(msg_);
  }

private:
  ::gnss::msg::Message msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gnss::msg::Message>()
{
  return gnss::msg::builder::Init_Message_header();
}

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__MESSAGE__BUILDER_HPP_
