// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/rab_dict__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rabbit_interfaces/msg/detail/rab_dict__struct.hpp"

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
  const rabbit_interfaces::msg::RabDict & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: connection
  cdr << (ros_message.connection ? true : false);
  // Member: key_axes
  {
    cdr << ros_message.key_axes;
  }
  // Member: key_buttons
  {
    cdr << ros_message.key_buttons;
  }
  // Member: value_axes
  {
    cdr << ros_message.value_axes;
  }
  // Member: value_buttons
  {
    cdr << ros_message.value_buttons;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rabbit_interfaces::msg::RabDict & ros_message)
{
  // Member: connection
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.connection = tmp ? true : false;
  }

  // Member: key_axes
  {
    cdr >> ros_message.key_axes;
  }

  // Member: key_buttons
  {
    cdr >> ros_message.key_buttons;
  }

  // Member: value_axes
  {
    cdr >> ros_message.value_axes;
  }

  // Member: value_buttons
  {
    cdr >> ros_message.value_buttons;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
get_serialized_size(
  const rabbit_interfaces::msg::RabDict & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: connection
  {
    size_t item_size = sizeof(ros_message.connection);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: key_axes
  {
    size_t array_size = ros_message.key_axes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.key_axes[index].size() + 1);
    }
  }
  // Member: key_buttons
  {
    size_t array_size = ros_message.key_buttons.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.key_buttons[index].size() + 1);
    }
  }
  // Member: value_axes
  {
    size_t array_size = ros_message.value_axes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.value_axes[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: value_buttons
  {
    size_t array_size = ros_message.value_buttons.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.value_buttons[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rabbit_interfaces
max_serialized_size_RabDict(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: connection
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: key_axes
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

  // Member: key_buttons
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

  // Member: value_axes
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: value_buttons
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RabDict__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rabbit_interfaces::msg::RabDict *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RabDict__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rabbit_interfaces::msg::RabDict *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RabDict__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rabbit_interfaces::msg::RabDict *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RabDict__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RabDict(full_bounded, 0);
}

static message_type_support_callbacks_t _RabDict__callbacks = {
  "rabbit_interfaces::msg",
  "RabDict",
  _RabDict__cdr_serialize,
  _RabDict__cdr_deserialize,
  _RabDict__get_serialized_size,
  _RabDict__max_serialized_size
};

static rosidl_message_type_support_t _RabDict__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RabDict__callbacks,
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
get_message_type_support_handle<rabbit_interfaces::msg::RabDict>()
{
  return &rabbit_interfaces::msg::typesupport_fastrtps_cpp::_RabDict__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rabbit_interfaces, msg, RabDict)() {
  return &rabbit_interfaces::msg::typesupport_fastrtps_cpp::_RabDict__handle;
}

#ifdef __cplusplus
}
#endif
