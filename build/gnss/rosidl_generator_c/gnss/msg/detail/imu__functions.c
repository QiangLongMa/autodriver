// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gnss:msg/Imu.idl
// generated code does not contain a copyright notice
#include "gnss/msg/detail/imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gnss__msg__Imu__init(gnss__msg__Imu * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gnss__msg__Imu__fini(msg);
    return false;
  }
  // x_linear_acceleration
  // y_linear_acceleration
  // z_linear_acceleration
  // x_angular_velocity
  // y_angular_velocity
  // z_angular_velocity
  return true;
}

void
gnss__msg__Imu__fini(gnss__msg__Imu * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x_linear_acceleration
  // y_linear_acceleration
  // z_linear_acceleration
  // x_angular_velocity
  // y_angular_velocity
  // z_angular_velocity
}

bool
gnss__msg__Imu__are_equal(const gnss__msg__Imu * lhs, const gnss__msg__Imu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // x_linear_acceleration
  if (lhs->x_linear_acceleration != rhs->x_linear_acceleration) {
    return false;
  }
  // y_linear_acceleration
  if (lhs->y_linear_acceleration != rhs->y_linear_acceleration) {
    return false;
  }
  // z_linear_acceleration
  if (lhs->z_linear_acceleration != rhs->z_linear_acceleration) {
    return false;
  }
  // x_angular_velocity
  if (lhs->x_angular_velocity != rhs->x_angular_velocity) {
    return false;
  }
  // y_angular_velocity
  if (lhs->y_angular_velocity != rhs->y_angular_velocity) {
    return false;
  }
  // z_angular_velocity
  if (lhs->z_angular_velocity != rhs->z_angular_velocity) {
    return false;
  }
  return true;
}

bool
gnss__msg__Imu__copy(
  const gnss__msg__Imu * input,
  gnss__msg__Imu * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // x_linear_acceleration
  output->x_linear_acceleration = input->x_linear_acceleration;
  // y_linear_acceleration
  output->y_linear_acceleration = input->y_linear_acceleration;
  // z_linear_acceleration
  output->z_linear_acceleration = input->z_linear_acceleration;
  // x_angular_velocity
  output->x_angular_velocity = input->x_angular_velocity;
  // y_angular_velocity
  output->y_angular_velocity = input->y_angular_velocity;
  // z_angular_velocity
  output->z_angular_velocity = input->z_angular_velocity;
  return true;
}

gnss__msg__Imu *
gnss__msg__Imu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Imu * msg = (gnss__msg__Imu *)allocator.allocate(sizeof(gnss__msg__Imu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gnss__msg__Imu));
  bool success = gnss__msg__Imu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gnss__msg__Imu__destroy(gnss__msg__Imu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gnss__msg__Imu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gnss__msg__Imu__Sequence__init(gnss__msg__Imu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Imu * data = NULL;

  if (size) {
    data = (gnss__msg__Imu *)allocator.zero_allocate(size, sizeof(gnss__msg__Imu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gnss__msg__Imu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gnss__msg__Imu__fini(&data[i - 1]);
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
gnss__msg__Imu__Sequence__fini(gnss__msg__Imu__Sequence * array)
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
      gnss__msg__Imu__fini(&array->data[i]);
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

gnss__msg__Imu__Sequence *
gnss__msg__Imu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Imu__Sequence * array = (gnss__msg__Imu__Sequence *)allocator.allocate(sizeof(gnss__msg__Imu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gnss__msg__Imu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gnss__msg__Imu__Sequence__destroy(gnss__msg__Imu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gnss__msg__Imu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gnss__msg__Imu__Sequence__are_equal(const gnss__msg__Imu__Sequence * lhs, const gnss__msg__Imu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gnss__msg__Imu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gnss__msg__Imu__Sequence__copy(
  const gnss__msg__Imu__Sequence * input,
  gnss__msg__Imu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gnss__msg__Imu);
    gnss__msg__Imu * data =
      (gnss__msg__Imu *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gnss__msg__Imu__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          gnss__msg__Imu__fini(&data[i]);
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
    if (!gnss__msg__Imu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
