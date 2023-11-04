#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class CPPServiceClient : public rclcpp::Node
{
public:
    CPPServiceClient() : Node("add_two_ints_client")
    {
        threads_.push_back(std::thread(std::bind(&CPPServiceClient::callAddTwoIntsService, this, 1, 4)));
        threads_.push_back(std::thread(std::bind(&CPPServiceClient::callAddTwoIntsService, this, 4, 5)));
    }

    void callAddTwoIntsService(int a, int b)
    {
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("learn_service");
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the server to be up...");
        }

        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client->async_send_request(request);

        try
        {
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "%d + %d = %d", a, b, (int)response->sum);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }
    }

private:
    std::vector<std::thread> threads_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CPPServiceClient>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
