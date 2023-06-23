import rclpy
import numpy as np
import math

from rclpy.node import Node
from geometry_msgs.msg import Twist, Vector3
from rabbit_interfaces.msg import RabDict
from rclpy import qos
from rosbags.rosbag2 import Reader
from rosbags.serde import deserialize_cdr
from pathlib import Path


class DriveRabbit(Node):
    def __init__(self):
        super().__init__("drive_rabbit_node")
        self.dat = self.create_subscription(
            RabDict,
            "joystick_topic",
            self.sub_callback,
            qos_profile=qos.qos_profile_sensor_data,
        )
        self.dat

        self.sent_drive = self.create_publisher(
            Twist, "drive_topic", qos_profile=qos.qos_profile_system_default
        )
        self.sent_drive_timer = self.create_timer(0.05, self.sent_drive_callback)

        self.axes = {}
        self.buttons = {}
        self.joyState = False

        self.distance = 0.0
        self.state_speed = 0
        self.state_auto = 0
        self.preDriveMode = -1
        self.stateDriveMode = 0

        self.preAuto = -1

        self.param_distance = 10

        self.auto_drive_temp = []
        self.counter = 0

        self.declare_parameters("", [("speed_motor", None), ("path_auto", None)])
        self.speed = (
            self.get_parameter("speed_motor").get_parameter_value().double_value
        ) / 255
        self.path_auto = (
            self.get_parameter("path_auto").get_parameter_value().string_value
        )

        with Reader(f"{Path.home()}{self.path_auto}") as reader:
            # iterate over messages
            for connection, timestamp, rawdata in reader.messages():
                if (
                    connection.topic == "/drive_topic"
                    and connection.msgtype == "geometry_msgs/msg/Twist"
                ):
                    msg_auto = deserialize_cdr(rawdata, connection.msgtype)
                    temp_msg_auto = Twist(
                        linear=Vector3(
                            x=msg_auto.linear.x,
                            y=msg_auto.linear.y,
                            z=msg_auto.linear.z,
                        ),
                        angular=Vector3(
                            x=msg_auto.angular.x,
                            y=msg_auto.angular.y,
                            z=msg_auto.angular.z,
                        ),
                    )
                    if (
                        temp_msg_auto.linear.x != 0
                        or temp_msg_auto.linear.y != 0
                        or temp_msg_auto.linear.z != 0
                        or temp_msg_auto.angular.x != 0
                        or temp_msg_auto.angular.y != 0
                        or temp_msg_auto.angular.z != 0
                    ):
                        self.auto_drive_temp.append(temp_msg_auto)

    def sub_callback(self, msg):
        self.axes = dict(zip(msg.key_axes, msg.value_axes))
        self.buttons = dict(zip(msg.key_buttons, msg.value_buttons))
        self.joyState = msg.connection

    def sent_drive_callback(self):  # publisher drive topic
        limit = 0.1
        in_limit = -1 * limit
        msg = Twist()

        x = 0.0
        y = 0.0
        msg.linear.x = 0.0
        msg.linear.y = 0.0
        msg.angular.x = 0.0
        msg.angular.y = 0.0

        try:
            if self.preDriveMode != self.buttons["L"]:
                self.preDriveMode = self.buttons["L"]
                if self.buttons["L"] == 1:
                    self.stateDriveMode += 1

            if self.state_speed == 0:
                if (self.axes["AX"] != 0) or (self.axes["AY"] != 0):
                    y = -1 * self.axes["AX"]
                    x = -1 * self.axes["AY"]
                    if self.stateDriveMode == 1:
                        x = np.interp(x, [-1, 1], [-1 * self.speed, self.speed])
                        y = np.interp(y, [-1, 1], [-1 * self.speed, self.speed])
                    else:
                        self.stateDriveMode = 0

                else:
                    y = -1 * self.axes["LX"]
                    x = -1 * self.axes["LY"]
                    if self.stateDriveMode > 1:
                        self.stateDriveMode = 0
                    # if self.stateDriveMode == 1:
                    #     if y != 0.0:
                    #         y = (abs(y) / y) * 0.55
                    #     if (x > limit) and (y > limit):
                    #         x = 0.707
                    #         y = 0.707
                    #     elif (x < in_limit) and (y > limit):
                    #         x = -0.707
                    #         y = 0.707
                    #     elif (x < in_limit) and (y < in_limit):
                    #         x = -0.707
                    #         y = -0.707
                    #     elif (x > limit) and (y < in_limit):
                    #         x = 0.707
                    #         y = -0.707
                    #     else:
                    #         x = 0.0
                    #         y = 0.0
                    # elif self.stateDriveMode == 2:
                    #     self.stateDriveMode = 0

            if (
                (self.buttons["PS"] == 1)
                and (self.axes["AX"] == 0)
                and (self.axes["AY"] == 0)
                and (self.axes["LY"] == 0)
                and (self.axes["LX"] == 0)
            ):
                self.state_speed = 1
            else:
                self.state_speed = 0

            if self.state_speed == 1:
                if self.distance > self.param_distance:
                    x = 0.707
                    y = 0.707
                elif self.distance < (self.param_distance * -1):
                    x = -0.707
                    y = 0.707
                else:
                    self.state_speed = 0
                    x = 0.0
                    y = 0.0

            y = y * -1
            turn = np.interp(self.axes["RX"], [-1, 1], [-0.392, 0.392])
            theta = math.atan2(y, x)
            power = math.hypot(x, y)
            sin = math.sin(theta - math.pi / 4)
            cos = math.cos(theta - math.pi / 4)
            Max = max(abs(sin), abs(cos))
            leftFront = power * cos / Max + turn
            rightFront = power * sin / Max + turn
            leftBack = power * sin / Max - turn
            rightBack = power * cos / Max - turn

            if (power + abs(turn)) > 1:
                leftFront /= power + abs(turn)
                rightFront /= power + abs(turn)
                leftBack /= power + abs(turn)
                rightBack /= power + abs(turn)

            msg.linear.x = float(round(leftFront * 255))
            msg.linear.y = float(round(rightFront * 255))
            msg.angular.x = float(round(leftBack * 255))
            msg.angular.y = float(round(rightBack * 255))

            if self.preAuto != self.buttons["O"]:
                self.preAuto = self.buttons["O"]
                if self.preAuto == 1:
                    self.state_auto += 1
            if x != 0 or y != 0 or turn != 0 or self.state_auto >= 2:
                self.state_auto = 0
                self.counter = 0

            if self.state_auto == 1:
                if self.counter != len(self.auto_drive_temp):
                    msg = self.auto_drive_temp[self.counter]
                    self.counter += 1
                else:
                    self.counter = 0
                    self.state_auto = 0

        except KeyError:
            pass

        if not self.joyState:
            msg.linear.x = 0.0
            msg.linear.y = 0.0
            msg.angular.x = 0.0
            msg.angular.y = 0.0

        # self.get_logger().info(f"{self.path_auto}")
        self.sent_drive.publish(msg)


def main():
    rclpy.init()

    sub = DriveRabbit()
    rclpy.spin(sub)

    rclpy.shutdown()


if __name__ == "__main__":
    main()
