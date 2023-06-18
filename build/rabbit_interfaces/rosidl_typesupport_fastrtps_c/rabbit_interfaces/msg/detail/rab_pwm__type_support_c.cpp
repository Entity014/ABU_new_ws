// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/rab_pwm__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rabbit_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rabbit_interfaces/msg/detail/rab_pwm__struct.h"
#include "rabbit_interfaces/msg/detail/rab_pwm__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // pwm_state
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // pwm_state

// forward declare type support functions


using _RabPwm__ros_msg_type = rabbit_interfaces__msg__RabPwm;

static bool _RabPwm__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RabPwm__ros_msg_type * ros_message = static_cast<const _RabPwm__ros_msg_type *>(untyped_ros_message);
  // Field name: shoot
  {
    cdr << (ros_message->shoot ? true : false);
  }

  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: pwm_current
  {
    cdr << ros_message->pwm_current;
  }

  // Field name: pwm_state
  {
    size_t size = ros_message->pwm_state.size;
    auto array_ptr = ros_message->pwm_state.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _RabPwm__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RabPwm__ros_msg_type * ros_message = static_cast<_RabPwm__ros_msg_type *>(untyped_ros_message);
  // Field name: shoot
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->shoot = tmp ? true : false;
  }

  // Field name: state
  {
    cdr >> ros_message->state;
  }

  // Field name: pwm_current
  {
    cdr >> ros_message->pwm_current;
  }

  // Field name: pwm_state
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->pwm_state.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->pwm_state);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->pwm_state, size)) {
      return "failed to create array for field 'pwm_state'";
    }
    auto array_ptr = ros_message->pwm_state.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rabbit_interfaces
size_t get_serialized_size_rabbit_interfaces__msg__RabPwm(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RabPwm__ros_msg_type * ros_message = static_cast<const _RabPwm__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name shoot
  {
    size_t item_size = sizeof(ros_message->shoot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pwm_current
  {
    size_t item_size = sizeof(ros_message->pwm_current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pwm_state
  {
    size_t array_size = ros_message->pwm_state.size;
    auto array_ptr = ros_message->pwm_state.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RabPwm__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rabbit_interfaces__msg__RabPwm(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rabbit_interfaces
size_t max_serialized_size_rabbit_interfaces__msg__RabPwm(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: shoot
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pwm_current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pwm_state
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

static size_t _RabPwm__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_rabbit_interfaces__msg__RabPwm(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RabPwm = {
  "rabbit_interfaces::msg",
  "RabPwm",
  _RabPwm__cdr_serialize,
  _RabPwm__cdr_deserialize,
  _RabPwm__get_serialized_size,
  _RabPwm__max_serialized_size
};

static rosidl_message_type_support_t _RabPwm__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RabPwm,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rabbit_interfaces, msg, RabPwm)() {
  return &_RabPwm__type_support;
}

#if defined(__cplusplus)
}
#endif
