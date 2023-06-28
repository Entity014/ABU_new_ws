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

        self.declare_parameters(
            "",
            [
                ("team", None),
                ("boot.pwm", None),
                ("dec.pwm", None),
                ("boot.delay", None),
                ("boot.delayPre", None),
                ("dec.delay", None),
            ],
        )

        self.axes = {}
        self.buttons = {}
        self.joyState = False

        self.pwm = 0.0
        self.save_pwm = 0.0
        self.state = 0
        self.counter = 0

        self.assis_shoot = [0, 0, 0, 0, 0]

        self.prePwm = -1
        self.preShoot = -1
        self.preStateShot = -1
        self.stateShoot = 0

        self.preChangeType1 = -1
        self.preChangeType2 = -1
        self.changingTeam = False

        self.preBootShoot = -1
        self.oncePwm = False
        self.isPreBooted = False
        self.isBooted = False
        self.isDelayBoot = False
        self.delayPreBoot = (
            self.get_parameter("boot.delayPre").get_parameter_value().double_value
        )
        self.delayBoot = (
            self.get_parameter("boot.delay").get_parameter_value().double_value
        )
        self.booster_PWM = (
            self.get_parameter("boot.pwm").get_parameter_value().double_value
        )

        self.isDelayDec = False
        self.isDec = False
        self.delayDec = (
            self.get_parameter("dec.delay").get_parameter_value().double_value
        )
        self.decelerator_PWM = (
            self.get_parameter("dec.pwm").get_parameter_value().double_value
        )

        self.typeTeam = (
            self.get_parameter("team").get_parameter_value().string_value.upper()
        )
        self.file_path = f"{Path.home()}/config.ini"
        self.config = configparser.ConfigParser()
        self.config.read(self.file_path)
        self.param_pwm_motor1 = float(self.config[f"{self.typeTeam}"]["param1"])  # ใกล้
        self.param_pwm_motor2 = float(self.config[f"{self.typeTeam}"]["param2"])  # กลาง
        self.param_pwm_motor3 = float(
            self.config[f"{self.typeTeam}"]["param3"]
        )  # ฝั่งตรงข้าม
        self.param_pwm_motor4 = float(
            self.config[f"{self.typeTeam}"]["param4"]
        )  # ใกล้ช้าง
        self.param_pwm_motor5 = float(
            self.config[f"{self.typeTeam}"]["param5"]
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
            if self.preStateShot != self.buttons["O"]:
                self.preStateShot = self.buttons["O"]
                if self.preStateShot == 1:
                    if self.stateShoot == 1:
                        self.prePwm = self.pwm
                        self.oncePwm = True
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

            # //------------------------------------------------------------------------------------------------//
            if self.stateShoot == 0:
                msg.linear.x = 0.0
            elif self.stateShoot == 1:
                if self.preBootShoot != self.buttons["R1"] and self.pwm >= 180.0:
                    self.preBootShoot = self.buttons["R1"]
                    if self.preBootShoot == 1:
                        self.isPreBooted = True
                        self.isBooted = True
                if self.oncePwm:
                    self.oncePwm = False
                    if self.prePwm < self.pwm:
                        self.isBooted = True
                    elif self.prePwm > self.pwm:
                        self.isDec = True
                if self.isBooted:
                    self.bootPwm()
                elif self.isDec:
                    self.decPwm()
                msg.linear.x = self.pwm
            elif self.stateShoot == 2:
                self.stateShoot = 0

            # //------------------------------------------------------------------------------------------------//
            if (
                self.preChangeType1 != self.buttons["R1"]
                and self.preChangeType2 != self.buttons["R2"]
            ):
                self.preChangeType1 = self.buttons["R1"]
                self.preChangeType2 = self.buttons["R2"]
                if self.preChangeType1 == 1 and self.preChangeType2 == 1:
                    if self.typeTeam == "BLUE":
                        self.typeTeam = "RED"
                    else:
                        self.typeTeam = "BLUE"
                    self.changingTeam = True
                    self.changePwmTeam()
                else:
                    self.changingTeam = False
            if (self.buttons["L2"] == 1) and (self.buttons["R2"] == 1):
                self.assis_shoot[self.state] = 0
            elif self.buttons["L2"] == 1 and not self.changingTeam:
                self.assis_shoot[self.state] += 0.5
            elif self.buttons["R2"] == 1 and not self.changingTeam:
                self.assis_shoot[self.state] -= 0.5

            # //------------------------------------------------------------------------------------------------//
            if self.buttons["T"] == 1:
                msg.angular.x = 1.0
            if self.buttons["L1"] == 1:
                msg.angular.y = 10.0
            if self.buttons["S"] == 1:
                msg.angular.y = 20.0
            if self.buttons["R1"] == 1 and not self.changingTeam:
                msg.angular.z = 999.0

            # //------------------------------------------------------------------------------------------------//
            self.save_pwm = msg.linear.x

        except KeyError:
            pass

        # self.get_logger().info(f"{self.isBooted} {self.isPreBooted}")
        self.sent_command.publish(msg)

    def send_data_gui_callback(self):
        msg = RabPwm()
        msg.type_team = self.typeTeam
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
            a[f"param{i+1}"] = float(self.config[f"{self.typeTeam}"][f"param{i+1}"])
        return a

    def write_configs(self, index, val):
        self.config.read(self.file_path)
        self.config.set(f"{self.typeTeam}", index, val)
        with open(self.file_path, "w") as config_file:
            self.config.write(config_file)
        self.param_pwm_motor1 = float(self.config[f"{self.typeTeam}"]["param1"])
        self.param_pwm_motor2 = float(self.config[f"{self.typeTeam}"]["param2"])
        self.param_pwm_motor3 = float(self.config[f"{self.typeTeam}"]["param3"])
        self.param_pwm_motor4 = float(self.config[f"{self.typeTeam}"]["param4"])
        self.param_pwm_motor5 = float(self.config[f"{self.typeTeam}"]["param5"])
        self.assis_shoot[int(str(index)[-1]) - 1] = 0

    def changePwmTeam(self):
        self.param_pwm_motor1 = float(self.config[f"{self.typeTeam}"]["param1"])  # ใกล้
        self.param_pwm_motor2 = float(self.config[f"{self.typeTeam}"]["param2"])  # กลาง
        self.param_pwm_motor3 = float(
            self.config[f"{self.typeTeam}"]["param3"]
        )  # ฝั่งตรงข้าม
        self.param_pwm_motor4 = float(
            self.config[f"{self.typeTeam}"]["param4"]
        )  # ใกล้ช้าง
        self.param_pwm_motor5 = float(
            self.config[f"{self.typeTeam}"]["param5"]
        )  # ฝั่งตรงข้ามไกล

    def bootPwm(self):
        if not self.isDelayBoot:
            self.isDelayBoot = True
            self.startTimeBoot = self.get_clock().now()

        current_time = self.get_clock().now()
        elapsed_time = (current_time - self.startTimeBoot).nanoseconds / 1e9
        if not self.isPreBooted:
            self.pwm = self.booster_PWM

        if elapsed_time >= self.delayPreBoot and self.isPreBooted:
            self.isDelayBoot = False
            self.isPreBooted = False
        elif elapsed_time >= self.delayBoot and not self.isPreBooted:
            self.isDelayBoot = False
            self.isBooted = False

    def decPwm(self):
        if not self.isDelayDec:
            self.isDelayDec = True
            self.startTimeDec = self.get_clock().now()

        current_time = self.get_clock().now()
        elapsed_time = (current_time - self.startTimeDec).nanoseconds / 1e9
        self.pwm = self.decelerator_PWM

        if elapsed_time >= self.delayBoot:
            self.isDelayDec = False
            self.isDec = False


def main():
    rclpy.init()

    sub = CommandRabbit()
    rclpy.spin(sub)

    rclpy.shutdown()


if __name__ == "__main__":
    main()
