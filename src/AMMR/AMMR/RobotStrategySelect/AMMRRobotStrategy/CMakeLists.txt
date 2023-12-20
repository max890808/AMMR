cmake_minimum_required(VERSION 3.5)
project(AMMRRobotStrategy)
include_directories(${PROJECT_SOURCE_DIR})

add_library(AMMRRobotStrategy SHARED AMMRRobotStrategy.cpp)
target_link_libraries(AMMRRobotStrategy PUBLIC RobotStrategy)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})