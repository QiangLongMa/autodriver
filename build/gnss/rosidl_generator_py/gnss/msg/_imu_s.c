// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gnss:msg/Imu.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "gnss/msg/detail/imu__struct.h"
#include "gnss/msg/detail/imu__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool gnss__msg__imu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[18];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("gnss.msg._imu.Imu", full_classname_dest, 17) == 0);
  }
  gnss__msg__Imu * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // x_linear_acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_linear_acceleration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_linear_acceleration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_linear_acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_linear_acceleration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_linear_acceleration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_linear_acceleration
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_linear_acceleration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_linear_acceleration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x_angular_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_angular_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_angular_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_angular_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_angular_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_angular_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_angular_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_angular_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_angular_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gnss__msg__imu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Imu */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gnss.msg._imu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Imu");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gnss__msg__Imu * ros_message = (gnss__msg__Imu *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_linear_acceleration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_linear_acceleration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_linear_acceleration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_linear_acceleration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_linear_acceleration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_linear_acceleration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_linear_acceleration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_linear_acceleration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_linear_acceleration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_angular_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_angular_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_angular_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_angular_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_angular_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_angular_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_angular_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_angular_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_angular_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
