// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gnss:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__IMU__STRUCT_HPP_
#define GNSS__MSG__DETAIL__IMU__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gnss__msg__Imu __attribute__((deprecated))
#else
# define DEPRECATED__gnss__msg__Imu __declspec(deprecated)
#endif

namespace gnss
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Imu_
{
  using Type = Imu_<ContainerAllocator>;

  explicit Imu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_linear_acceleration = 0.0;
      this->y_linear_acceleration = 0.0;
      this->z_linear_acceleration = 0.0;
      this->x_angular_velocity = 0.0;
      this->y_angular_velocity = 0.0;
      this->z_angular_velocity = 0.0;
    }
  }

  explicit Imu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_linear_acceleration = 0.0;
      this->y_linear_acceleration = 0.0;
      this->z_linear_acceleration = 0.0;
      this->x_angular_velocity = 0.0;
      this->y_angular_velocity = 0.0;
      this->z_angular_velocity = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _x_linear_acceleration_type =
    double;
  _x_linear_acceleration_type x_linear_acceleration;
  using _y_linear_acceleration_type =
    double;
  _y_linear_acceleration_type y_linear_acceleration;
  using _z_linear_acceleration_type =
    double;
  _z_linear_acceleration_type z_linear_acceleration;
  using _x_angular_velocity_type =
    double;
  _x_angular_velocity_type x_angular_velocity;
  using _y_angular_velocity_type =
    double;
  _y_angular_velocity_type y_angular_velocity;
  using _z_angular_velocity_type =
    double;
  _z_angular_velocity_type z_angular_velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__x_linear_acceleration(
    const double & _arg)
  {
    this->x_linear_acceleration = _arg;
    return *this;
  }
  Type & set__y_linear_acceleration(
    const double & _arg)
  {
    this->y_linear_acceleration = _arg;
    return *this;
  }
  Type & set__z_linear_acceleration(
    const double & _arg)
  {
    this->z_linear_acceleration = _arg;
    return *this;
  }
  Type & set__x_angular_velocity(
    const double & _arg)
  {
    this->x_angular_velocity = _arg;
    return *this;
  }
  Type & set__y_angular_velocity(
    const double & _arg)
  {
    this->y_angular_velocity = _arg;
    return *this;
  }
  Type & set__z_angular_velocity(
    const double & _arg)
  {
    this->z_angular_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gnss::msg::Imu_<ContainerAllocator> *;
  using ConstRawPtr =
    const gnss::msg::Imu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gnss::msg::Imu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gnss::msg::Imu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Imu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Imu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Imu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Imu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gnss::msg::Imu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gnss::msg::Imu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gnss__msg__Imu
    std::shared_ptr<gnss::msg::Imu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gnss__msg__Imu
    std::shared_ptr<gnss::msg::Imu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Imu_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->x_linear_acceleration != other.x_linear_acceleration) {
      return false;
    }
    if (this->y_linear_acceleration != other.y_linear_acceleration) {
      return false;
    }
    if (this->z_linear_acceleration != other.z_linear_acceleration) {
      return false;
    }
    if (this->x_angular_velocity != other.x_angular_velocity) {
      return false;
    }
    if (this->y_angular_velocity != other.y_angular_velocity) {
      return false;
    }
    if (this->z_angular_velocity != other.z_angular_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const Imu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Imu_

// alias to use template instance with default allocator
using Imu =
  gnss::msg::Imu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__IMU__STRUCT_HPP_
