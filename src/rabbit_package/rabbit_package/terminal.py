import rclpy
import cv2
import math
import numpy as np

from rclpy.node import Node
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from rabbit_interfaces.msg import RabPwm
from rclpy import qos
from cv_bridge import CvBridge


class TeriminalRabbit(Node):
    def __init__(self):
        super().__init__("terminal_rabbit_node")
        self.dat = self.create_subscription(
            RabPwm,
            "pwm_topic",
            self.sub_callback,
            qos_profile=qos.qos_profile_sensor_data,
        )
        self.dat

        # self.cam = self.create_subscription(
        #     Image,
        #     "color_image_topic",
        #     self.sub_cam_callback,
        #     qos_profile=qos.qos_profile_sensor_data,
        # )
        # self.cam

        self.team = ""
        self.shoot = False
        self.state = 0
        self.pwm = 0.0
        self.pwm_gui = []

        self.width_frame, self.height_frame = (576, 720)
        self.window_state = "fullscreen"

        self.br = CvBridge()

    def sub_callback(self, msg):
        self.team = msg.type_team
        self.shoot = msg.shoot
        self.state = msg.state
        self.pwm = msg.pwm_current
        self.pwm_gui = msg.pwm_state
        self.gui()
        # self.get_logger().info(f"{self.isAuto}")

    def sub_cam_callback(self, msg):
        current_frame = self.br.imgmsg_to_cv2(msg)
        cv2.imshow("ROS2 subscriber webcam", current_frame)
        if cv2.waitKey(1) & 0xFF == ord("q"):
            # closing all open windows
            cv2.destroyAllWindows()
            exit()

    def gui(self):
        block = [
            [50, 0, self.width_frame - 50, 100],
            [50, 100, self.width_frame - 50, 100],
            [50, 200, self.width_frame - 50, 100],
            [50, 300, self.width_frame - 50, 100],
            [50, 400, self.width_frame - 50, 100],
        ]

        # frame = self.cap.read()
        frame = np.ones((self.width_frame, self.height_frame, 3), np.uint8) * 255
        frame = cv2.resize(frame, (self.width_frame, self.height_frame))
        frame = cv2.flip(frame, 0)
        # frame = cv2.flip(frame, 1)
        frame = self.draw_power_bar(frame)

        self.draw_mode(frame=frame, block=block, mode=self.state)

        frame = cv2.rotate(frame, cv2.ROTATE_90_CLOCKWISE)

        self.toggle_fullscreen()
        cv2.imshow("Webcam", frame)
        if cv2.waitKey(1) & 0xFF == ord("q"):
            # closing all open windows
            cv2.destroyAllWindows()
            exit()

    def toggle_fullscreen(self):
        cv2.namedWindow("Webcam", cv2.WND_PROP_FULLSCREEN)
        if self.window_state == "normal":
            cv2.setWindowProperty("Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_NORMAL)
        elif self.window_state == "fullscreen":
            cv2.setWindowProperty(
                "Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN
            )
        cv2.setMouseCallback("Webcam", self.mouse_callback)

    def mouse_callback(self, event, x, y, flags, param):
        if event == cv2.EVENT_LBUTTONUP:
            if (self.window_state) == "normal":
                self.window_state = "fullscreen"
            else:
                self.window_state = "normal"

    def draw_mode(self, frame, block, mode):
        text_temp = ["Near", "Medium", "Enemy", "Near Ally", "Far Enemy"]
        text_block = []

        for i, temp in enumerate(text_temp):
            text_block.append(f"{temp} {self.pwm_gui[i]}")

        for index, arr in enumerate(block):
            text = f"{text_block[index]}"
            x, y, width, height = arr
            if index == mode:
                cv2.rectangle(frame, (x, y), (x + width, y + height), (162, 223, 0), -1)
            else:
                cv2.rectangle(
                    frame, (x, y), (x + width, y + height), (200, 188, 243), -1
                )
            cv2.rectangle(frame, (x, y), (x + width, y + height), (0, 0, 0), 2)

            text_size, _ = cv2.getTextSize(text, cv2.FONT_HERSHEY_SIMPLEX, 1.5, 3)
            text_x = x + int((width - text_size[0]) / 2)
            text_y = y + int((height + text_size[1]) / 2)
            cv2.putText(
                frame,
                text,
                (text_x, text_y),
                cv2.FONT_HERSHEY_SIMPLEX,
                1.5,
                (255, 0, 0),
                3,
            )

    def interpolate_color(self, start_color, end_color, value):
        b = int(start_color[0] + (end_color[0] - start_color[0]) * value)
        g = int(start_color[1] + (end_color[1] - start_color[1]) * value)
        r = int(start_color[2] + (end_color[2] - start_color[2]) * value)
        return (b, g, r)

    def get_zone_color(self):
        color_zone1 = (0, 255, 0)
        color_zone2 = (0, 165, 255)
        color_zone3 = (0, 0, 255)

        if self.pwm <= 85:
            return color_zone1
        elif self.pwm <= 60:
            value = (self.pwm - 85) / (170 - 85)
            return self.interpolate_color(color_zone1, color_zone2, value)
        else:
            value = (self.pwm - 170) / (255 - 170)
            return self.interpolate_color(color_zone2, color_zone3, value)

    def draw_power_bar(self, frame):
        pwm_height = int((self.pwm / 255) * self.height_frame)
        pwm_color = self.get_zone_color()
        text_size_pwm, _ = cv2.getTextSize(
            f"{self.pwm}", cv2.FONT_HERSHEY_SIMPLEX, 6, 20
        )
        text_x_pwm = 50 + int((self.width_frame - 50 - text_size_pwm[0]) / 2)
        text_y_pwm = 500 + int((self.height_frame - 500 + text_size_pwm[1]) / 2)
        cv2.rectangle(
            frame,
            (0, (self.height_frame - pwm_height)),
            (50, self.height_frame),
            pwm_color,
            -1,
        )
        cv2.rectangle(
            frame, (0, 0), (50, (self.height_frame - pwm_height)), (0, 0, 0), -1
        )
        cv2.rectangle(frame, (0, 0), (50, self.height_frame), (0, 0, 0), 2)

        if self.shoot:
            if self.team == "BLUE":
                cv2.rectangle(
                    frame,
                    (50, 500),
                    (self.width_frame, int(self.height_frame)),
                    (227, 150, 90),
                    -1,
                )
            else:
                cv2.rectangle(
                    frame,
                    (50, 500),
                    (self.width_frame, int(self.height_frame)),
                    (104, 115, 237),
                    -1,
                )
        else:
            cv2.rectangle(
                frame,
                (50, 500),
                (self.width_frame, int(self.height_frame)),
                (255, 204, 243),
                -1,
            )
        cv2.rectangle(
            frame,
            (50, 500),
            (self.width_frame, int(self.height_frame)),
            (0, 0, 0),
            2,
        )
        cv2.putText(
            frame,
            f"{self.pwm}",
            (text_x_pwm, text_y_pwm),
            cv2.FONT_HERSHEY_SIMPLEX,
            6,
            (0, 0, 0),
            20,
            cv2.LINE_AA,
        )

        return frame


def main():
    rclpy.init()

    sub = TeriminalRabbit()
    rclpy.spin(sub)

    rclpy.shutdown()


if __name__ == "__main__":
    main()
