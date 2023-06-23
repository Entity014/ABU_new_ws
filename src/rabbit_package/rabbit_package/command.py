import rclpy
import numpy as np
import math
import configparser

from rclpy.node import Node
from geometry_msgs.msg import Twist
from rabbit_interfaces.msg import RabDict, RabPwm
from rclpy import qos
from pathlib import Path


class CommandRabbit(Node):
    def __init__(self):
        super().__init__("command_rabbit_node")
        self.dat = self.create_subscription(
            RabDict,
            "joystick_topic",
            self.sub_callback,
            qos_profile=qos.qos_profile_sensor_data,
        )
        self.dat

        self.sent_command = self.create_publisher(
            Twist, "command_topic", qos_profile=qos.qos_profile_system_default
        )
        self.sent_command_timer = self.create_timer(0.05, self.sent_command_callback)

        self.send_data_gui = self.create_publisher(
            RabPwm, "pwm_topic", qos_profile=qos.qos_profile_system_default
        )
        self.send_data_gui_timer = self.create_timer(0.05, self.send_data_gui_callback)

        self.axes = {}
        self.buttons = {}
        self.joyState = False

        self.pwm = 0.0
        self.save_pwm = 0.0
        self.state = 0
        self.counter = 0

        self.assis_shoot = [0, 0, 0, 0, 0]
        self.list_debount_r = []
        self.list_debount_l = []

        self.preShoot = -1
        self.preStateShot = -1
        self.stateShoot = 0

        home = str(Path.home())
        file = "/config.ini"
        self.file_path = home + file
        self.config = configparser.ConfigParser()
        self.config.read(self.file_path)
        self.param_pwm_motor1 = float(self.config["DEFAULT"]["param1"])  # ใกล้
        self.param_pwm_motor2 = float(self.config["DEFAULT"]["param2"])  # กลาง
        self.param_pwm_motor3 = float(self.config["DEFAULT"]["param3"])  # ฝั่งตรงข้าม
        self.param_pwm_motor4 = float(self.config["DEFAULT"]["param4"])  # ใกล้ช้าง
        self.param_pwm_motor5 = float(
            self.config["DEFAULT"]["param5"]
        )  # ฝั่งตรงข้ามไกล

    def sub_callback(self, msg):
        self.axes = dict(zip(msg.key_axes, msg.value_axes))
        self.buttons = dict(zip(msg.key_buttons, msg.value_buttons))
        self.joyState = msg.connection

    def sent_command_callback(self):
        msg = Twist()

        msg.linear.x = 0.0  # pwm shoot
        msg.angular.x = 0.0  # command

        try:
            if self.buttons["PS"] == 1:
                self.write_configs(f"param{self.state+1}", str(self.pwm))

            # //------------------------------------------------------------------------------------------------//
            if self.preStateShot != self.buttons["R"]:
                self.preStateShot = self.buttons["R"]
                if self.preStateShot == 1:
                    self.state += 1
            if self.state > 4:
                self.state = 0
            if self.state < 0:
                self.state = 1
            if self.state == 0:
                self.pwm = self.param_pwm_motor1 - self.assis_shoot[0]
            elif self.state == 1:
                self.pwm = self.param_pwm_motor2 - self.assis_shoot[1]
            elif self.state == 2:
                self.pwm = self.param_pwm_motor3 - self.assis_shoot[2]
            elif self.state == 3:
                self.pwm = self.param_pwm_motor4 - self.assis_shoot[3]
            elif self.state == 4:
                self.pwm = self.param_pwm_motor5 - self.assis_shoot[4]

            if self.pwm > 255:
                self.pwm = 255.0
            elif self.pwm < 0:
                self.pwm = 0.0

            if self.preShoot != self.buttons["X"]:
                self.preShoot = self.buttons["X"]
                if self.buttons["X"] == 1:
                    self.stateShoot += 1

            if self.stateShoot == 0:
                msg.linear.x = 0.0
            elif self.stateShoot == 1:
                msg.linear.x = self.pwm
            elif self.stateShoot == 2:
                self.stateShoot = 0
            # //------------------------------------------------------------------------------------------------//
            if (self.buttons["L2"] == 1) and (self.buttons["R2"] == 1):
                self.assis_shoot[self.state] = 0
            elif self.buttons["L2"] == 1:
                self.assis_shoot[self.state] += 0.5
            elif self.buttons["R2"] == 1:
                self.assis_shoot[self.state] -= 0.5

            # //------------------------------------------------------------------------------------------------//
            if self.buttons["T"] == 1:
                msg.angular.x = 1.0
            if self.buttons["L1"] == 1:
                msg.angular.y = 10.0
            if self.buttons["S"] == 1:
                msg.angular.y = 20.0

            if self.buttons["R1"] == 1:
                msg.angular.z = 999.0
            if self.buttons["O"] == 1:
                msg.linear.y = 888.0

            self.save_pwm = msg.linear.x

        except KeyError:
            pass

        self.sent_command.publish(msg)

    def send_data_gui_callback(self):
        msg = RabPwm()
        msg.pwm_current = self.pwm
        msg.pwm_state = [
            self.param_pwm_motor1,
            self.param_pwm_motor2,
            self.param_pwm_motor3,
            self.param_pwm_motor4,
            self.param_pwm_motor5,
        ]
        msg.state = self.state
        if self.save_pwm > 0:
            msg.shoot = True
        else:
            msg.shoot = False

        self.send_data_gui.publish(msg)

    def read_configs(self):
        self.config.read(self.file_path)
        a = {}
        for i in range(len(self.assis_shoot)):
            a[f"param{i+1}"] = float(self.config["DEFAULT"][f"param{i+1}"])
        return a

    def write_configs(self, index, val):
        self.config.read(self.file_path)
        self.config.set("DEFAULT", index, val)
        with open(self.file_path, "w") as config_file:
            self.config.write(config_file)
        self.param_pwm_motor1 = float(self.config["DEFAULT"]["param1"])
        self.param_pwm_motor2 = float(self.config["DEFAULT"]["param2"])
        self.param_pwm_motor3 = float(self.config["DEFAULT"]["param3"])
        self.param_pwm_motor4 = float(self.config["DEFAULT"]["param4"])
        self.param_pwm_motor5 = float(self.config["DEFAULT"]["param5"])
        self.assis_shoot[int(str(index)[-1]) - 1] = 0


def main():
    rclpy.init()

    sub = CommandRabbit()
    rclpy.spin(sub)

    rclpy.shutdown()


if __name__ == "__main__":
    main()
