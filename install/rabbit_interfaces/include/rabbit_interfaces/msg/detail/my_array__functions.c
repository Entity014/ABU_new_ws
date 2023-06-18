// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice
#include "rabbit_interfaces/msg/detail/my_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `key`
#include "rosidl_runtime_c/string_functions.h"
// Member `value`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
rabbit_interfaces__msg__MyArray__init(rabbit_interfaces__msg__MyArray * msg)
{
  if (!msg) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__Sequence__init(&msg->key, 0)) {
    rabbit_interfaces__msg__MyArray__fini(msg);
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->value, 0)) {
    rabbit_interfaces__msg__MyArray__fini(msg);
    return false;
  }
  return true;
}

void
rabbit_interfaces__msg__MyArray__fini(rabbit_interfaces__msg__MyArray * msg)
{
  if (!msg) {
    return;
  }
  // key
  rosidl_runtime_c__String__Sequence__fini(&msg->key);
  // value
  rosidl_runtime_c__int64__Sequence__fini(&msg->value);
}

bool
rabbit_interfaces__msg__MyArray__are_equal(const rabbit_interfaces__msg__MyArray * lhs, const rabbit_interfaces__msg__MyArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->key), &(rhs->key)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->value), &(rhs->value)))
  {
    return false;
  }
  return true;
}

bool
rabbit_interfaces__msg__MyArray__copy(
  const rabbit_interfaces__msg__MyArray * input,
  rabbit_interfaces__msg__MyArray * output)
{
  if (!input || !output) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->key), &(output->key)))
  {
    return false;
  }
  // value
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->value), &(output->value)))
  {
    return false;
  }
  return true;
}

rabbit_interfaces__msg__MyArray *
rabbit_interfaces__msg__MyArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__MyArray * msg = (rabbit_interfaces__msg__MyArray *)allocator.allocate(sizeof(rabbit_interfaces__msg__MyArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rabbit_interfaces__msg__MyArray));
  bool success = rabbit_interfaces__msg__MyArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rabbit_interfaces__msg__MyArray__destroy(rabbit_interfaces__msg__MyArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rabbit_interfaces__msg__MyArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rabbit_interfaces__msg__MyArray__Sequence__init(rabbit_interfaces__msg__MyArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__MyArray * data = NULL;

  if (size) {
    data = (rabbit_interfaces__msg__MyArray *)allocator.zero_allocate(size, sizeof(rabbit_interfaces__msg__MyArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rabbit_interfaces__msg__MyArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rabbit_interfaces__msg__MyArray__fini(&data[i - 1]);
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
rabbit_interfaces__msg__MyArray__Sequence__fini(rabbit_interfaces__msg__MyArray__Sequence * array)
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
      rabbit_interfaces__msg__MyArray__fini(&array->data[i]);
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

rabbit_interfaces__msg__MyArray__Sequence *
rabbit_interfaces__msg__MyArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rabbit_interfaces__msg__MyArray__Sequence * array = (rabbit_interfaces__msg__MyArray__Sequence *)allocator.allocate(sizeof(rabbit_interfaces__msg__MyArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rabbit_interfaces__msg__MyArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rabbit_interfaces__msg__MyArray__Sequence__destroy(rabbit_interfaces__msg__MyArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rabbit_interfaces__msg__MyArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rabbit_interfaces__msg__MyArray__Sequence__are_equal(const rabbit_interfaces__msg__MyArray__Sequence * lhs, const rabbit_interfaces__msg__MyArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rabbit_interfaces__msg__MyArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rabbit_interfaces__msg__MyArray__Sequence__copy(
  const rabbit_interfaces__msg__MyArray__Sequence * input,
  rabbit_interfaces__msg__MyArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rabbit_interfaces__msg__MyArray);
    rabbit_interfaces__msg__MyArray * data =
      (rabbit_interfaces__msg__MyArray *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rabbit_interfaces__msg__MyArray__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          rabbit_interfaces__msg__MyArray__fini(&data[i]);
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
    if (!rabbit_interfaces__msg__MyArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
