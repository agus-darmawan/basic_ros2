#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class PySubNode(Node):
    def __init__(self):
        super().__init__('py_sub_node')
        self.get_logger().info('ROS2 Python Subscriber Node has been started')
        self.str_sub = self.create_subscription(String, 'py_pub_topic', self.sub_msg, 10)
    
    def sub_msg(self, msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = PySubNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()