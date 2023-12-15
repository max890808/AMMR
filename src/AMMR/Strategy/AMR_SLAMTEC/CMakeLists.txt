cmake_minimum_required(VERSION 3.5)
project(AMR_SLAMTEC)
include_directories(${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED AMR_SLAMTEC.cpp)
target_link_libraries(${PROJECT_NAME} AMMR)