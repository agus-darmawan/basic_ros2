#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class CPPPubNode : public rclcpp::Node
{
public:
   CPPPubNode() : Node("cpp_pub_node") 
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("test_topic", 10); 
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&CPPPubNode::pub_msg, this)); 
    }

private:
    void pub_msg(){
        auto msg = example_interfaces::msg::String();
        msg.data = "Hello, world!";
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
        publisher_->publish(msg);

    }
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CPPPubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
