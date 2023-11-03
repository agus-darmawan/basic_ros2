#!/usr/bin/python3
import rclpy
from rclpy.node import Node

class PyTestNodeOOP(Node):
    def __init__(self):
        super().__init__('py_test_node_oop')
        self.get_logger().info('Hello ROS2 from Python')
        self.counter = 0
        self.create_timer(1, self.timer_callback)

    def timer_callback(self):
        self.counter += 1
        self.get_logger().info('Hello ROS2 from Python ' + str(self.counter))

def main(args=None):
    rclpy.init(args=args)
    node = PyTestNodeOOP()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()