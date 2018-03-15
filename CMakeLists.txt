cmake_minimum_required(VERSION 3.5)
project(RUDP)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

include_directories("src")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/Core/UDP/Sockets/Socket.cpp
        src/Core/UDP/IPTarget.cpp
        src/Core/UDP/Sockets/SocketBase.h
        src/Core/UDP/Connection/Unreliable/UDPConnection.h
        src/Core/UDP/Connection/Reliability/ReliableConnection.h
        src/Core/UDP/Connection/Base/ConnectionBase.h
        src/Messages/ReliableMessage.pb.cc
        src/Messages/ReliableMessage.pb.h
        src/Messages/StringMessage.pb.cc
        src/Messages/StringMessage.pb.h
        src/Core/UDP/FakeSockets/FakeNetwork.cpp src/Core/UDP/FakeSockets/FakeMessage.cpp src/Core/UDP/FakeSockets/FakeMessage.h src/Core/UDP/FakeSockets/FakeSocket.cpp src/Core/UDP/FakeSockets/FakeSocket.h
        )
add_executable(RUDP ${SOURCE_FILES})

add_compile_options("-include cstdint")


target_link_libraries(RUDP
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${PROTOBUF_LIBRARY})