// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rabbit_interfaces/msg/detail/rab_pwm__rosidl_typesupport_introspection_c.h"
#include "rabbit_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rabbit_interfaces/msg/detail/rab_pwm__functions.h"
#include "rabbit_interfaces/msg/detail/rab_pwm__struct.h"


// Include directives for member types
// Member `pwm_state`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RabPwm__rosidl_typesupport_introspection_c__RabPwm_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rabbit_interfaces__msg__RabPwm__init(message_memory);
}

void RabPwm__rosidl_typesupport_introspection_c__RabPwm_fini_function(void * message_memory)
{
  rabbit_interfaces__msg__RabPwm__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_member_array[4] = {
  {
    "shoot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces__msg__RabPwm, shoot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces__msg__RabPwm, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pwm_current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces__msg__RabPwm, pwm_current),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pwm_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rabbit_interfaces__msg__RabPwm, pwm_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_members = {
  "rabbit_interfaces__msg",  // message namespace
  "RabPwm",  // message name
  4,  // number of fields
  sizeof(rabbit_interfaces__msg__RabPwm),
  RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_member_array,  // message members
  RabPwm__rosidl_typesupport_introspection_c__RabPwm_init_function,  // function to initialize message memory (memory has to be allocated)
  RabPwm__rosidl_typesupport_introspection_c__RabPwm_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_type_support_handle = {
  0,
  &RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rabbit_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rabbit_interfaces, msg, RabPwm)() {
  if (!RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_type_support_handle.typesupport_identifier) {
    RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RabPwm__rosidl_typesupport_introspection_c__RabPwm_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
