cmake_minimum_required(VERSION 3.5)
project(ImageGetter)

find_package(catkin REQUIRED COMPONENTS cv_bridge nodelet)

add_library(ImageGetter SHARED ImageGetter.cpp)
target_link_libraries(ImageGetter ${catkin_LIBRARIES})
target_include_directories(ImageGetter PUBLIC ${catkin_INCLUDE_DIRS})