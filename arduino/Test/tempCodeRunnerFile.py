from rosbags.rosbag2 import Writer
from rosbags.serde import serialize_cdr
from rosbags.typesys.types import (
    geometry_msgs__msg__Twist as Twist,
    geometry_msgs__msg__Vector3 as Vector3,
)
from pathlib import Path


# Create a new rosbag file by overwriting the existing one
with Writer(f"{Path.home()}/test2") as writer:
    # Add a new connection
    topic = "/drive_topic"
    msgtype = Twist.__msgtype__
    connection = writer.add_connection(topic, msgtype, "sqlite3", "")

    # Serialize and write the message
    timestamp = 42
    linear = Vector3(x=1.0, y=1.0, z=1.0)
    angular = Vector3(x=1.0, y=1.0, z=1.0)
    message = Twist(linear=linear, angular=angular)
    writer.write(connection, timestamp, serialize_cdr(message, msgtype))
