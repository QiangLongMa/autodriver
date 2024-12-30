// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice

#ifndef GNSS__MSG__DETAIL__INS__FUNCTIONS_H_
#define GNSS__MSG__DETAIL__INS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gnss/msg/rosidl_generator_c__visibility_control.h"

#include "gnss/msg/detail/ins__struct.h"

/// Initialize msg/Ins message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gnss__msg__Ins
 * )) before or use
 * gnss__msg__Ins__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Ins__init(gnss__msg__Ins * msg);

/// Finalize msg/Ins message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Ins__fini(gnss__msg__Ins * msg);

/// Create msg/Ins message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gnss__msg__Ins__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
gnss__msg__Ins *
gnss__msg__Ins__create();

/// Destroy msg/Ins message.
/**
 * It calls
 * gnss__msg__Ins__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Ins__destroy(gnss__msg__Ins * msg);

/// Check for msg/Ins message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Ins__are_equal(const gnss__msg__Ins * lhs, const gnss__msg__Ins * rhs);

/// Copy a msg/Ins message.
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
gnss__msg__Ins__copy(
  const gnss__msg__Ins * input,
  gnss__msg__Ins * output);

/// Initialize array of msg/Ins messages.
/**
 * It allocates the memory for the number of elements and calls
 * gnss__msg__Ins__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Ins__Sequence__init(gnss__msg__Ins__Sequence * array, size_t size);

/// Finalize array of msg/Ins messages.
/**
 * It calls
 * gnss__msg__Ins__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Ins__Sequence__fini(gnss__msg__Ins__Sequence * array);

/// Create array of msg/Ins messages.
/**
 * It allocates the memory for the array and calls
 * gnss__msg__Ins__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
gnss__msg__Ins__Sequence *
gnss__msg__Ins__Sequence__create(size_t size);

/// Destroy array of msg/Ins messages.
/**
 * It calls
 * gnss__msg__Ins__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
void
gnss__msg__Ins__Sequence__destroy(gnss__msg__Ins__Sequence * array);

/// Check for msg/Ins message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gnss
bool
gnss__msg__Ins__Sequence__are_equal(const gnss__msg__Ins__Sequence * lhs, const gnss__msg__Ins__Sequence * rhs);

/// Copy an array of msg/Ins messages.
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
gnss__msg__Ins__Sequence__copy(
  const gnss__msg__Ins__Sequence * input,
  gnss__msg__Ins__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GNSS__MSG__DETAIL__INS__FUNCTIONS_H_
