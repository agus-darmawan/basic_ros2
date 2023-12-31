cmake_minimum_required(VERSION 3.8)
project(learn_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(cpp_node src/cpp_test_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(cpp_node_oop src/cpp_test_node_oop.cpp)
ament_target_dependencies(cpp_node_oop rclcpp)

INSTALL(TARGETS
  cpp_node
  DESTINATION lib/${PROJECT_NAME}
)

INSTALL(TARGETS
  cpp_node_oop
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
