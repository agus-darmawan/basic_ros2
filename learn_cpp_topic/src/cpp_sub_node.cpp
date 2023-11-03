#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class CPPSubNode : public rclcpp::Node
{
public:
   CPPSubNode() : Node("cpp_pub_node") 
    {
        subscription_ = this->create_subscription<example_interfaces::msg::String>("test_topic", 10, 
                        std::bind(&CPPSubNode::sub_msg, this, std::placeholders::_1)); 
        RCLCPP_INFO(this->get_logger(), "Subscribed to test_topic");        
    }

private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscription_;
    void sub_msg(const example_interfaces::msg::String::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
    }

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CPPSubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
