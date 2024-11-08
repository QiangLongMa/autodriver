// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__MESSAGE__STRUCT_HPP_
#define GNSS__MSG__DETAIL__MESSAGE__STRUCT_HPP_

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
// Member 'array'
#include "std_msgs/msg/detail/float64_multi_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gnss__msg__Message __attribute__((deprecated))
#else
# define DEPRECATED__gnss__msg__Message __declspec(deprecated)
#endif

namespace gnss
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Message_
{
  using Type = Message_<ContainerAllocator>;

  explicit Message_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    array(_init)
  {
    (void)_init;
  }

  explicit Message_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    array(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _array_type =
    std_msgs::msg::Float64MultiArray_<ContainerAllocator>;
  _array_type array;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__array(
    const std_msgs::msg::Float64MultiArray_<ContainerAllocator> & _arg)
  {
    this->array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gnss::msg::Message_<ContainerAllocator> *;
  using ConstRawPtr =
    const gnss::msg::Message_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gnss::msg::Message_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gnss::msg::Message_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Message_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Message_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gnss::msg::Message_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gnss::msg::Message_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gnss::msg::Message_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gnss::msg::Message_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gnss__msg__Message
    std::shared_ptr<gnss::msg::Message_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gnss__msg__Message
    std::shared_ptr<gnss::msg::Message_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Message_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->array != other.array) {
      return false;
    }
    return true;
  }
  bool operator!=(const Message_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Message_

// alias to use template instance with default allocator
using Message =
  gnss::msg::Message_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gnss

#endif  // GNSS__MSG__DETAIL__MESSAGE__STRUCT_HPP_
