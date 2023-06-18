// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rabbit_interfaces:msg/RabPwm.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/rab_pwm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pwm_state`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rabbit_interfaces__msg__RabPwm__init(rabbit_interfaces__msg__RabPwm * msg)
{
  if (!msg) {
    return false;
  }
  // shoot
  // state
  // pwm_current
  // pwm_state
  if (!rosidl_runtime_c__float__Sequence__init(&msg->pwm_state, 0)) {
    rabbit_interfaces__msg__RabPwm__fini(msg);
    return false;
  }
  return true;
}

void
rabbit_interfaces__msg__RabPwm__fini(rabbit_interfaces__msg__RabPwm * msg)
{
  if (!msg) {
    return;
  }
  // shoot
  // state
  // pwm_current
  // pwm_state
  rosidl_runtime_c__float__Sequence__fini(&msg->pwm_state);
}

bool
rabbit_interfaces__msg__RabPwm__are_equal(const rabbit_interfaces__msg__RabPwm * lhs, const rabbit_interfaces__msg__RabPwm * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // shoot
  if (lhs->shoot != rhs->shoot) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // pwm_current
  if (lhs->pwm_current != rhs->pwm_current) {
    return false;
  }
  // pwm_state
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->pwm_state), &(rhs->pwm_state)))
  {
    return false;
  }
  return true;
}

bool
rabbit_interfaces__msg__RabPwm__copy(
  const rabbit_interfaces__msg__RabPwm * input,
  rabbit_interfaces__msg__RabPwm * output)
{
  if (!input || !output) {
    return false;
  }
  // shoot
  output->shoot = input->shoot;
  // state
  output->state = input->state;
  // pwm_current
  output->pwm_current = input->pwm_current;
  // pwm_state
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->pwm_state), &(output->pwm_state)))
  {
    return false;
  }
  return true;
}

rabbit_interfaces__msg__RabPwm *
rabbit_interfaces__msg__RabPwm__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabPwm * msg = (rabbit_interfaces__msg__RabPwm *)allocator.allocate(sizeof(rabbit_interfaces__msg__RabPwm), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rabbit_interfaces__msg__RabPwm));
  bool success = rabbit_interfaces__msg__RabPwm__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rabbit_interfaces__msg__RabPwm__destroy(rabbit_interfaces__msg__RabPwm * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rabbit_interfaces__msg__RabPwm__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rabbit_interfaces__msg__RabPwm__Sequence__init(rabbit_interfaces__msg__RabPwm__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabPwm * data = NULL;

  if (size) {
    data = (rabbit_interfaces__msg__RabPwm *)allocator.zero_allocate(size, sizeof(rabbit_interfaces__msg__RabPwm), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rabbit_interfaces__msg__RabPwm__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rabbit_interfaces__msg__RabPwm__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rabbit_interfaces__msg__RabPwm__Sequence__fini(rabbit_interfaces__msg__RabPwm__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rabbit_interfaces__msg__RabPwm__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rabbit_interfaces__msg__RabPwm__Sequence *
rabbit_interfaces__msg__RabPwm__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabPwm__Sequence * array = (rabbit_interfaces__msg__RabPwm__Sequence *)allocator.allocate(sizeof(rabbit_interfaces__msg__RabPwm__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rabbit_interfaces__msg__RabPwm__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rabbit_interfaces__msg__RabPwm__Sequence__destroy(rabbit_interfaces__msg__RabPwm__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rabbit_interfaces__msg__RabPwm__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rabbit_interfaces__msg__RabPwm__Sequence__are_equal(const rabbit_interfaces__msg__RabPwm__Sequence * lhs, const rabbit_interfaces__msg__RabPwm__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rabbit_interfaces__msg__RabPwm__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rabbit_interfaces__msg__RabPwm__Sequence__copy(
  const rabbit_interfaces__msg__RabPwm__Sequence * input,
  rabbit_interfaces__msg__RabPwm__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rabbit_interfaces__msg__RabPwm);
    rabbit_interfaces__msg__RabPwm * data =
      (rabbit_interfaces__msg__RabPwm *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rabbit_interfaces__msg__RabPwm__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rabbit_interfaces__msg__RabPwm__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rabbit_interfaces__msg__RabPwm__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
