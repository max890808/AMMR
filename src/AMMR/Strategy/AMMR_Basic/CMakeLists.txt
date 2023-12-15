cmake_minimum_required(VERSION 3.5)
project(AMMR_Basic)
include_directories(${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED AMMR_Basic.cpp)
target_link_libraries(${PROJECT_NAME} AMMR)