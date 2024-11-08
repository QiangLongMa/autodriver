// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gnss:msg/Ins.idl
// generated code does not contain a copyright notice
#include "gnss/msg/detail/ins__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
gnss__msg__Ins__init(gnss__msg__Ins * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gnss__msg__Ins__fini(msg);
    return false;
  }
  // latitude
  // longitude
  // height
  // undulation
  // north_velocity
  // east_velocity
  // up_velocity
  // roll
  // pitch
  // azimuth
  // latitude_std
  // longitude_std
  // height_std
  // north_velocity_std
  // east_velocity_std
  // up_velocity_std
  // roll_std
  // pitch_std
  // azimuth_std
  return true;
}

void
gnss__msg__Ins__fini(gnss__msg__Ins * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // latitude
  // longitude
  // height
  // undulation
  // north_velocity
  // east_velocity
  // up_velocity
  // roll
  // pitch
  // azimuth
  // latitude_std
  // longitude_std
  // height_std
  // north_velocity_std
  // east_velocity_std
  // up_velocity_std
  // roll_std
  // pitch_std
  // azimuth_std
}

bool
gnss__msg__Ins__are_equal(const gnss__msg__Ins * lhs, const gnss__msg__Ins * rhs)
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
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // undulation
  if (lhs->undulation != rhs->undulation) {
    return false;
  }
  // north_velocity
  if (lhs->north_velocity != rhs->north_velocity) {
    return false;
  }
  // east_velocity
  if (lhs->east_velocity != rhs->east_velocity) {
    return false;
  }
  // up_velocity
  if (lhs->up_velocity != rhs->up_velocity) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // latitude_std
  if (lhs->latitude_std != rhs->latitude_std) {
    return false;
  }
  // longitude_std
  if (lhs->longitude_std != rhs->longitude_std) {
    return false;
  }
  // height_std
  if (lhs->height_std != rhs->height_std) {
    return false;
  }
  // north_velocity_std
  if (lhs->north_velocity_std != rhs->north_velocity_std) {
    return false;
  }
  // east_velocity_std
  if (lhs->east_velocity_std != rhs->east_velocity_std) {
    return false;
  }
  // up_velocity_std
  if (lhs->up_velocity_std != rhs->up_velocity_std) {
    return false;
  }
  // roll_std
  if (lhs->roll_std != rhs->roll_std) {
    return false;
  }
  // pitch_std
  if (lhs->pitch_std != rhs->pitch_std) {
    return false;
  }
  // azimuth_std
  if (lhs->azimuth_std != rhs->azimuth_std) {
    return false;
  }
  return true;
}

bool
gnss__msg__Ins__copy(
  const gnss__msg__Ins * input,
  gnss__msg__Ins * output)
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
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // height
  output->height = input->height;
  // undulation
  output->undulation = input->undulation;
  // north_velocity
  output->north_velocity = input->north_velocity;
  // east_velocity
  output->east_velocity = input->east_velocity;
  // up_velocity
  output->up_velocity = input->up_velocity;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // azimuth
  output->azimuth = input->azimuth;
  // latitude_std
  output->latitude_std = input->latitude_std;
  // longitude_std
  output->longitude_std = input->longitude_std;
  // height_std
  output->height_std = input->height_std;
  // north_velocity_std
  output->north_velocity_std = input->north_velocity_std;
  // east_velocity_std
  output->east_velocity_std = input->east_velocity_std;
  // up_velocity_std
  output->up_velocity_std = input->up_velocity_std;
  // roll_std
  output->roll_std = input->roll_std;
  // pitch_std
  output->pitch_std = input->pitch_std;
  // azimuth_std
  output->azimuth_std = input->azimuth_std;
  return true;
}

gnss__msg__Ins *
gnss__msg__Ins__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Ins * msg = (gnss__msg__Ins *)allocator.allocate(sizeof(gnss__msg__Ins), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gnss__msg__Ins));
  bool success = gnss__msg__Ins__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gnss__msg__Ins__destroy(gnss__msg__Ins * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gnss__msg__Ins__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gnss__msg__Ins__Sequence__init(gnss__msg__Ins__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Ins * data = NULL;

  if (size) {
    data = (gnss__msg__Ins *)allocator.zero_allocate(size, sizeof(gnss__msg__Ins), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gnss__msg__Ins__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gnss__msg__Ins__fini(&data[i - 1]);
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
gnss__msg__Ins__Sequence__fini(gnss__msg__Ins__Sequence * array)
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
      gnss__msg__Ins__fini(&array->data[i]);
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

gnss__msg__Ins__Sequence *
gnss__msg__Ins__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gnss__msg__Ins__Sequence * array = (gnss__msg__Ins__Sequence *)allocator.allocate(sizeof(gnss__msg__Ins__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gnss__msg__Ins__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gnss__msg__Ins__Sequence__destroy(gnss__msg__Ins__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gnss__msg__Ins__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gnss__msg__Ins__Sequence__are_equal(const gnss__msg__Ins__Sequence * lhs, const gnss__msg__Ins__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gnss__msg__Ins__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gnss__msg__Ins__Sequence__copy(
  const gnss__msg__Ins__Sequence * input,
  gnss__msg__Ins__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gnss__msg__Ins);
    gnss__msg__Ins * data =
      (gnss__msg__Ins *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gnss__msg__Ins__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          gnss__msg__Ins__fini(&data[i]);
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
    if (!gnss__msg__Ins__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
