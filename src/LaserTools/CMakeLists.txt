cmake_minimum_required(VERSION 3.0.2)
project(laser_tools)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(LaserFilter src/LaserFilter/LaserFilter.cpp)
target_link_libraries(LaserFilter ${catkin_LIBRARIES})

