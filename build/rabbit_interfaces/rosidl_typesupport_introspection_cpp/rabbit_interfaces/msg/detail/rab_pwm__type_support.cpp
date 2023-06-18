// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rabbit_interfaces/msg/detail/rab_pwm__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rabbit_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RabPwm_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rabbit_interfaces::msg::RabPwm(_init);
}

void RabPwm_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rabbit_interfaces::msg::RabPwm *>(message_memory);
  typed_message->~RabPwm();
}

size_t size_function__RabPwm__pwm_state(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RabPwm__pwm_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__RabPwm__pwm_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__RabPwm__pwm_state(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RabPwm_message_member_array[4] = {
  {
    "shoot",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::RabPwm, shoot),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::RabPwm, state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pwm_current",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::RabPwm, pwm_current),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pwm_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::RabPwm, pwm_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__RabPwm__pwm_state,  // size() function pointer
    get_const_function__RabPwm__pwm_state,  // get_const(index) function pointer
    get_function__RabPwm__pwm_state,  // get(index) function pointer
    resize_function__RabPwm__pwm_state  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RabPwm_message_members = {
  "rabbit_interfaces::msg",  // message namespace
  "RabPwm",  // message name
  4,  // number of fields
  sizeof(rabbit_interfaces::msg::RabPwm),
  RabPwm_message_member_array,  // message members
  RabPwm_init_function,  // function to initialize message memory (memory has to be allocated)
  RabPwm_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RabPwm_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RabPwm_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rabbit_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rabbit_interfaces::msg::RabPwm>()
{
  return &::rabbit_interfaces::msg::rosidl_typesupport_introspection_cpp::RabPwm_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rabbit_interfaces, msg, RabPwm)() {
  return &::rabbit_interfaces::msg::rosidl_typesupport_introspection_cpp::RabPwm_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
