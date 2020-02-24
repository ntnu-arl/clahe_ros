cmake_minimum_required(VERSION 2.8.3)
project(clahe_ros)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV 3 REQUIRED COMPONENTS core highgui)

catkin_package(
 CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS}  ${OpenCV_INCLUDE_DIRS} ${OpenCV_LIBRARIES})

add_executable(clahe_ros_node src/clahe_ros_node.cpp src/clahe_ros.cpp)
target_link_libraries(clahe_ros_node ${OpenCV_LIBRARIES} ${OpenCV_INCLUDE_DIRS} ${catkin_LIBRARIES})