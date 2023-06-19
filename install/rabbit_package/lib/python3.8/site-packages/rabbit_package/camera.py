import rclpy
import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from rclpy import qos


class ImagePublisher(Node):
    def __init__(self):
        super().__init__("camera_rabbit_node")
        self.publisher_ = self.create_publisher(
            Image, "color_image_topic", qos_profile=qos.qos_profile_system_default
        )
        self.timer = self.create_timer(0.01, self.timer_callback)

        self.cap = cv2.VideoCapture(0)
        self.width_frame, self.height_frame = (600, 1024)
        # self.cap = nano.Camera(width=1024, height=600, fps=30)
        # self.cap = cv2.VideoCapture(0)
        # self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.width_frame)
        # self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.height_frame)
        self.br = CvBridge()

    def timer_callback(self):
        ret, frame = self.cap.read()
        frame = cv2.resize(frame, (self.height_frame, self.width_frame))
        frame = cv2.flip(frame, 1)
        if ret == True:
            self.publisher_.publish(self.br.cv2_to_imgmsg(frame))
            if cv2.waitKey(1) & 0xFF == ord("q"):
                cv2.destroyAllWindows()
                exit()


def main(args=None):
    rclpy.init(args=args)
    image_publisher = ImagePublisher()
    rclpy.spin(image_publisher)
    image_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
