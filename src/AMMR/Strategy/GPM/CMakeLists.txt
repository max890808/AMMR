cmake_minimum_required(VERSION 3.5)
project(GPM)
include_directories(${CMAKE_SOURCE_DIR})

find_package(catkin REQUIRED)

add_library(GPM SHARED Targetpicking.cpp)
target_include_directories(GPM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GPM AMMR ${catkin_LIBRARIES})