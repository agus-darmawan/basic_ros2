#include "rclcpp/rclcpp.hpp" 

class CppTestNodeOOP : public rclcpp::Node {
    public:
        CppTestNodeOOP() : Node("cpp_test_node") {
            RCLCPP_INFO(this->get_logger(), "Hello, world!");
            timer_ = this->create_wall_timer(std::chrono::seconds(1), 
                                        std::bind(&CppTestNodeOOP::timer_callback, this));
        }
        

    private:
        int count_ = 0;
        void timer_callback() {
            RCLCPP_INFO(this->get_logger(), "Hello, world! %d", count_++);
        }
        rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv); // initialize ROS 2 communication
    auto node = std::make_shared<CppTestNodeOOP>(); // create a node
    rclcpp::spin(node); // spin the node
    rclcpp::shutdown(); // shutdown ROS 2 communication
    return 0;
}

