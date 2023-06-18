// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__TRAITS_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__TRAITS_HPP_

#include "rabbit_interfaces/msg/detail/rab_pwm__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rabbit_interfaces::msg::RabPwm>()
{
  return "rabbit_interfaces::msg::RabPwm";
}

template<>
inline const char * name<rabbit_interfaces::msg::RabPwm>()
{
  return "rabbit_interfaces/msg/RabPwm";
}

template<>
struct has_fixed_size<rabbit_interfaces::msg::RabPwm>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rabbit_interfaces::msg::RabPwm>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rabbit_interfaces::msg::RabPwm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__TRAITS_HPP_
