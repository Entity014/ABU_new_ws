import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.join(
        get_package_share_directory("rabbit_package"), "config", "params.yaml"
    )

    node_microros = Node(
        package="micro_ros_agent",
        executable="micro_ros_agent",
        output="screen",
        arguments=["serial", "--dev", "/dev/ttyACM0"],
    )
    node_drive = Node(
        package="rabbit_package", executable="drive_node", parameters=[config]
    )
    node_controller = Node(
        package="rabbit_package", executable="controller_node", parameters=[config]
    )
    node_command = Node(
        package="rabbit_package", executable="command_node", parameters=[config]
    )
    node_joy = Node(package="joy", executable="joy_node")
    node_joyCon = Node(package="rabbit_package", executable="joyCon_node")
    node_terminal = Node(package="rabbit_package", executable="terminal_node")
    node_camera = Node(package="rabbit_package", executable="camera_node")

    ld.add_action(node_microros)
    ld.add_action(node_joy)
    ld.add_action(node_joyCon)
    ld.add_action(node_controller)
    ld.add_action(node_drive)
    ld.add_action(node_command)
    ld.add_action(node_terminal)
    # ld.add_action(node_camera)

    return ld
