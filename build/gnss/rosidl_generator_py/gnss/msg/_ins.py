# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gnss:msg/Ins.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Ins(type):
    """Metaclass of message 'Ins'."""

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
            module = import_type_support('gnss')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gnss.msg.Ins')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ins
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ins
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ins
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ins
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ins

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Ins(metaclass=Metaclass_Ins):
    """Message class 'Ins'."""

    __slots__ = [
        '_header',
        '_latitude',
        '_longitude',
        '_height',
        '_undulation',
        '_north_velocity',
        '_east_velocity',
        '_up_velocity',
        '_roll',
        '_pitch',
        '_azimuth',
        '_latitude_std',
        '_longitude_std',
        '_height_std',
        '_north_velocity_std',
        '_east_velocity_std',
        '_up_velocity_std',
        '_roll_std',
        '_pitch_std',
        '_azimuth_std',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'latitude': 'double',
        'longitude': 'double',
        'height': 'double',
        'undulation': 'float',
        'north_velocity': 'double',
        'east_velocity': 'double',
        'up_velocity': 'double',
        'roll': 'double',
        'pitch': 'double',
        'azimuth': 'double',
        'latitude_std': 'float',
        'longitude_std': 'float',
        'height_std': 'float',
        'north_velocity_std': 'float',
        'east_velocity_std': 'float',
        'up_velocity_std': 'float',
        'roll_std': 'float',
        'pitch_std': 'float',
        'azimuth_std': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.latitude = kwargs.get('latitude', float())
        self.longitude = kwargs.get('longitude', float())
        self.height = kwargs.get('height', float())
        self.undulation = kwargs.get('undulation', float())
        self.north_velocity = kwargs.get('north_velocity', float())
        self.east_velocity = kwargs.get('east_velocity', float())
        self.up_velocity = kwargs.get('up_velocity', float())
        self.roll = kwargs.get('roll', float())
        self.pitch = kwargs.get('pitch', float())
        self.azimuth = kwargs.get('azimuth', float())
        self.latitude_std = kwargs.get('latitude_std', float())
        self.longitude_std = kwargs.get('longitude_std', float())
        self.height_std = kwargs.get('height_std', float())
        self.north_velocity_std = kwargs.get('north_velocity_std', float())
        self.east_velocity_std = kwargs.get('east_velocity_std', float())
        self.up_velocity_std = kwargs.get('up_velocity_std', float())
        self.roll_std = kwargs.get('roll_std', float())
        self.pitch_std = kwargs.get('pitch_std', float())
        self.azimuth_std = kwargs.get('azimuth_std', float())

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
        if self.header != other.header:
            return False
        if self.latitude != other.latitude:
            return False
        if self.longitude != other.longitude:
            return False
        if self.height != other.height:
            return False
        if self.undulation != other.undulation:
            return False
        if self.north_velocity != other.north_velocity:
            return False
        if self.east_velocity != other.east_velocity:
            return False
        if self.up_velocity != other.up_velocity:
            return False
        if self.roll != other.roll:
            return False
        if self.pitch != other.pitch:
            return False
        if self.azimuth != other.azimuth:
            return False
        if self.latitude_std != other.latitude_std:
            return False
        if self.longitude_std != other.longitude_std:
            return False
        if self.height_std != other.height_std:
            return False
        if self.north_velocity_std != other.north_velocity_std:
            return False
        if self.east_velocity_std != other.east_velocity_std:
            return False
        if self.up_velocity_std != other.up_velocity_std:
            return False
        if self.roll_std != other.roll_std:
            return False
        if self.pitch_std != other.pitch_std:
            return False
        if self.azimuth_std != other.azimuth_std:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def latitude(self):
        """Message field 'latitude'."""
        return self._latitude

    @latitude.setter
    def latitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude' field must be of type 'float'"
        self._latitude = value

    @property
    def longitude(self):
        """Message field 'longitude'."""
        return self._longitude

    @longitude.setter
    def longitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude' field must be of type 'float'"
        self._longitude = value

    @property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height' field must be of type 'float'"
        self._height = value

    @property
    def undulation(self):
        """Message field 'undulation'."""
        return self._undulation

    @undulation.setter
    def undulation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'undulation' field must be of type 'float'"
        self._undulation = value

    @property
    def north_velocity(self):
        """Message field 'north_velocity'."""
        return self._north_velocity

    @north_velocity.setter
    def north_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'north_velocity' field must be of type 'float'"
        self._north_velocity = value

    @property
    def east_velocity(self):
        """Message field 'east_velocity'."""
        return self._east_velocity

    @east_velocity.setter
    def east_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'east_velocity' field must be of type 'float'"
        self._east_velocity = value

    @property
    def up_velocity(self):
        """Message field 'up_velocity'."""
        return self._up_velocity

    @up_velocity.setter
    def up_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'up_velocity' field must be of type 'float'"
        self._up_velocity = value

    @property
    def roll(self):
        """Message field 'roll'."""
        return self._roll

    @roll.setter
    def roll(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll' field must be of type 'float'"
        self._roll = value

    @property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch' field must be of type 'float'"
        self._pitch = value

    @property
    def azimuth(self):
        """Message field 'azimuth'."""
        return self._azimuth

    @azimuth.setter
    def azimuth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth' field must be of type 'float'"
        self._azimuth = value

    @property
    def latitude_std(self):
        """Message field 'latitude_std'."""
        return self._latitude_std

    @latitude_std.setter
    def latitude_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'latitude_std' field must be of type 'float'"
        self._latitude_std = value

    @property
    def longitude_std(self):
        """Message field 'longitude_std'."""
        return self._longitude_std

    @longitude_std.setter
    def longitude_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'longitude_std' field must be of type 'float'"
        self._longitude_std = value

    @property
    def height_std(self):
        """Message field 'height_std'."""
        return self._height_std

    @height_std.setter
    def height_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height_std' field must be of type 'float'"
        self._height_std = value

    @property
    def north_velocity_std(self):
        """Message field 'north_velocity_std'."""
        return self._north_velocity_std

    @north_velocity_std.setter
    def north_velocity_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'north_velocity_std' field must be of type 'float'"
        self._north_velocity_std = value

    @property
    def east_velocity_std(self):
        """Message field 'east_velocity_std'."""
        return self._east_velocity_std

    @east_velocity_std.setter
    def east_velocity_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'east_velocity_std' field must be of type 'float'"
        self._east_velocity_std = value

    @property
    def up_velocity_std(self):
        """Message field 'up_velocity_std'."""
        return self._up_velocity_std

    @up_velocity_std.setter
    def up_velocity_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'up_velocity_std' field must be of type 'float'"
        self._up_velocity_std = value

    @property
    def roll_std(self):
        """Message field 'roll_std'."""
        return self._roll_std

    @roll_std.setter
    def roll_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'roll_std' field must be of type 'float'"
        self._roll_std = value

    @property
    def pitch_std(self):
        """Message field 'pitch_std'."""
        return self._pitch_std

    @pitch_std.setter
    def pitch_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pitch_std' field must be of type 'float'"
        self._pitch_std = value

    @property
    def azimuth_std(self):
        """Message field 'azimuth_std'."""
        return self._azimuth_std

    @azimuth_std.setter
    def azimuth_std(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth_std' field must be of type 'float'"
        self._azimuth_std = value
