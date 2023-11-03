#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class PyPubNode(Node):
    def __init__(self):
        super().__init__('py_pub_node')
        self.get_logger().info('ROS2 Python Publisher Node has been started')
        self.counter = 0
        self.str_pub = self.create_publisher(String, 'py_pub_topic', 10)
        self.create_timer(1, self.pub_msg)

    def pub_msg(self):
        msg = String()
        msg.data = "Hello ROS2 from Python " + str(self.counter)
        self.str_pub.publish(msg)
        self.counter += 1

def main(args=None):
    rclpy.init(args=args)
    node = PyPubNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()