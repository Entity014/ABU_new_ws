// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__BUILDER_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__BUILDER_HPP_

#include "rabbit_interfaces/msg/detail/rab_pwm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace rabbit_interfaces
{

namespace msg
{

namespace builder
{

class Init_RabPwm_pwm_state
{
public:
  explicit Init_RabPwm_pwm_state(::rabbit_interfaces::msg::RabPwm & msg)
  : msg_(msg)
  {}
  ::rabbit_interfaces::msg::RabPwm pwm_state(::rabbit_interfaces::msg::RabPwm::_pwm_state_type arg)
  {
    msg_.pwm_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabPwm msg_;
};

class Init_RabPwm_pwm_current
{
public:
  explicit Init_RabPwm_pwm_current(::rabbit_interfaces::msg::RabPwm & msg)
  : msg_(msg)
  {}
  Init_RabPwm_pwm_state pwm_current(::rabbit_interfaces::msg::RabPwm::_pwm_current_type arg)
  {
    msg_.pwm_current = std::move(arg);
    return Init_RabPwm_pwm_state(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabPwm msg_;
};

class Init_RabPwm_state
{
public:
  explicit Init_RabPwm_state(::rabbit_interfaces::msg::RabPwm & msg)
  : msg_(msg)
  {}
  Init_RabPwm_pwm_current state(::rabbit_interfaces::msg::RabPwm::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_RabPwm_pwm_current(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabPwm msg_;
};

class Init_RabPwm_shoot
{
public:
  Init_RabPwm_shoot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RabPwm_state shoot(::rabbit_interfaces::msg::RabPwm::_shoot_type arg)
  {
    msg_.shoot = std::move(arg);
    return Init_RabPwm_state(msg_);
  }

private:
  ::rabbit_interfaces::msg::RabPwm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rabbit_interfaces::msg::RabPwm>()
{
  return rabbit_interfaces::msg::builder::Init_RabPwm_shoot();
}

}  // namespace rabbit_interfaces

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__BUILDER_HPP_
