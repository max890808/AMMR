cmake_minimum_required(VERSION 3.5)
project(Gui)

# QT autogeneration setting
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "ui")

# Find Package
find_package(OpenCV)
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found.")
endif()
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Set source

set(GUI_SRC 
    src/Form_ControlPanel.cpp
    src/Form_Strategy.cpp
    src/Form_AMMR.cpp
    src/Form_AMR.cpp
    src/Form_Manipulator.cpp
    src/Form_VLSensor.cpp)
set(GUI_HEADER 
    include/Form_ControlPanel.h
    include/Form_Strategy.h
    include/Form_AMMR.h
    include/Form_AMR.h
    include/Form_Manipulator.h
    include/Form_VLSensor.h)
set(GUI_QRC
    resource/resource.qrc)

# Generate library
add_library(Gui SHARED ${GUI_SRC} ${GUI_HEADER} ${GUI_QRC})
target_link_libraries(Gui Qt5::Widgets Qt5::Core ${OpenCV_LIBS} AMMR)
target_include_directories(Gui PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)
