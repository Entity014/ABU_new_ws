# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rabbit_interfaces:msg/RabDict.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'value_axes'
# Member 'value_buttons'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RabDict(type):
    """Metaclass of message 'RabDict'."""

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
            module = import_type_support('rabbit_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rabbit_interfaces.msg.RabDict')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rab_dict
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rab_dict
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rab_dict
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rab_dict
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rab_dict

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RabDict(metaclass=Metaclass_RabDict):
    """Message class 'RabDict'."""

    __slots__ = [
        '_connection',
        '_key_axes',
        '_key_buttons',
        '_value_axes',
        '_value_buttons',
    ]

    _fields_and_field_types = {
        'connection': 'boolean',
        'key_axes': 'sequence<string>',
        'key_buttons': 'sequence<string>',
        'value_axes': 'sequence<float>',
        'value_buttons': 'sequence<int32>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.connection = kwargs.get('connection', bool())
        self.key_axes = kwargs.get('key_axes', [])
        self.key_buttons = kwargs.get('key_buttons', [])
        self.value_axes = array.array('f', kwargs.get('value_axes', []))
        self.value_buttons = array.array('i', kwargs.get('value_buttons', []))

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
        if self.connection != other.connection:
            return False
        if self.key_axes != other.key_axes:
            return False
        if self.key_buttons != other.key_buttons:
            return False
        if self.value_axes != other.value_axes:
            return False
        if self.value_buttons != other.value_buttons:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def connection(self):
        """Message field 'connection'."""
        return self._connection

    @connection.setter
    def connection(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'connection' field must be of type 'bool'"
        self._connection = value

    @property
    def key_axes(self):
        """Message field 'key_axes'."""
        return self._key_axes

    @key_axes.setter
    def key_axes(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'key_axes' field must be a set or sequence and each value of type 'str'"
        self._key_axes = value

    @property
    def key_buttons(self):
        """Message field 'key_buttons'."""
        return self._key_buttons

    @key_buttons.setter
    def key_buttons(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'key_buttons' field must be a set or sequence and each value of type 'str'"
        self._key_buttons = value

    @property
    def value_axes(self):
        """Message field 'value_axes'."""
        return self._value_axes

    @value_axes.setter
    def value_axes(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'value_axes' array.array() must have the type code of 'f'"
            self._value_axes = value
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
                "The 'value_axes' field must be a set or sequence and each value of type 'float'"
        self._value_axes = array.array('f', value)

    @property
    def value_buttons(self):
        """Message field 'value_buttons'."""
        return self._value_buttons

    @value_buttons.setter
    def value_buttons(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'value_buttons' array.array() must have the type code of 'i'"
            self._value_buttons = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'value_buttons' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._value_buttons = array.array('i', value)
