// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__BUILDER_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__BUILDER_HPP_

#include "rabbit_interfaces/msg/detail/rab_dict__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rabbit_interfaces
{

namespace msg
{

namespace builder
{

class Init_RabDict_value_buttons
{
public:
  explicit Init_RabDict_value_buttons(::rabbit_interfaces::msg::RabDict & msg)
  : msg_(msg)
  {}
  ::rabbit_interfaces::msg::RabDict value_buttons(::rabbit_interfaces::msg::RabDict::_value_buttons_type arg)
  {
    msg_.value_buttons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabDict msg_;
};

class Init_RabDict_value_axes
{
public:
  explicit Init_RabDict_value_axes(::rabbit_interfaces::msg::RabDict & msg)
  : msg_(msg)
  {}
  Init_RabDict_value_buttons value_axes(::rabbit_interfaces::msg::RabDict::_value_axes_type arg)
  {
    msg_.value_axes = std::move(arg);
    return Init_RabDict_value_buttons(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabDict msg_;
};

class Init_RabDict_key_buttons
{
public:
  explicit Init_RabDict_key_buttons(::rabbit_interfaces::msg::RabDict & msg)
  : msg_(msg)
  {}
  Init_RabDict_value_axes key_buttons(::rabbit_interfaces::msg::RabDict::_key_buttons_type arg)
  {
    msg_.key_buttons = std::move(arg);
    return Init_RabDict_value_axes(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabDict msg_;
};

class Init_RabDict_key_axes
{
public:
  explicit Init_RabDict_key_axes(::rabbit_interfaces::msg::RabDict & msg)
  : msg_(msg)
  {}
  Init_RabDict_key_buttons key_axes(::rabbit_interfaces::msg::RabDict::_key_axes_type arg)
  {
    msg_.key_axes = std::move(arg);
    return Init_RabDict_key_buttons(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabDict msg_;
};

class Init_RabDict_connection
{
public:
  Init_RabDict_connection()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RabDict_key_axes connection(::rabbit_interfaces::msg::RabDict::_connection_type arg)
  {
    msg_.connection = std::move(arg);
    return Init_RabDict_key_axes(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabDict msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rabbit_interfaces::msg::RabDict>()
{
  return rabbit_interfaces::msg::builder::Init_RabDict_connection();
}

}  // namespace rabbit_interfaces

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__BUILDER_HPP_
