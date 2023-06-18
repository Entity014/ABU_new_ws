// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rabbit_interfaces:msg/MyArray.idl
// generated code does not contain a copyright notice

#ifndef RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__FUNCTIONS_H_
#define RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rabbit_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rabbit_interfaces/msg/detail/my_array__struct.h"

/// Initialize msg/MyArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rabbit_interfaces__msg__MyArray
 * )) before or use
 * rabbit_interfaces__msg__MyArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__init(rabbit_interfaces__msg__MyArray * msg);

/// Finalize msg/MyArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
void
rabbit_interfaces__msg__MyArray__fini(rabbit_interfaces__msg__MyArray * msg);

/// Create msg/MyArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rabbit_interfaces__msg__MyArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
rabbit_interfaces__msg__MyArray *
rabbit_interfaces__msg__MyArray__create();

/// Destroy msg/MyArray message.
/**
 * It calls
 * rabbit_interfaces__msg__MyArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
void
rabbit_interfaces__msg__MyArray__destroy(rabbit_interfaces__msg__MyArray * msg);

/// Check for msg/MyArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__are_equal(const rabbit_interfaces__msg__MyArray * lhs, const rabbit_interfaces__msg__MyArray * rhs);

/// Copy a msg/MyArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__copy(
  const rabbit_interfaces__msg__MyArray * input,
  rabbit_interfaces__msg__MyArray * output);

/// Initialize array of msg/MyArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * rabbit_interfaces__msg__MyArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__Sequence__init(rabbit_interfaces__msg__MyArray__Sequence * array, size_t size);

/// Finalize array of msg/MyArray messages.
/**
 * It calls
 * rabbit_interfaces__msg__MyArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
void
rabbit_interfaces__msg__MyArray__Sequence__fini(rabbit_interfaces__msg__MyArray__Sequence * array);

/// Create array of msg/MyArray messages.
/**
 * It allocates the memory for the array and calls
 * rabbit_interfaces__msg__MyArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
rabbit_interfaces__msg__MyArray__Sequence *
rabbit_interfaces__msg__MyArray__Sequence__create(size_t size);

/// Destroy array of msg/MyArray messages.
/**
 * It calls
 * rabbit_interfaces__msg__MyArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
void
rabbit_interfaces__msg__MyArray__Sequence__destroy(rabbit_interfaces__msg__MyArray__Sequence * array);

/// Check for msg/MyArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__Sequence__are_equal(const rabbit_interfaces__msg__MyArray__Sequence * lhs, const rabbit_interfaces__msg__MyArray__Sequence * rhs);

/// Copy an array of msg/MyArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rabbit_interfaces
bool
rabbit_interfaces__msg__MyArray__Sequence__copy(
  const rabbit_interfaces__msg__MyArray__Sequence * input,
  rabbit_interfaces__msg__MyArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RABBIT_INTERFACES__MSG__DETAIL__MY_ARRAY__FUNCTIONS_H_
