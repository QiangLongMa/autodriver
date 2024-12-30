// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gnss:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__IMU__BUILDER_HPP_
#define GNSS__MSG__DETAIL__IMU__BUILDER_HPP_

#include "gnss/msg/detail/imu__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace gnss
{

namespace msg
{

namespace builder
{

class Init_Imu_z_angular_velocity
{
public:
  explicit Init_Imu_z_angular_velocity(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  ::gnss::msg::Imu z_angular_velocity(::gnss::msg::Imu::_z_angular_velocity_type arg)
  {
    msg_.z_angular_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_y_angular_velocity
{
public:
  explicit Init_Imu_y_angular_velocity(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_z_angular_velocity y_angular_velocity(::gnss::msg::Imu::_y_angular_velocity_type arg)
  {
    msg_.y_angular_velocity = std::move(arg);
    return Init_Imu_z_angular_velocity(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_x_angular_velocity
{
public:
  explicit Init_Imu_x_angular_velocity(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_y_angular_velocity x_angular_velocity(::gnss::msg::Imu::_x_angular_velocity_type arg)
  {
    msg_.x_angular_velocity = std::move(arg);
    return Init_Imu_y_angular_velocity(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_z_linear_acceleration
{
public:
  explicit Init_Imu_z_linear_acceleration(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_x_angular_velocity z_linear_acceleration(::gnss::msg::Imu::_z_linear_acceleration_type arg)
  {
    msg_.z_linear_acceleration = std::move(arg);
    return Init_Imu_x_angular_velocity(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_y_linear_acceleration
{
public:
  explicit Init_Imu_y_linear_acceleration(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_z_linear_acceleration y_linear_acceleration(::gnss::msg::Imu::_y_linear_acceleration_type arg)
  {
    msg_.y_linear_acceleration = std::move(arg);
    return Init_Imu_z_linear_acceleration(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_x_linear_acceleration
{
public:
  explicit Init_Imu_x_linear_acceleration(::gnss::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_y_linear_acceleration x_linear_acceleration(::gnss::msg::Imu::_x_linear_acceleration_type arg)
  {
    msg_.x_linear_acceleration = std::move(arg);
    return Init_Imu_y_linear_acceleration(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

class Init_Imu_header
{
public:
  Init_Imu_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imu_x_linear_acceleration header(::gnss::msg::Imu::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Imu_x_linear_acceleration(msg_);
  }

private:
  ::gnss::msg::Imu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gnss::msg::Imu>()
{
  return gnss::msg::builder::Init_Imu_header();
}

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__IMU__BUILDER_HPP_
