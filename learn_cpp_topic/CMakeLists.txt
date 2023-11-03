cmake_minimum_required(VERSION 3.8)
project(learn_cpp_topic)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(topic_publisher src/cpp_pub_node.cpp)
ament_target_dependencies(topic_publisher rclcpp example_interfaces)

INSTALL(TARGETS
  topic_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
