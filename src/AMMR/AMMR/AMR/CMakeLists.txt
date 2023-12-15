cmake_minimum_required(VERSION 3.5)
project(AMR)

add_library(AMR SHARED AMR.cpp)
target_link_libraries(AMR MotorUnion)
