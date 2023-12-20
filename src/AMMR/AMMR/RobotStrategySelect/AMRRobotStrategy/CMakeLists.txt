cmake_minimum_required(VERSION 3.5)
project(AMRRobotStrategy)
include_directories(${PROJECT_SOURCE_DIR})

add_library(AMRRobotStrategy SHARED AMRRobotStrategy.cpp)
target_link_libraries(AMRRobotStrategy PUBLIC RobotStrategy)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})