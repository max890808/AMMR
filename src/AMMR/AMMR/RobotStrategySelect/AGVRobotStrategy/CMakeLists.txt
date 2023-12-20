cmake_minimum_required(VERSION 3.5)
project(AGVRobotStrategy)
include_directories(${PROJECT_SOURCE_DIR})

add_library(AGVRobotStrategy SHARED AGVRobotStrategy.cpp)
target_link_libraries(AGVRobotStrategy PUBLIC RobotStrategy)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})