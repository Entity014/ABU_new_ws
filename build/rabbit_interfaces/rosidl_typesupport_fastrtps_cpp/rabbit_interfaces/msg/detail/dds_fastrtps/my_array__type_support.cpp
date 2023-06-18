// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/my_array__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rabbit_interfaces/msg/detail/my_array__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rabbit_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
cdr_serialize(
  const rabbit_interfaces::msg::MyArray & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: key
  {
    cdr << ros_message.key;
  }
  // Member: value
  {
    cdr << ros_message.value;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rabbit_interfaces::msg::MyArray & ros_message)
{
  // Member: key
  {
    cdr >> ros_message.key;
  }

  // Member: value
  {
    cdr >> ros_message.value;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
get_serialized_size(
  const rabbit_interfaces::msg::MyArray & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: key
  {
    size_t array_size = ros_message.key.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.key[index].size() + 1);
    }
  }
  // Member: value
  {
    size_t array_size = ros_message.value.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.value[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
max_serialized_size_MyArray(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: key
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: value
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MyArray__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rabbit_interfaces::msg::MyArray *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyArray__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rabbit_interfaces::msg::MyArray *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyArray__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rabbit_interfaces::msg::MyArray *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyArray__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MyArray(full_bounded, 0);
}

static message_type_support_callbacks_t _MyArray__callbacks = {
  "rabbit_interfaces::msg",
  "MyArray",
  _MyArray__cdr_serialize,
  _MyArray__cdr_deserialize,
  _MyArray__get_serialized_size,
  _MyArray__max_serialized_size
};

static rosidl_message_type_support_t _MyArray__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyArray__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rabbit_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rabbit_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rabbit_interfaces::msg::MyArray>()
{
  return &rabbit_interfaces::msg::typesupport_fastrtps_cpp::_MyArray__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rabbit_interfaces, msg, MyArray)() {
  return &rabbit_interfaces::msg::typesupport_fastrtps_cpp::_MyArray__handle;
}

#ifdef __cplusplus
}
#endif
