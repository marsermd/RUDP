cmake_minimum_required(VERSION 3.6)
project(RUDP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Core/UDP/Sockets/Socket.cpp src/Core/UDP/Sockets/Socket.h src/Core/UDP/IPTarget.cpp src/Core/UDP/IPTarget.h src/Core/UDP/Sockets/SocketBase.h)
add_executable(RUDP ${SOURCE_FILES})

add_compile_options("-include cstdint")