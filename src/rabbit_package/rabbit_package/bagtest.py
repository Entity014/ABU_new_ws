from rosbags.rosbag2 import Reader
from rosbags.serde import deserialize_cdr

# create reader instance and open for reading
with Reader("/home/entity014/test") as reader:
    # iterate over messages
    for connection, timestamp, rawdata in reader.messages():
        if connection.topic == "/drive_topic":
            msg = deserialize_cdr(rawdata, connection.msgtype)

            # Check if the message type is geometry_msgs__msg__Twist
            if connection.msgtype == "geometry_msgs/msg/Twist":
                linear_x = msg.linear.x
                linear_y = msg.linear.y
                angular_x = msg.angular.x
                angular_y = msg.angular.y

                # Print the extracted information
                print(msg.linear.x)
