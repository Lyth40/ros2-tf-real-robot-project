cmake_minimum_required(VERSION 3.8)
project(ros2_tf_project)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(my_robot_interfaces REQUIRED)
find_package(OpenCV REQUIRED)


add_executable(feature_detector src/feature_detector.cpp)
add_executable(simple_trajectory_service  src/simple_trajectory_service.cpp)
add_executable(simple_navigation_action_server  src/simple_navigation_action_server.cpp)

ament_target_dependencies(feature_detector OpenCV rclcpp sensor_msgs geometry_msgs tf2 tf2_ros yaml-cpp tf2_geometry_msgs
 my_robot_interfaces)

ament_target_dependencies(simple_trajectory_service OpenCV rclcpp sensor_msgs geometry_msgs tf2 tf2_ros yaml-cpp tf2_geometry_msgs
 my_robot_interfaces )

 ament_target_dependencies(simple_navigation_action_server rclcpp rclcpp_action tf2 tf2_ros geometry_msgs  tf2_geometry_msgs my_robot_interfaces )

target_link_libraries(feature_detector yaml-cpp)
target_link_libraries(simple_trajectory_service yaml-cpp)

install(TARGETS feature_detector DESTINATION lib/${PROJECT_NAME})
install(TARGETS simple_trajectory_service DESTINATION lib/${PROJECT_NAME})
install(TARGETS simple_navigation_action_server DESTINATION lib/${PROJECT_NAME})
install(
  DIRECTORY frames launch rviz
  DESTINATION share/${PROJECT_NAME}/
)



ament_package()
