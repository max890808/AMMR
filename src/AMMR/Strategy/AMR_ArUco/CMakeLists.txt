cmake_minimum_required(VERSION 3.5)
project(AMR_ArUco)
include_directories(${CMAKE_SOURCE_DIR})

find_package(catkin REQUIRED tf2_ros)

add_library(AMR_ArUco SHARED AMR_ArUco.cpp)
target_link_libraries(AMR_ArUco AMMR ${catkin_LIBRARIES})