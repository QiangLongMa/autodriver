// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gnss:msg/Ins.idl
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
#include "gnss/msg/detail/ins__struct.h"
#include "gnss/msg/detail/ins__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool gnss__msg__ins__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("gnss.msg._ins.Ins", full_classname_dest, 17) == 0);
  }
  gnss__msg__Ins * ros_message = _ros_message;
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
  {  // latitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // longitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // undulation
    PyObject * field = PyObject_GetAttrString(_pymsg, "undulation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->undulation = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // north_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "north_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->north_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // east_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "east_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->east_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // up_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "up_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->up_velocity = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // azimuth
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // latitude_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "latitude_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->latitude_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // longitude_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "longitude_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->longitude_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // height_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "height_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // north_velocity_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "north_velocity_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->north_velocity_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // east_velocity_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "east_velocity_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->east_velocity_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // up_velocity_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "up_velocity_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->up_velocity_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // azimuth_std
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth_std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth_std = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gnss__msg__ins__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Ins */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gnss.msg._ins");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Ins");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gnss__msg__Ins * ros_message = (gnss__msg__Ins *)raw_ros_message;
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
  {  // latitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // longitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // undulation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->undulation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "undulation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // north_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->north_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "north_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // east_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->east_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "east_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // up_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->up_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "up_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // latitude_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->latitude_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "latitude_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // longitude_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->longitude_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "longitude_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // north_velocity_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->north_velocity_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "north_velocity_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // east_velocity_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->east_velocity_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "east_velocity_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // up_velocity_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->up_velocity_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "up_velocity_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth_std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth_std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth_std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
