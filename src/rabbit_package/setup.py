from setuptools import setup

import os
from glob import glob

package_name = "rabbit_package"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name), glob("launch/*launch.py")),
        (os.path.join("share", package_name, "config"), glob("config/*.yaml")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="entity014",
    maintainer_email="phytes.narawit@gmail.com",
    description="TODO: Package description",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "joyCon_node = rabbit_package.joyConnection:main",
            "controller_node = rabbit_package.controller:main",
            "drive_node = rabbit_package.drive:main",
            "command_node = rabbit_package.command:main",
            "terminal_node = rabbit_package.terminal:main",
            "camera_node = rabbit_package.camera:main",
        ],
    },
)
