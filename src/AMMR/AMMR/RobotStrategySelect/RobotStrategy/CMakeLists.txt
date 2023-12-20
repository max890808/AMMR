cmake_minimum_required(VERSION 3.5)
project(RobotStrategy)
include_directories(${PROJECT_SOURCE_DIR})

add_library(RobotStrategy SHARED RobotStrategy.cpp)
target_link_libraries(RobotStrategy PUBLIC AMR Manipulator ControlInterface)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})