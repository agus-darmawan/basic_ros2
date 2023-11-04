cmake_minimum_required(VERSION 3.8)
project(learn_cpp_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(service_server src/cpp_service_server.cpp)
ament_target_dependencies(service_server rclcpp example_interfaces)

add_executable(service_client src/cpp_service_client.cpp)
ament_target_dependencies(service_client rclcpp example_interfaces)

add_executable(service_client_no_oop src/cpp_service_client_no_oop.cpp)
ament_target_dependencies(service_client_no_oop rclcpp example_interfaces)

install(TARGETS
  service_server
  service_client
  service_client_no_oop
  DESTINATION lib/${PROJECT_NAME})
  

ament_package()
