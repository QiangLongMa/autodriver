// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__INS__STRUCT_HPP_
#define GNSS__MSG__DETAIL__INS__STRUCT_HPP_

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
# define DEPRECATED__gnss__msg__Ins __attribute__((deprecated))
#else
# define DEPRECATED__gnss__msg__Ins __declspec(deprecated)
#endif

namespace gnss
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Ins_
{
  using Type = Ins_<ContainerAllocator>;

  explicit Ins_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->height = 0.0;
      this->undulation = 0.0f;
      this->north_velocity = 0.0;
      this->east_velocity = 0.0;
      this->up_velocity = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->azimuth = 0.0;
      this->latitude_std = 0.0f;
      this->longitude_std = 0.0f;
      this->height_std = 0.0f;
      this->north_velocity_std = 0.0f;
      this->east_velocity_std = 0.0f;
      this->up_velocity_std = 0.0f;
      this->roll_std = 0.0f;
      this->pitch_std = 0.0f;
      this->azimuth_std = 0.0f;
    }
  }

  explicit Ins_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->height = 0.0;
      this->undulation = 0.0f;
      this->north_velocity = 0.0;
      this->east_velocity = 0.0;
      this->up_velocity = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->azimuth = 0.0;
      this->latitude_std = 0.0f;
      this->longitude_std = 0.0f;
      this->height_std = 0.0f;
      this->north_velocity_std = 0.0f;
      this->east_velocity_std = 0.0f;
      this->up_velocity_std = 0.0f;
      this->roll_std = 0.0f;
      this->pitch_std = 0.0f;
      this->azimuth_std = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _height_type =
    double;
  _height_type height;
  using _undulation_type =
    float;
  _undulation_type undulation;
  using _north_velocity_type =
    double;
  _north_velocity_type north_velocity;
  using _east_velocity_type =
    double;
  _east_velocity_type east_velocity;
  using _up_velocity_type =
    double;
  _up_velocity_type up_velocity;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _latitude_std_type =
    float;
  _latitude_std_type latitude_std;
  using _longitude_std_type =
    float;
  _longitude_std_type longitude_std;
  using _height_std_type =
    float;
  _height_std_type height_std;
  using _north_velocity_std_type =
    float;
  _north_velocity_std_type north_velocity_std;
  using _east_velocity_std_type =
    float;
  _east_velocity_std_type east_velocity_std;
  using _up_velocity_std_type =
    float;
  _up_velocity_std_type up_velocity_std;
  using _roll_std_type =
    float;
  _roll_std_type roll_std;
  using _pitch_std_type =
    float;
  _pitch_std_type pitch_std;
  using _azimuth_std_type =
    float;
  _azimuth_std_type azimuth_std;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__height(
    const double & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__undulation(
    const float & _arg)
  {
    this->undulation = _arg;
    return *this;
  }
  Type & set__north_velocity(
    const double & _arg)
  {
    this->north_velocity = _arg;
    return *this;
  }
  Type & set__east_velocity(
    const double & _arg)
  {
    this->east_velocity = _arg;
    return *this;
  }
  Type & set__up_velocity(
    const double & _arg)
  {
    this->up_velocity = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__latitude_std(
    const float & _arg)
  {
    this->latitude_std = _arg;
    return *this;
  }
  Type & set__longitude_std(
    const float & _arg)
  {
    this->longitude_std = _arg;
    return *this;
  }
  Type & set__height_std(
    const float & _arg)
  {
    this->height_std = _arg;
    return *this;
  }
  Type & set__north_velocity_std(
    const float & _arg)
  {
    this->north_velocity_std = _arg;
    return *this;
  }
  Type & set__east_velocity_std(
    const float & _arg)
  {
    this->east_velocity_std = _arg;
    return *this;
  }
  Type & set__up_velocity_std(
    const float & _arg)
  {
    this->up_velocity_std = _arg;
    return *this;
  }
  Type & set__roll_std(
    const float & _arg)
  {
    this->roll_std = _arg;
    return *this;
  }
  Type & set__pitch_std(
    const float & _arg)
  {
    this->pitch_std = _arg;
    return *this;
  }
  Type & set__azimuth_std(
    const float & _arg)
  {
    this->azimuth_std = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gnss::msg::Ins_<ContainerAllocator> *;
  using ConstRawPtr =
    const gnss::msg::Ins_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gnss::msg::Ins_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gnss::msg::Ins_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Ins_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Ins_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Ins_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Ins_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gnss::msg::Ins_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gnss::msg::Ins_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gnss__msg__Ins
    std::shared_ptr<gnss::msg::Ins_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gnss__msg__Ins
    std::shared_ptr<gnss::msg::Ins_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Ins_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->undulation != other.undulation) {
      return false;
    }
    if (this->north_velocity != other.north_velocity) {
      return false;
    }
    if (this->east_velocity != other.east_velocity) {
      return false;
    }
    if (this->up_velocity != other.up_velocity) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->latitude_std != other.latitude_std) {
      return false;
    }
    if (this->longitude_std != other.longitude_std) {
      return false;
    }
    if (this->height_std != other.height_std) {
      return false;
    }
    if (this->north_velocity_std != other.north_velocity_std) {
      return false;
    }
    if (this->east_velocity_std != other.east_velocity_std) {
      return false;
    }
    if (this->up_velocity_std != other.up_velocity_std) {
      return false;
    }
    if (this->roll_std != other.roll_std) {
      return false;
    }
    if (this->pitch_std != other.pitch_std) {
      return false;
    }
    if (this->azimuth_std != other.azimuth_std) {
      return false;
    }
    return true;
  }
  bool operator!=(const Ins_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Ins_

// alias to use template instance with default allocator
using Ins =
  gnss::msg::Ins_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__INS__STRUCT_HPP_
