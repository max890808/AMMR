cmake_minimum_required(VERSION 3.5)
project(DynamixelSdk)

if (NOT TARGET DynamixelSdk)
    add_library(DynamixelSdk SHARED
    dynamixel_sdk/group_bulk_read.cpp
    dynamixel_sdk/group_bulk_write.cpp
    dynamixel_sdk/group_sync_read.cpp
    dynamixel_sdk/group_sync_write.cpp
    dynamixel_sdk/packet_handler.cpp
    dynamixel_sdk/port_handler.cpp
    dynamixel_sdk/packet_handler.cpp
    dynamixel_sdk/port_handler_linux.cpp
    dynamixel_sdk/port_handler.cpp
    dynamixel_sdk/protocol1_packet_handler.cpp
    dynamixel_sdk/protocol2_packet_handler.cpp
    )
endif()