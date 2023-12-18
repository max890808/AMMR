cmake_minimum_required(VERSION 3.5)
project(Test)
include_directories(${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED Test.cpp)

target_link_libraries(${PROJECT_NAME} AMMR)
