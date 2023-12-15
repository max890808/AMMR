cmake_minimum_required(VERSION 3.5)
project(VisionInterface)

add_subdirectory(ImageGetter)

add_library(VisionInterface SHARED VisionInterface.cpp)
target_link_libraries(VisionInterface ImageGetter)


# Remove below if ArUco is not used
add_subdirectory(ArUcoProcessing)
if(ArUcoProcessing_FOUND)
   target_link_libraries(VisionInterface ArUcoProcessing)
else()
   message(WARNING "ArUco library not found. Maybe forget to install opencv contrib")
endif()