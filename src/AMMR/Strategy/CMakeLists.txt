cmake_minimum_required(VERSION 3.5)
project(Strategy)
include_directories(${CMAKE_SOURCE_DIR})

add_library(Strategy SHARED Strategy.cpp)

# Add Your Strategy Below
add_subdirectory(AMR_ArUco)
add_subdirectory(AMR_Basic)
add_subdirectory(AMR_SLAMTEC)
add_subdirectory(AMMR_Basic)
add_subdirectory(GPM)
add_subdirectory(Test)

# Link Your Strategy Below
set(ALL_STRATEGES AMR_ArUco AMR_Basic AMMR_Basic AMR_SLAMTEC GPM Test) 
target_link_libraries(Strategy AMR_ArUco AMR_Basic AMMR_Basic AMR_SLAMTEC GPM Test)