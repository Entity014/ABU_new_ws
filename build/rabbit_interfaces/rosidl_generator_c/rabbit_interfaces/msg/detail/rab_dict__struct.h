// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_H_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'key_axes'
// Member 'key_buttons'
#include "rosidl_runtime_c/string.h"
// Member 'value_axes'
// Member 'value_buttons'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/RabDict in the package rabbit_interfaces.
typedef struct rabbit_interfaces__msg__RabDict
{
  bool connection;
  rosidl_runtime_c__String__Sequence key_axes;
  rosidl_runtime_c__String__Sequence key_buttons;
  rosidl_runtime_c__float__Sequence value_axes;
  rosidl_runtime_c__int32__Sequence value_buttons;
} rabbit_interfaces__msg__RabDict;

// Struct for a sequence of rabbit_interfaces__msg__RabDict.
typedef struct rabbit_interfaces__msg__RabDict__Sequence
{
  rabbit_interfaces__msg__RabDict * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rabbit_interfaces__msg__RabDict__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_DICT__STRUCT_H_
