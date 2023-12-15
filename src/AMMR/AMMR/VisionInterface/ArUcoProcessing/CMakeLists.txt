cmake_minimum_required(VERSION 3.5)
project(ArUcoProcessing)

find_package(OpenCV)
if(NOT OpenCV_FOUND)
	message(FATAL_ERROR "OpenCV not found.")
endif()

find_package(OpenCV COMPONENTS aruco)
if(NOT OpenCV_aruco_FOUND)
	message(WARNING "ArUco library not found. Maybe forget to install opencv contrib")
else()
	message("" "ArUco library detected. Build ArUco support for vision")
	set(${PROJECT_NAME}_FOUND True PARENT_SCOPE)
	# ArUcoProcessing
	add_library(${PROJECT_NAME} SHARED ArUcoProcessing.cpp)
	target_link_libraries(${PROJECT_NAME}
		${OpenCV_LIBS}
	)
endif()
