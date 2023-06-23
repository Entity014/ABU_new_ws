from rosbags.rosbag2 import Reader
from rosbags.serde import deserialize_cdr
from geometry_msgs.msg import Twist, Vector3
from pathlib import Path

with Reader(f"{Path.home()}/test") as reader:
    for connection, timestamp, rawdata in reader.messages():
        if (
            connection.topic == "/drive_topic"
            and connection.msgtype == "geometry_msgs/msg/Twist"
        ):
            msg = deserialize_cdr(rawdata, connection.msgtype)

            lx = Twist(
                linear=Vector3(x=msg.linear.x, y=msg.linear.y, z=msg.linear.z),
                angular=Vector3(x=msg.angular.x, y=msg.angular.y, z=msg.angular.z),
            )

            # Check if any component of lx.linear or lx.angular is greater than 0
            if (
                lx.linear.x != 0
                or lx.linear.y != 0
                or lx.linear.z != 0
                or lx.angular.x != 0
                or lx.angular.y != 0
                or lx.angular.z != 0
            ):
                print(lx)
