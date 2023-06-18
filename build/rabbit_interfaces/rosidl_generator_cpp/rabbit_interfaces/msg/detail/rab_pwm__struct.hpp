// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rabbit_interfaces__msg__RabPwm __attribute__((deprecated))
#else
# define DEPRECATED__rabbit_interfaces__msg__RabPwm __declspec(deprecated)
#endif

namespace rabbit_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RabPwm_
{
  using Type = RabPwm_<ContainerAllocator>;

  explicit RabPwm_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoot = false;
      this->state = 0l;
      this->pwm_current = 0.0f;
    }
  }

  explicit RabPwm_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shoot = false;
      this->state = 0l;
      this->pwm_current = 0.0f;
    }
  }

  // field types and members
  using _shoot_type =
    bool;
  _shoot_type shoot;
  using _state_type =
    int32_t;
  _state_type state;
  using _pwm_current_type =
    float;
  _pwm_current_type pwm_current;
  using _pwm_state_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _pwm_state_type pwm_state;

  // setters for named parameter idiom
  Type & set__shoot(
    const bool & _arg)
  {
    this->shoot = _arg;
    return *this;
  }
  Type & set__state(
    const int32_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__pwm_current(
    const float & _arg)
  {
    this->pwm_current = _arg;
    return *this;
  }
  Type & set__pwm_state(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->pwm_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rabbit_interfaces::msg::RabPwm_<ContainerAllocator> *;
  using ConstRawPtr =
    const rabbit_interfaces::msg::RabPwm_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rabbit_interfaces::msg::RabPwm_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rabbit_interfaces::msg::RabPwm_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rabbit_interfaces__msg__RabPwm
    std::shared_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rabbit_interfaces__msg__RabPwm
    std::shared_ptr<rabbit_interfaces::msg::RabPwm_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RabPwm_ & other) const
  {
    if (this->shoot != other.shoot) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->pwm_current != other.pwm_current) {
      return false;
    }
    if (this->pwm_state != other.pwm_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const RabPwm_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RabPwm_

// alias to use template instance with default allocator
using RabPwm =
  rabbit_interfaces::msg::RabPwm_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rabbit_interfaces

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_HPP_
