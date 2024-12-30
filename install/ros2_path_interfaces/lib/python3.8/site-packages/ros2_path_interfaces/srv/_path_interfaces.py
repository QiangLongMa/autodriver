# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_path_interfaces:srv/PathInterfaces.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PathInterfaces_Request(type):
    """Metaclass of message 'PathInterfaces_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_path_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_path_interfaces.srv.PathInterfaces_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__path_interfaces__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__path_interfaces__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__path_interfaces__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__path_interfaces__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__path_interfaces__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PathInterfaces_Request(metaclass=Metaclass_PathInterfaces_Request):
    """Message class 'PathInterfaces_Request'."""

    __slots__ = [
        '_global_request',
    ]

    _fields_and_field_types = {
        'global_request': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.global_request = kwargs.get('global_request', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.global_request != other.global_request:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def global_request(self):
        """Message field 'global_request'."""
        return self._global_request

    @global_request.setter
    def global_request(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'global_request' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'global_request' field must be an integer in [-2147483648, 2147483647]"
        self._global_request = value


# Import statements for member types

# Member 'data'
import array  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_PathInterfaces_Response(type):
    """Metaclass of message 'PathInterfaces_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_path_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_path_interfaces.srv.PathInterfaces_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__path_interfaces__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__path_interfaces__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__path_interfaces__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__path_interfaces__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__path_interfaces__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PathInterfaces_Response(metaclass=Metaclass_PathInterfaces_Response):
    """Message class 'PathInterfaces_Response'."""

    __slots__ = [
        '_local_response',
        '_data',
    ]

    _fields_and_field_types = {
        'local_response': 'int32',
        'data': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.local_response = kwargs.get('local_response', int())
        self.data = array.array('d', kwargs.get('data', []))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.local_response != other.local_response:
            return False
        if self.data != other.data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def local_response(self):
        """Message field 'local_response'."""
        return self._local_response

    @local_response.setter
    def local_response(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'local_response' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'local_response' field must be an integer in [-2147483648, 2147483647]"
        self._local_response = value

    @property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'data' array.array() must have the type code of 'd'"
            self._data = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'data' field must be a set or sequence and each value of type 'float'"
        self._data = array.array('d', value)


class Metaclass_PathInterfaces(type):
    """Metaclass of service 'PathInterfaces'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_path_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_path_interfaces.srv.PathInterfaces')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__path_interfaces

            from ros2_path_interfaces.srv import _path_interfaces
            if _path_interfaces.Metaclass_PathInterfaces_Request._TYPE_SUPPORT is None:
                _path_interfaces.Metaclass_PathInterfaces_Request.__import_type_support__()
            if _path_interfaces.Metaclass_PathInterfaces_Response._TYPE_SUPPORT is None:
                _path_interfaces.Metaclass_PathInterfaces_Response.__import_type_support__()


class PathInterfaces(metaclass=Metaclass_PathInterfaces):
    from ros2_path_interfaces.srv._path_interfaces import PathInterfaces_Request as Request
    from ros2_path_interfaces.srv._path_interfaces import PathInterfaces_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
