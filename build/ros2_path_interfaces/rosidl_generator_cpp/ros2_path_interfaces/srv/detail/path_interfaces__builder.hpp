// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__BUILDER_HPP_
#define ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__BUILDER_HPP_

#include "ros2_path_interfaces/srv/detail/path_interfaces__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace ros2_path_interfaces
{

namespace srv
{

namespace builder
{

class Init_PathInterfaces_Request_global_request
{
public:
  Init_PathInterfaces_Request_global_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros2_path_interfaces::srv::PathInterfaces_Request global_request(::ros2_path_interfaces::srv::PathInterfaces_Request::_global_request_type arg)
  {
    msg_.global_request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_path_interfaces::srv::PathInterfaces_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_path_interfaces::srv::PathInterfaces_Request>()
{
  return ros2_path_interfaces::srv::builder::Init_PathInterfaces_Request_global_request();
}

}  // namespace ros2_path_interfaces


namespace ros2_path_interfaces
{

namespace srv
{

namespace builder
{

class Init_PathInterfaces_Response_data
{
public:
  explicit Init_PathInterfaces_Response_data(::ros2_path_interfaces::srv::PathInterfaces_Response & msg)
  : msg_(msg)
  {}
  ::ros2_path_interfaces::srv::PathInterfaces_Response data(::ros2_path_interfaces::srv::PathInterfaces_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_path_interfaces::srv::PathInterfaces_Response msg_;
};

class Init_PathInterfaces_Response_local_response
{
public:
  Init_PathInterfaces_Response_local_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathInterfaces_Response_data local_response(::ros2_path_interfaces::srv::PathInterfaces_Response::_local_response_type arg)
  {
    msg_.local_response = std::move(arg);
    return Init_PathInterfaces_Response_data(msg_);
  }

private:
  ::ros2_path_interfaces::srv::PathInterfaces_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_path_interfaces::srv::PathInterfaces_Response>()
{
  return ros2_path_interfaces::srv::builder::Init_PathInterfaces_Response_local_response();
}

}  // namespace ros2_path_interfaces

#endif  // ROS2_PATH_INTERFACES__SRV__DETAIL__PATH_INTERFACES__BUILDER_HPP_
