// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rabbit_interfaces/msg/detail/my_array__struct.hpp"
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

void MyArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rabbit_interfaces::msg::MyArray(_init);
}

void MyArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rabbit_interfaces::msg::MyArray *>(message_memory);
  typed_message->~MyArray();
}

size_t size_function__MyArray__key(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyArray__key(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__MyArray__key(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__MyArray__key(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MyArray__value(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MyArray__value(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void * get_function__MyArray__value(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void resize_function__MyArray__value(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MyArray_message_member_array[2] = {
  {
    "key",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::MyArray, key),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyArray__key,  // size() function pointer
    get_const_function__MyArray__key,  // get_const(index) function pointer
    get_function__MyArray__key,  // get(index) function pointer
    resize_function__MyArray__key  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces::msg::MyArray, value),  // bytes offset in struct
    nullptr,  // default value
    size_function__MyArray__value,  // size() function pointer
    get_const_function__MyArray__value,  // get_const(index) function pointer
    get_function__MyArray__value,  // get(index) function pointer
    resize_function__MyArray__value  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MyArray_message_members = {
  "rabbit_interfaces::msg",  // message namespace
  "MyArray",  // message name
  2,  // number of fields
  sizeof(rabbit_interfaces::msg::MyArray),
  MyArray_message_member_array,  // message members
  MyArray_init_function,  // function to initialize message memory (memory has to be allocated)
  MyArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MyArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MyArray_message_members,
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
get_message_type_support_handle<rabbit_interfaces::msg::MyArray>()
{
  return &::rabbit_interfaces::msg::rosidl_typesupport_introspection_cpp::MyArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rabbit_interfaces, msg, MyArray)() {
  return &::rabbit_interfaces::msg::rosidl_typesupport_introspection_cpp::MyArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
