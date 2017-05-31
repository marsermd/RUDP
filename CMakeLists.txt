cmake_minimum_required(VERSION 3.6)
project(RUDP)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

include_directories("src")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/Core/UDP/Sockets/Socket.cpp
        src/Core/UDP/Sockets/Socket.h
        src/Core/UDP/IPTarget.cpp
        src/Core/UDP/IPTarget.h
        src/Core/UDP/Sockets/SocketBase.h
        src/Core/UDP/Connection/Unreliable/UDPConnection.h
        src/Core/UDP/Connection/Reliability/ReliableConnection.h
        src/Core/UDP/Connection/Base/ConnectionBase.h
        src/Messages/ReliableMessage.pb.cc
        src/Messages/ReliableMessage.pb.h
        src/Messages/StringMessage.pb.cc
        src/Messages/StringMessage.pb.h)
add_executable(RUDP ${SOURCE_FILES})

add_compile_options("-include cstdint")


target_link_libraries(RUDP
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${PROTOBUF_LIBRARY})