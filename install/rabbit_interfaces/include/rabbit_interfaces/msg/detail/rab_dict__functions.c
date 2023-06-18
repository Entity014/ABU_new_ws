// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rabbit_interfaces:msg/RabDict.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/rab_dict__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `key_axes`
// Member `key_buttons`
#include "rosidl_runtime_c/string_functions.h"
// Member `value_axes`
// Member `value_buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rabbit_interfaces__msg__RabDict__init(rabbit_interfaces__msg__RabDict * msg)
{
  if (!msg) {
    return false;
  }
  // connection
  // key_axes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->key_axes, 0)) {
    rabbit_interfaces__msg__RabDict__fini(msg);
    return false;
  }
  // key_buttons
  if (!rosidl_runtime_c__String__Sequence__init(&msg->key_buttons, 0)) {
    rabbit_interfaces__msg__RabDict__fini(msg);
    return false;
  }
  // value_axes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->value_axes, 0)) {
    rabbit_interfaces__msg__RabDict__fini(msg);
    return false;
  }
  // value_buttons
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->value_buttons, 0)) {
    rabbit_interfaces__msg__RabDict__fini(msg);
    return false;
  }
  return true;
}

void
rabbit_interfaces__msg__RabDict__fini(rabbit_interfaces__msg__RabDict * msg)
{
  if (!msg) {
    return;
  }
  // connection
  // key_axes
  rosidl_runtime_c__String__Sequence__fini(&msg->key_axes);
  // key_buttons
  rosidl_runtime_c__String__Sequence__fini(&msg->key_buttons);
  // value_axes
  rosidl_runtime_c__float__Sequence__fini(&msg->value_axes);
  // value_buttons
  rosidl_runtime_c__int32__Sequence__fini(&msg->value_buttons);
}

bool
rabbit_interfaces__msg__RabDict__are_equal(const rabbit_interfaces__msg__RabDict * lhs, const rabbit_interfaces__msg__RabDict * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // connection
  if (lhs->connection != rhs->connection) {
    return false;
  }
  // key_axes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->key_axes), &(rhs->key_axes)))
  {
    return false;
  }
  // key_buttons
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->key_buttons), &(rhs->key_buttons)))
  {
    return false;
  }
  // value_axes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->value_axes), &(rhs->value_axes)))
  {
    return false;
  }
  // value_buttons
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->value_buttons), &(rhs->value_buttons)))
  {
    return false;
  }
  return true;
}

bool
rabbit_interfaces__msg__RabDict__copy(
  const rabbit_interfaces__msg__RabDict * input,
  rabbit_interfaces__msg__RabDict * output)
{
  if (!input || !output) {
    return false;
  }
  // connection
  output->connection = input->connection;
  // key_axes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->key_axes), &(output->key_axes)))
  {
    return false;
  }
  // key_buttons
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->key_buttons), &(output->key_buttons)))
  {
    return false;
  }
  // value_axes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->value_axes), &(output->value_axes)))
  {
    return false;
  }
  // value_buttons
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->value_buttons), &(output->value_buttons)))
  {
    return false;
  }
  return true;
}

rabbit_interfaces__msg__RabDict *
rabbit_interfaces__msg__RabDict__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabDict * msg = (rabbit_interfaces__msg__RabDict *)allocator.allocate(sizeof(rabbit_interfaces__msg__RabDict), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rabbit_interfaces__msg__RabDict));
  bool success = rabbit_interfaces__msg__RabDict__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rabbit_interfaces__msg__RabDict__destroy(rabbit_interfaces__msg__RabDict * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rabbit_interfaces__msg__RabDict__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rabbit_interfaces__msg__RabDict__Sequence__init(rabbit_interfaces__msg__RabDict__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabDict * data = NULL;

  if (size) {
    data = (rabbit_interfaces__msg__RabDict *)allocator.zero_allocate(size, sizeof(rabbit_interfaces__msg__RabDict), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rabbit_interfaces__msg__RabDict__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rabbit_interfaces__msg__RabDict__fini(&data[i - 1]);
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
rabbit_interfaces__msg__RabDict__Sequence__fini(rabbit_interfaces__msg__RabDict__Sequence * array)
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
      rabbit_interfaces__msg__RabDict__fini(&array->data[i]);
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

rabbit_interfaces__msg__RabDict__Sequence *
rabbit_interfaces__msg__RabDict__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__RabDict__Sequence * array = (rabbit_interfaces__msg__RabDict__Sequence *)allocator.allocate(sizeof(rabbit_interfaces__msg__RabDict__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rabbit_interfaces__msg__RabDict__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rabbit_interfaces__msg__RabDict__Sequence__destroy(rabbit_interfaces__msg__RabDict__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rabbit_interfaces__msg__RabDict__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rabbit_interfaces__msg__RabDict__Sequence__are_equal(const rabbit_interfaces__msg__RabDict__Sequence * lhs, const rabbit_interfaces__msg__RabDict__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rabbit_interfaces__msg__RabDict__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rabbit_interfaces__msg__RabDict__Sequence__copy(
  const rabbit_interfaces__msg__RabDict__Sequence * input,
  rabbit_interfaces__msg__RabDict__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rabbit_interfaces__msg__RabDict);
    rabbit_interfaces__msg__RabDict * data =
      (rabbit_interfaces__msg__RabDict *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rabbit_interfaces__msg__RabDict__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rabbit_interfaces__msg__RabDict__fini(&data[i]);
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
    if (!rabbit_interfaces__msg__RabDict__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
