// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__INS__BUILDER_HPP_
#define GNSS__MSG__DETAIL__INS__BUILDER_HPP_

#include "gnss/msg/detail/ins__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace gnss
{

namespace msg
{

namespace builder
{

class Init_Ins_azimuth_std
{
public:
  explicit Init_Ins_azimuth_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  ::gnss::msg::Ins azimuth_std(::gnss::msg::Ins::_azimuth_std_type arg)
  {
    msg_.azimuth_std = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_pitch_std
{
public:
  explicit Init_Ins_pitch_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_azimuth_std pitch_std(::gnss::msg::Ins::_pitch_std_type arg)
  {
    msg_.pitch_std = std::move(arg);
    return Init_Ins_azimuth_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_roll_std
{
public:
  explicit Init_Ins_roll_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_pitch_std roll_std(::gnss::msg::Ins::_roll_std_type arg)
  {
    msg_.roll_std = std::move(arg);
    return Init_Ins_pitch_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_up_velocity_std
{
public:
  explicit Init_Ins_up_velocity_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_roll_std up_velocity_std(::gnss::msg::Ins::_up_velocity_std_type arg)
  {
    msg_.up_velocity_std = std::move(arg);
    return Init_Ins_roll_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_east_velocity_std
{
public:
  explicit Init_Ins_east_velocity_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_up_velocity_std east_velocity_std(::gnss::msg::Ins::_east_velocity_std_type arg)
  {
    msg_.east_velocity_std = std::move(arg);
    return Init_Ins_up_velocity_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_north_velocity_std
{
public:
  explicit Init_Ins_north_velocity_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_east_velocity_std north_velocity_std(::gnss::msg::Ins::_north_velocity_std_type arg)
  {
    msg_.north_velocity_std = std::move(arg);
    return Init_Ins_east_velocity_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_height_std
{
public:
  explicit Init_Ins_height_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_north_velocity_std height_std(::gnss::msg::Ins::_height_std_type arg)
  {
    msg_.height_std = std::move(arg);
    return Init_Ins_north_velocity_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_longitude_std
{
public:
  explicit Init_Ins_longitude_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_height_std longitude_std(::gnss::msg::Ins::_longitude_std_type arg)
  {
    msg_.longitude_std = std::move(arg);
    return Init_Ins_height_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_latitude_std
{
public:
  explicit Init_Ins_latitude_std(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_longitude_std latitude_std(::gnss::msg::Ins::_latitude_std_type arg)
  {
    msg_.latitude_std = std::move(arg);
    return Init_Ins_longitude_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_azimuth
{
public:
  explicit Init_Ins_azimuth(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_latitude_std azimuth(::gnss::msg::Ins::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_Ins_latitude_std(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_pitch
{
public:
  explicit Init_Ins_pitch(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_azimuth pitch(::gnss::msg::Ins::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Ins_azimuth(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_roll
{
public:
  explicit Init_Ins_roll(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_pitch roll(::gnss::msg::Ins::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Ins_pitch(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_up_velocity
{
public:
  explicit Init_Ins_up_velocity(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_roll up_velocity(::gnss::msg::Ins::_up_velocity_type arg)
  {
    msg_.up_velocity = std::move(arg);
    return Init_Ins_roll(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_east_velocity
{
public:
  explicit Init_Ins_east_velocity(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_up_velocity east_velocity(::gnss::msg::Ins::_east_velocity_type arg)
  {
    msg_.east_velocity = std::move(arg);
    return Init_Ins_up_velocity(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_north_velocity
{
public:
  explicit Init_Ins_north_velocity(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_east_velocity north_velocity(::gnss::msg::Ins::_north_velocity_type arg)
  {
    msg_.north_velocity = std::move(arg);
    return Init_Ins_east_velocity(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_undulation
{
public:
  explicit Init_Ins_undulation(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_north_velocity undulation(::gnss::msg::Ins::_undulation_type arg)
  {
    msg_.undulation = std::move(arg);
    return Init_Ins_north_velocity(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_height
{
public:
  explicit Init_Ins_height(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_undulation height(::gnss::msg::Ins::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Ins_undulation(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_longitude
{
public:
  explicit Init_Ins_longitude(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_height longitude(::gnss::msg::Ins::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_Ins_height(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_latitude
{
public:
  explicit Init_Ins_latitude(::gnss::msg::Ins & msg)
  : msg_(msg)
  {}
  Init_Ins_longitude latitude(::gnss::msg::Ins::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_Ins_longitude(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

class Init_Ins_header
{
public:
  Init_Ins_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ins_latitude header(::gnss::msg::Ins::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ins_latitude(msg_);
  }

private:
  ::gnss::msg::Ins msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gnss::msg::Ins>()
{
  return gnss::msg::builder::Init_Ins_header();
}

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__INS__BUILDER_HPP_
