cmake_minimum_required(VERSION 3.5)
project(ControlInterface)

find_package(catkin REQUIRED)
find_package(Eigen3 REQUIRED)

add_subdirectory(MoveBaseClient)

add_library(${PROJECT_NAME} SHARED ControlInterface.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${EIGEN3_LIBS} MoveBaseClient)
target_include_directories(${PROJECT_NAME} PUBLIC ${EIGEN3_INCLUDE_DIR})