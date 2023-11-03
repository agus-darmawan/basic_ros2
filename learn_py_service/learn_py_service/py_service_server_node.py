#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class PySrvServerNode(Node):
    def __init__(self):
        super().__init__('py_srv_server_node')
        self.get_logger().info('ROS2 Python Service Server Node has been started')
        self.server = self.create_service(
                    AddTwoInts, 'py_srv_server', self.srv_callback)
    
    def srv_callback(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        self.get_logger().info('Sending back response: %d' % response.sum)
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = PySrvServerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()