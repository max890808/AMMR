cmake_minimum_required(VERSION 3.5)
project(testing)

include_directories(${CMAKE_SOURCE_DIR})

if(CATKIN_ENABLE_TESTING)
find_package(rostest REQUIRED)
catkin_add_gtest(${PROJECT_NAME} testing.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} Test)
endif()