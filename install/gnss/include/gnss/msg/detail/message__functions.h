// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gnss:msg/Message.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__MESSAGE__FUNCTIONS_H_
#define GNSS__MSG__DETAIL__MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gnss/msg/rosidl_generator_c__visibility_control.h"

#include "gnss/msg/detail/message__struct.h"

/// Initialize msg/Message message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gnss__msg__Message
 * )) before or use
 * gnss__msg__Message__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__init(gnss__msg__Message * msg);

/// Finalize msg/Message message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Message__fini(gnss__msg__Message * msg);

/// Create msg/Message message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gnss__msg__Message__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
gnss__msg__Message *
gnss__msg__Message__create();

/// Destroy msg/Message message.
/**
 * It calls
 * gnss__msg__Message__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Message__destroy(gnss__msg__Message * msg);

/// Check for msg/Message message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__are_equal(const gnss__msg__Message * lhs, const gnss__msg__Message * rhs);

/// Copy a msg/Message message.
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
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__copy(
  const gnss__msg__Message * input,
  gnss__msg__Message * output);

/// Initialize array of msg/Message messages.
/**
 * It allocates the memory for the number of elements and calls
 * gnss__msg__Message__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__Sequence__init(gnss__msg__Message__Sequence * array, size_t size);

/// Finalize array of msg/Message messages.
/**
 * It calls
 * gnss__msg__Message__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Message__Sequence__fini(gnss__msg__Message__Sequence * array);

/// Create array of msg/Message messages.
/**
 * It allocates the memory for the array and calls
 * gnss__msg__Message__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
gnss__msg__Message__Sequence *
gnss__msg__Message__Sequence__create(size_t size);

/// Destroy array of msg/Message messages.
/**
 * It calls
 * gnss__msg__Message__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Message__Sequence__destroy(gnss__msg__Message__Sequence * array);

/// Check for msg/Message message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__Sequence__are_equal(const gnss__msg__Message__Sequence * lhs, const gnss__msg__Message__Sequence * rhs);

/// Copy an array of msg/Message messages.
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
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Message__Sequence__copy(
  const gnss__msg__Message__Sequence * input,
  gnss__msg__Message__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__MESSAGE__FUNCTIONS_H_
