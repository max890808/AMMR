cmake_minimum_required(VERSION 3.5)
project(Manipulator)

find_package(Poco REQUIRED Foundation Net) 
set(POCO_LIBS Poco::Net Poco::Foundation)

add_library(Manipulator SHARED Manipulator.cpp)
target_link_libraries(Manipulator MotorUnion ${POCO_LIBS})