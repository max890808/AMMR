cmake_minimum_required(VERSION 3.5)
project(LiDARGetter)

find_package(OpenCV)
if(NOT OpenCV_FOUND)
	message(FATAL_ERROR "OpenCV not found.")
endif()

find_package(catkin REQUIRED COMPONENTS nodelet)
find_package(Eigen3 REQUIRED)

add_library(LiDARGetter SHARED LiDARGetter.cpp)
target_link_libraries(LiDARGetter ${catkin_LIBRARIES} ${EIGEN3_LIBS} ${OpenCV_LIBS})
target_include_directories(LiDARGetter PUBLIC ${catkin_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR})