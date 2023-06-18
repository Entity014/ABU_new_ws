// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__BUILDER_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__BUILDER_HPP_

#include "rabbit_interfaces/msg/detail/my_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rabbit_interfaces
{

namespace msg
{

namespace builder
{

class Init_MyArray_value
{
public:
  explicit Init_MyArray_value(::rabbit_interfaces::msg::MyArray & msg)
  : msg_(msg)
  {}
  ::rabbit_interfaces::msg::MyArray value(::rabbit_interfaces::msg::MyArray::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rabbit_interfaces::msg::MyArray msg_;
};

class Init_MyArray_key
{
public:
  Init_MyArray_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyArray_value key(::rabbit_interfaces::msg::MyArray::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_MyArray_value(msg_);
  }

private:
  ::rabbit_interfaces::msg::MyArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rabbit_interfaces::msg::MyArray>()
{
  return rabbit_interfaces::msg::builder::Init_MyArray_key();
}

}  // namespace rabbit_interfaces

#endif  // RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__BUILDER_HPP_
