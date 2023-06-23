import rclpy
import numpy as np

from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
from rabbit_interfaces.msg import RabDict
from rclpy import qos


class JoyStick(Node):
    def __init__(self):
        super().__init__("joystick_node")
        self.controller = self.create_subscription(
            Joy,
            "joy",
            self.sub_controller_callback,
            qos_profile=qos.qos_profile_sensor_data,
        )
        self.controller

        self.joyCon = self.create_subscription(
            String,
            "joy_connection_status",
            self.sub_callback_joyCon,
            qos_profile=qos.qos_profile_sensor_data,
        )
        self.joyCon

        self.sent_joy = self.create_publisher(
            RabDict, "joystick_topic", qos_profile=qos.qos_profile_system_default
        )
        self.sent_joy_timer = self.create_timer(0.05, self.sent_controller_callback)

        self.declare_parameters("", [("type_joy", None)])
        self.controller_type = (
            self.get_parameter("type_joy").get_parameter_value().string_value
        )

        self.all = [
            "X",
            "O",
            "Dummy2",
            "S",
            "T",
            "Dummy5",
            "L1",
            "R1",
            "Dummy8",
            "Dummy9",
            "L",
            "R",
            "PS",
            "LS",
            "RS",
            "XBOX",
        ]  # ? XBOX
        self.all2 = ["LX", "LY", "RX", "RY", "LT", "RT", "AX", "AY"]  # ? XBOX
        self.button = {element: 0 for element in self.all}
        self.axes = {element: 0 for element in self.all2}
        self.button["L2"] = 0
        self.button["R2"] = 0

        self.joyState = False

    def sub_controller_callback(self, msg):
        # ? XBOX
        if msg.axes[5] < 0:
            self.button["L2"] = 1
        else:
            self.button["L2"] = 0
        if msg.axes[4] < 0:
            self.button["R2"] = 1
        else:
            self.button["R2"] = 0

        for index, element in enumerate(self.all):
            self.button[element] = msg.buttons[index]
        #     print(f"{self.all[index]}  :  {self.button[element]}")

        for index, element in enumerate(self.all2):
            if msg.axes[index] <= 0.1 and msg.axes[index] >= -0.1:
                self.axes[element] = 0.0
            else:
                self.axes[element] = msg.axes[index]

    def sub_callback_joyCon(self, msg):
        if msg.data == "JoyCon":
            self.joyState = True
        else:
            self.joyState = False

    def sent_controller_callback(self):
        msg = RabDict()
        self.axes = {key: float(value) for key, value in self.axes.items()}
        msg.connection = self.joyState
        msg.key_axes = list(self.axes.keys())
        msg.key_buttons = list(self.button.keys())
        msg.value_axes = list(self.axes.values())
        msg.value_buttons = list(self.button.values())

        # self.get_logger().info(f"{self.controller_type}")
        self.sent_joy.publish(msg)


def main():
    rclpy.init()

    sub = JoyStick()
    rclpy.spin(sub)

    rclpy.shutdown()


if __name__ == "__main__":
    main()
