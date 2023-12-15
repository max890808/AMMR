# Install script for directory: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr/ROS/srv" TYPE FILE FILES
    "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Yolo.srv"
    "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/srv/Job.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr/ROS/msg" TYPE FILE FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/ROS/msg/status.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr/cmake" TYPE FILE FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/catkin_generated/installspace/airobots_ammr-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/include/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/share/roseus/ros/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/share/common-lisp/ros/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/share/gennodejs/ros/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/python2.7/dist-packages/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/python2.7/dist-packages/airobots_ammr")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/catkin_generated/installspace/airobots_ammr.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr/cmake" TYPE FILE FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/catkin_generated/installspace/airobots_ammr-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr/cmake" TYPE FILE FILES
    "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/catkin_generated/installspace/airobots_ammrConfig.cmake"
    "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/catkin_generated/installspace/airobots_ammrConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/airobots_ammr" TYPE FILE FILES "/home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/Gui/cmake_install.cmake")
  include("/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/cmake_install.cmake")
  include("/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/Strategy/cmake_install.cmake")

endif()

