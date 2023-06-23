import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from sensor_msgs.msg import Joy
from rclpy import qos


class JoyConnectionChecker(Node):
    def __init__(self):
        super().__init__("joy_connection_checker")
        self.publisher_ = self.create_publisher(
            String, "joy_connection_status", qos_profile=qos.qos_profile_system_default
        )
        self.joy_connected = False
        self.timer_ = self.create_timer(0.08, self.timer_callback)

    def timer_callback(self):
        if self.joy_connected:
            msg = String()
            msg.data = "JoyCon"
        else:
            msg = String()
            msg.data = "JoyUnCon"
        self.publisher_.publish(msg)
        self.joy_connected = False

    def joy_callback(self, msg):
        self.joy_connected = True


def main(args=None):
    rclpy.init(args=args)
    joy_checker = JoyConnectionChecker()
    joy_checker.create_subscription(
        Joy, "joy", joy_checker.joy_callback, qos_profile=qos.qos_profile_sensor_data
    )
    rclpy.spin(joy_checker)
    joy_checker.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
