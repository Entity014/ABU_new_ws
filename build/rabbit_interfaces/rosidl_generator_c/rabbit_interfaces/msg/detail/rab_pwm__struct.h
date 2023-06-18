// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_H_
#define RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pwm_state'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/RabPwm in the package rabbit_interfaces.
typedef struct rabbit_interfaces__msg__RabPwm
{
  bool shoot;
  int32_t state;
  float pwm_current;
  rosidl_runtime_c__float__Sequence pwm_state;
} rabbit_interfaces__msg__RabPwm;

// Struct for a sequence of rabbit_interfaces__msg__RabPwm.
typedef struct rabbit_interfaces__msg__RabPwm__Sequence
{
  rabbit_interfaces__msg__RabPwm * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rabbit_interfaces__msg__RabPwm__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RABBIT_INTERFACES__MSG__DETAIL__RAB_PWM__STRUCT_H_
