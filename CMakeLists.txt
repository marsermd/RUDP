cmake_minimum_required(VERSION 3.6)
project(RUDP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Core/UDP/Socket.cpp Core/UDP/Socket.h Core/UDP/IPTarget.cpp Core/UDP/IPTarget.h)
add_executable(RUDP ${SOURCE_FILES})

add_compile_options("-include cstdint")