// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rabbit_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rabbit_interfaces/msg/detail/rab_dict__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rabbit_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
cdr_serialize(
  const rabbit_interfaces::msg::RabDict & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rabbit_interfaces::msg::RabDict & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
get_serialized_size(
  const rabbit_interfaces::msg::RabDict & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
max_serialized_size_RabDict(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rabbit_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rabbit_interfaces, msg, RabDict)();

#ifdef __cplusplus
}
#endif

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
