# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build

# Include any dependencies generated for this target.
include AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/depend.make

# Include the progress variables for this target.
include AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/progress.make

# Include the compile flags for this target's objects.
include AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/flags.make

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/flags.make
AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/AMMR/MotorUnion/MotorUnion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o"
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o -c /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/AMMR/MotorUnion/MotorUnion.cpp

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorUnion.dir/MotorUnion.cpp.i"
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/AMMR/MotorUnion/MotorUnion.cpp > CMakeFiles/MotorUnion.dir/MotorUnion.cpp.i

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorUnion.dir/MotorUnion.cpp.s"
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/AMMR/MotorUnion/MotorUnion.cpp -o CMakeFiles/MotorUnion.dir/MotorUnion.cpp.s

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.requires:

.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.requires

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.provides: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.requires
	$(MAKE) -f AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/build.make AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.provides.build
.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.provides

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.provides.build: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o


# Object files for target MotorUnion
MotorUnion_OBJECTS = \
"CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o"

# External object files for target MotorUnion
MotorUnion_EXTERNAL_OBJECTS =

/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o
/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/build.make
/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libDMotor.so
/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libDynamixelSdk.so
/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libmotor.so
/home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so"
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MotorUnion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/build: /home/aiRobots/aiRobots/aiRobots_AMMR/Software/devel/lib/libMotorUnion.so

.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/build

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/requires: AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/MotorUnion.cpp.o.requires

.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/requires

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/clean:
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion && $(CMAKE_COMMAND) -P CMakeFiles/MotorUnion.dir/cmake_clean.cmake
.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/clean

AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/depend:
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/AMMR/MotorUnion /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : AMMR/AMMR/MotorUnion/CMakeFiles/MotorUnion.dir/depend

