// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__STRUCT_H_
#define RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'key'
#include "rosidl_runtime_c/string.h"
// Member 'value'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/MyArray in the package rabbit_interfaces.
typedef struct rabbit_interfaces__msg__MyArray
{
  rosidl_runtime_c__String__Sequence key;
  rosidl_runtime_c__int64__Sequence value;
} rabbit_interfaces__msg__MyArray;

// Struct for a sequence of rabbit_interfaces__msg__MyArray.
typedef struct rabbit_interfaces__msg__MyArray__Sequence
{
  rabbit_interfaces__msg__MyArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rabbit_interfaces__msg__MyArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__STRUCT_H_
