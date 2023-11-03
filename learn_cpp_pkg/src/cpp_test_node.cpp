#include "rclcpp/rclcpp.hpp" 

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv); // initialize ROS 2 communication
    auto node = rclcpp::Node::make_shared("cpp_test_node"); // create a node
    RCLCPP_INFO(node->get_logger(), "Hello, world!"); // print a message to the screen
    rclcpp::spin(node); // spin the node
    rclcpp::shutdown(); // shutdown ROS 2 communication
    return 0;
}