cmake_minimum_required(VERSION 3.5)
project(AMMR)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(MotorUnion)
add_subdirectory(ControlInterface)
add_subdirectory(VisionInterface)
add_subdirectory(LiDARInterface)
add_subdirectory(AMR)
add_subdirectory(Manipulator)

add_library(${PROJECT_NAME} SHARED AMMR.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC AMR Manipulator ControlInterface VisionInterface LiDARInterface)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})