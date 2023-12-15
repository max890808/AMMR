cmake_minimum_required(VERSION 3.5)
project(airobots_ammr)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_BUILD_TYPE Debug)

find_package(catkin REQUIRED COMPONENTS
  tf2_ros
  roscpp
  rospy
  std_msgs
  message_generation
  genmsg
)

add_service_files(
  DIRECTORY ROS/srv
  FILES
  Yolo.srv
  Job.srv
)

add_message_files(
  DIRECTORY ROS/msg
  FILES
  status.msg
) 

generate_messages(
  DEPENDENCIES 
  std_msgs
)

catkin_package()

include_directories(${PROJECT_SOURCE_DIR} ${catkin_INCLUDE_DIRS})

add_subdirectory(Gui)
add_subdirectory(AMMR)
add_subdirectory(Strategy)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} 
  Gui 
  AMMR
  Strategy 
  ${catkin_LIBRARIES}
)
