// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_HPP_
#define ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Request __declspec(deprecated)
#endif

namespace ros2_path_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathInterfaces_Request_
{
  using Type = PathInterfaces_Request_<ContainerAllocator>;

  explicit PathInterfaces_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->global_request = 0l;
    }
  }

  explicit PathInterfaces_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->global_request = 0l;
    }
  }

  // field types and members
  using _global_request_type =
    int32_t;
  _global_request_type global_request;

  // setters for named parameter idiom
  Type & set__global_request(
    const int32_t & _arg)
  {
    this->global_request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Request
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Request
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathInterfaces_Request_ & other) const
  {
    if (this->global_request != other.global_request) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathInterfaces_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathInterfaces_Request_

// alias to use template instance with default allocator
using PathInterfaces_Request =
  ros2_path_interfaces::srv::PathInterfaces_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_path_interfaces


#ifndef _WIN32
# define DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Response __declspec(deprecated)
#endif

namespace ros2_path_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathInterfaces_Response_
{
  using Type = PathInterfaces_Response_<ContainerAllocator>;

  explicit PathInterfaces_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->local_response = 0l;
    }
  }

  explicit PathInterfaces_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->local_response = 0l;
    }
  }

  // field types and members
  using _local_response_type =
    int32_t;
  _local_response_type local_response;
  using _data_type =
    std::vector<double, typename ContainerAllocator::template rebind<double>::other>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__local_response(
    const int32_t & _arg)
  {
    this->local_response = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<double, typename ContainerAllocator::template rebind<double>::other> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Response
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_path_interfaces__srv__PathInterfaces_Response
    std::shared_ptr<ros2_path_interfaces::srv::PathInterfaces_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathInterfaces_Response_ & other) const
  {
    if (this->local_response != other.local_response) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathInterfaces_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathInterfaces_Response_

// alias to use template instance with default allocator
using PathInterfaces_Response =
  ros2_path_interfaces::srv::PathInterfaces_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_path_interfaces

namespace ros2_path_interfaces
{

namespace srv
{

struct PathInterfaces
{
  using Request = ros2_path_interfaces::srv::PathInterfaces_Request;
  using Response = ros2_path_interfaces::srv::PathInterfaces_Response;
};

}  // namespace srv

}  // namespace ros2_path_interfaces

#endif  // ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__STRUCT_HPP_
