# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_robot_interfaces:srv/FeatureDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FeatureDetection_Request(type):
    """Metaclass of message 'FeatureDetection_Request'."""

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
            module = import_type_support('my_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_interfaces.srv.FeatureDetection_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_detection__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_detection__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_detection__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_detection__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_detection__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureDetection_Request(metaclass=Metaclass_FeatureDetection_Request):
    """Message class 'FeatureDetection_Request'."""

    __slots__ = [
        '_feature',
        '_feature_id',
    ]

    _fields_and_field_types = {
        'feature': 'string',
        'feature_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.feature = kwargs.get('feature', str())
        self.feature_id = kwargs.get('feature_id', str())

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
        if self.feature != other.feature:
            return False
        if self.feature_id != other.feature_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def feature(self):
        """Message field 'feature'."""
        return self._feature

    @feature.setter
    def feature(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'feature' field must be of type 'str'"
        self._feature = value

    @builtins.property
    def feature_id(self):
        """Message field 'feature_id'."""
        return self._feature_id

    @feature_id.setter
    def feature_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'feature_id' field must be of type 'str'"
        self._feature_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FeatureDetection_Response(type):
    """Metaclass of message 'FeatureDetection_Response'."""

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
            module = import_type_support('my_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_interfaces.srv.FeatureDetection_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__feature_detection__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__feature_detection__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__feature_detection__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__feature_detection__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__feature_detection__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FeatureDetection_Response(metaclass=Metaclass_FeatureDetection_Response):
    """Message class 'FeatureDetection_Response'."""

    __slots__ = [
        '_detected',
        '_message',
        '_positions',
    ]

    _fields_and_field_types = {
        'detected': 'boolean',
        'message': 'string',
        'positions': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.detected = kwargs.get('detected', bool())
        self.message = kwargs.get('message', str())
        self.positions = kwargs.get('positions', [])

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
        if self.detected != other.detected:
            return False
        if self.message != other.message:
            return False
        if self.positions != other.positions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def detected(self):
        """Message field 'detected'."""
        return self._detected

    @detected.setter
    def detected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'detected' field must be of type 'bool'"
        self._detected = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def positions(self):
        """Message field 'positions'."""
        return self._positions

    @positions.setter
    def positions(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
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
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'positions' field must be a set or sequence and each value of type 'Point'"
        self._positions = value


class Metaclass_FeatureDetection(type):
    """Metaclass of service 'FeatureDetection'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('my_robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_robot_interfaces.srv.FeatureDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__feature_detection

            from my_robot_interfaces.srv import _feature_detection
            if _feature_detection.Metaclass_FeatureDetection_Request._TYPE_SUPPORT is None:
                _feature_detection.Metaclass_FeatureDetection_Request.__import_type_support__()
            if _feature_detection.Metaclass_FeatureDetection_Response._TYPE_SUPPORT is None:
                _feature_detection.Metaclass_FeatureDetection_Response.__import_type_support__()


class FeatureDetection(metaclass=Metaclass_FeatureDetection):
    from my_robot_interfaces.srv._feature_detection import FeatureDetection_Request as Request
    from my_robot_interfaces.srv._feature_detection import FeatureDetection_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
