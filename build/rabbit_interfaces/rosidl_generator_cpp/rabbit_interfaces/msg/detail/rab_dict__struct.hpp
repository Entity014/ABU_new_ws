// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__rabbit_interfaces__msg__RabDict __attribute__((deprecated))
#else
# define DEPRECATED__rabbit_interfaces__msg__RabDict __declspec(deprecated)
#endif

namespace rabbit_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RabDict_
{
  using Type = RabDict_<ContainerAllocator>;

  explicit RabDict_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connection = false;
    }
  }

  explicit RabDict_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connection = false;
    }
  }

  // field types and members
  using _connection_type =
    bool;
  _connection_type connection;
  using _key_axes_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _key_axes_type key_axes;
  using _key_buttons_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _key_buttons_type key_buttons;
  using _value_axes_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _value_axes_type value_axes;
  using _value_buttons_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _value_buttons_type value_buttons;

  // setters for named parameter idiom
  Type & set__connection(
    const bool & _arg)
  {
    this->connection = _arg;
    return *this;
  }
  Type & set__key_axes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->key_axes = _arg;
    return *this;
  }
  Type & set__key_buttons(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->key_buttons = _arg;
    return *this;
  }
  Type & set__value_axes(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->value_axes = _arg;
    return *this;
  }
  Type & set__value_buttons(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->value_buttons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rabbit_interfaces::msg::RabDict_<ContainerAllocator> *;
  using ConstRawPtr =
    const rabbit_interfaces::msg::RabDict_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rabbit_interfaces::msg::RabDict_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rabbit_interfaces::msg::RabDict_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rabbit_interfaces__msg__RabDict
    std::shared_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rabbit_interfaces__msg__RabDict
    std::shared_ptr<rabbit_interfaces::msg::RabDict_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RabDict_ & other) const
  {
    if (this->connection != other.connection) {
      return false;
    }
    if (this->key_axes != other.key_axes) {
      return false;
    }
    if (this->key_buttons != other.key_buttons) {
      return false;
    }
    if (this->value_axes != other.value_axes) {
      return false;
    }
    if (this->value_buttons != other.value_buttons) {
      return false;
    }
    return true;
  }
  bool operator!=(const RabDict_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RabDict_

// alias to use template instance with default allocator
using RabDict =
  rabbit_interfaces::msg::RabDict_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rabbit_interfaces

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_HPP_
