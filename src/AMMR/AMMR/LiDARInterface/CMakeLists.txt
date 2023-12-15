cmake_minimum_required(VERSION 3.5)
project(LiDARInterface)

add_subdirectory(LiDARGetter)

add_library(LiDARInterface SHARED LiDARInterface.cpp)
target_link_libraries(LiDARInterface LiDARGetter)