cmake_minimum_required(VERSION 3.5)
project(RobotStrategySelect)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(AMRRobotStrategy)
add_subdirectory(AMMRRobotStrategy)
add_subdirectory(AGVRobotStrategy)
add_subdirectory(RobotStrategy)

add_library(${PROJECT_NAME} SHARED RobotStrategySelect.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC AGVRobotStrategy AMMRRobotStrategy AMRRobotStrategy RobotStrategy)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})