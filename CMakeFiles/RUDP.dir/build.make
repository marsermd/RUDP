# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/natalya/Programs/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/natalya/Programs/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/natalya/Documents/os/RUDP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/natalya/Documents/os/RUDP

# Include any dependencies generated for this target.
include CMakeFiles/RUDP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RUDP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RUDP.dir/flags.make

CMakeFiles/RUDP.dir/src/main.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RUDP.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/main.cpp.o -c /home/natalya/Documents/os/RUDP/src/main.cpp

CMakeFiles/RUDP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/main.cpp > CMakeFiles/RUDP.dir/src/main.cpp.i

CMakeFiles/RUDP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/main.cpp -o CMakeFiles/RUDP.dir/src/main.cpp.s

CMakeFiles/RUDP.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/main.cpp.o.requires

CMakeFiles/RUDP.dir/src/main.cpp.o.provides: CMakeFiles/RUDP.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/main.cpp.o.provides

CMakeFiles/RUDP.dir/src/main.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/main.cpp.o


CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o: src/Core/UDP/Sockets/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o -c /home/natalya/Documents/os/RUDP/src/Core/UDP/Sockets/Socket.cpp

CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Core/UDP/Sockets/Socket.cpp > CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.i

CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Core/UDP/Sockets/Socket.cpp -o CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.s

CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.requires

CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.provides: CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.provides

CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o


CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o: src/Core/UDP/IPTarget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o -c /home/natalya/Documents/os/RUDP/src/Core/UDP/IPTarget.cpp

CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Core/UDP/IPTarget.cpp > CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.i

CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Core/UDP/IPTarget.cpp -o CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.s

CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.requires

CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.provides: CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.provides

CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o


CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o: src/Messages/ReliableMessage.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o -c /home/natalya/Documents/os/RUDP/src/Messages/ReliableMessage.pb.cc

CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Messages/ReliableMessage.pb.cc > CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.i

CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Messages/ReliableMessage.pb.cc -o CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.s

CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.requires

CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.provides: CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.provides

CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.provides.build: CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o


CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o: src/Messages/StringMessage.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o -c /home/natalya/Documents/os/RUDP/src/Messages/StringMessage.pb.cc

CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Messages/StringMessage.pb.cc > CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.i

CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Messages/StringMessage.pb.cc -o CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.s

CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.requires

CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.provides: CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.provides

CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.provides.build: CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o


CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o: src/Core/UDP/FakeSockets/FakeNetwork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o -c /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeNetwork.cpp

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeNetwork.cpp > CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.i

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeNetwork.cpp -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.s

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.requires

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.provides: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.provides

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o


CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o: src/Core/UDP/FakeSockets/FakeMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o -c /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeMessage.cpp

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeMessage.cpp > CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.i

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeMessage.cpp -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.s

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.requires

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.provides: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.provides

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o


CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o: CMakeFiles/RUDP.dir/flags.make
CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o: src/Core/UDP/FakeSockets/FakeSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o -c /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeSocket.cpp

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeSocket.cpp > CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.i

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/natalya/Documents/os/RUDP/src/Core/UDP/FakeSockets/FakeSocket.cpp -o CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.s

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.requires:

.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.requires

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.provides: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/RUDP.dir/build.make CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.provides.build
.PHONY : CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.provides

CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.provides.build: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o


# Object files for target RUDP
RUDP_OBJECTS = \
"CMakeFiles/RUDP.dir/src/main.cpp.o" \
"CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o" \
"CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o" \
"CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o" \
"CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o" \
"CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o" \
"CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o" \
"CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o"

# External object files for target RUDP
RUDP_EXTERNAL_OBJECTS =

RUDP: CMakeFiles/RUDP.dir/src/main.cpp.o
RUDP: CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o
RUDP: CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o
RUDP: CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o
RUDP: CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o
RUDP: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o
RUDP: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o
RUDP: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o
RUDP: CMakeFiles/RUDP.dir/build.make
RUDP: /usr/local/lib/libprotobuf.so
RUDP: CMakeFiles/RUDP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/natalya/Documents/os/RUDP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable RUDP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RUDP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RUDP.dir/build: RUDP

.PHONY : CMakeFiles/RUDP.dir/build

CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/main.cpp.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Core/UDP/Sockets/Socket.cpp.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Core/UDP/IPTarget.cpp.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Messages/ReliableMessage.pb.cc.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Messages/StringMessage.pb.cc.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeNetwork.cpp.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeMessage.cpp.o.requires
CMakeFiles/RUDP.dir/requires: CMakeFiles/RUDP.dir/src/Core/UDP/FakeSockets/FakeSocket.cpp.o.requires

.PHONY : CMakeFiles/RUDP.dir/requires

CMakeFiles/RUDP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RUDP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RUDP.dir/clean

CMakeFiles/RUDP.dir/depend:
	cd /home/natalya/Documents/os/RUDP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/natalya/Documents/os/RUDP /home/natalya/Documents/os/RUDP /home/natalya/Documents/os/RUDP /home/natalya/Documents/os/RUDP /home/natalya/Documents/os/RUDP/CMakeFiles/RUDP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RUDP.dir/depend
