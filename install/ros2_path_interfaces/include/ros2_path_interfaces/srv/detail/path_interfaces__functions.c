// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_path_interfaces:srv/PathInterfaces.idl
// generated code does not contain a copyright notice
#include "ros2_path_interfaces/srv/detail/path_interfaces__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ros2_path_interfaces__srv__PathInterfaces_Request__init(ros2_path_interfaces__srv__PathInterfaces_Request * msg)
{
  if (!msg) {
    return false;
  }
  // global_request
  return true;
}

void
ros2_path_interfaces__srv__PathInterfaces_Request__fini(ros2_path_interfaces__srv__PathInterfaces_Request * msg)
{
  if (!msg) {
    return;
  }
  // global_request
}

bool
ros2_path_interfaces__srv__PathInterfaces_Request__are_equal(const ros2_path_interfaces__srv__PathInterfaces_Request * lhs, const ros2_path_interfaces__srv__PathInterfaces_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // global_request
  if (lhs->global_request != rhs->global_request) {
    return false;
  }
  return true;
}

bool
ros2_path_interfaces__srv__PathInterfaces_Request__copy(
  const ros2_path_interfaces__srv__PathInterfaces_Request * input,
  ros2_path_interfaces__srv__PathInterfaces_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // global_request
  output->global_request = input->global_request;
  return true;
}

ros2_path_interfaces__srv__PathInterfaces_Request *
ros2_path_interfaces__srv__PathInterfaces_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Request * msg = (ros2_path_interfaces__srv__PathInterfaces_Request *)allocator.allocate(sizeof(ros2_path_interfaces__srv__PathInterfaces_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_path_interfaces__srv__PathInterfaces_Request));
  bool success = ros2_path_interfaces__srv__PathInterfaces_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_path_interfaces__srv__PathInterfaces_Request__destroy(ros2_path_interfaces__srv__PathInterfaces_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_path_interfaces__srv__PathInterfaces_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__init(ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Request * data = NULL;

  if (size) {
    data = (ros2_path_interfaces__srv__PathInterfaces_Request *)allocator.zero_allocate(size, sizeof(ros2_path_interfaces__srv__PathInterfaces_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_path_interfaces__srv__PathInterfaces_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_path_interfaces__srv__PathInterfaces_Request__fini(&data[i - 1]);
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
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__fini(ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * array)
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
      ros2_path_interfaces__srv__PathInterfaces_Request__fini(&array->data[i]);
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

ros2_path_interfaces__srv__PathInterfaces_Request__Sequence *
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * array = (ros2_path_interfaces__srv__PathInterfaces_Request__Sequence *)allocator.allocate(sizeof(ros2_path_interfaces__srv__PathInterfaces_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__destroy(ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__are_equal(const ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * lhs, const ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_path_interfaces__srv__PathInterfaces_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_path_interfaces__srv__PathInterfaces_Request__Sequence__copy(
  const ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * input,
  ros2_path_interfaces__srv__PathInterfaces_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_path_interfaces__srv__PathInterfaces_Request);
    ros2_path_interfaces__srv__PathInterfaces_Request * data =
      (ros2_path_interfaces__srv__PathInterfaces_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_path_interfaces__srv__PathInterfaces_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_path_interfaces__srv__PathInterfaces_Request__fini(&data[i]);
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
    if (!ros2_path_interfaces__srv__PathInterfaces_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ros2_path_interfaces__srv__PathInterfaces_Response__init(ros2_path_interfaces__srv__PathInterfaces_Response * msg)
{
  if (!msg) {
    return false;
  }
  // local_response
  // data
  if (!rosidl_runtime_c__double__Sequence__init(&msg->data, 0)) {
    ros2_path_interfaces__srv__PathInterfaces_Response__fini(msg);
    return false;
  }
  return true;
}

void
ros2_path_interfaces__srv__PathInterfaces_Response__fini(ros2_path_interfaces__srv__PathInterfaces_Response * msg)
{
  if (!msg) {
    return;
  }
  // local_response
  // data
  rosidl_runtime_c__double__Sequence__fini(&msg->data);
}

bool
ros2_path_interfaces__srv__PathInterfaces_Response__are_equal(const ros2_path_interfaces__srv__PathInterfaces_Response * lhs, const ros2_path_interfaces__srv__PathInterfaces_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // local_response
  if (lhs->local_response != rhs->local_response) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
ros2_path_interfaces__srv__PathInterfaces_Response__copy(
  const ros2_path_interfaces__srv__PathInterfaces_Response * input,
  ros2_path_interfaces__srv__PathInterfaces_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // local_response
  output->local_response = input->local_response;
  // data
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

ros2_path_interfaces__srv__PathInterfaces_Response *
ros2_path_interfaces__srv__PathInterfaces_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Response * msg = (ros2_path_interfaces__srv__PathInterfaces_Response *)allocator.allocate(sizeof(ros2_path_interfaces__srv__PathInterfaces_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_path_interfaces__srv__PathInterfaces_Response));
  bool success = ros2_path_interfaces__srv__PathInterfaces_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_path_interfaces__srv__PathInterfaces_Response__destroy(ros2_path_interfaces__srv__PathInterfaces_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_path_interfaces__srv__PathInterfaces_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__init(ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Response * data = NULL;

  if (size) {
    data = (ros2_path_interfaces__srv__PathInterfaces_Response *)allocator.zero_allocate(size, sizeof(ros2_path_interfaces__srv__PathInterfaces_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_path_interfaces__srv__PathInterfaces_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_path_interfaces__srv__PathInterfaces_Response__fini(&data[i - 1]);
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
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__fini(ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * array)
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
      ros2_path_interfaces__srv__PathInterfaces_Response__fini(&array->data[i]);
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

ros2_path_interfaces__srv__PathInterfaces_Response__Sequence *
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * array = (ros2_path_interfaces__srv__PathInterfaces_Response__Sequence *)allocator.allocate(sizeof(ros2_path_interfaces__srv__PathInterfaces_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__destroy(ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__are_equal(const ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * lhs, const ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_path_interfaces__srv__PathInterfaces_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_path_interfaces__srv__PathInterfaces_Response__Sequence__copy(
  const ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * input,
  ros2_path_interfaces__srv__PathInterfaces_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_path_interfaces__srv__PathInterfaces_Response);
    ros2_path_interfaces__srv__PathInterfaces_Response * data =
      (ros2_path_interfaces__srv__PathInterfaces_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_path_interfaces__srv__PathInterfaces_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          ros2_path_interfaces__srv__PathInterfaces_Response__fini(&data[i]);
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
    if (!ros2_path_interfaces__srv__PathInterfaces_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
