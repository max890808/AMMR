# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build

# Utility rule file for _run_tests_testing.

# Include the progress variables for this target.
include AMMR/test/CMakeFiles/_run_tests_testing.dir/progress.make

_run_tests_testing: AMMR/test/CMakeFiles/_run_tests_testing.dir/build.make

.PHONY : _run_tests_testing

# Rule to build all files generated by this target.
AMMR/test/CMakeFiles/_run_tests_testing.dir/build: _run_tests_testing

.PHONY : AMMR/test/CMakeFiles/_run_tests_testing.dir/build

AMMR/test/CMakeFiles/_run_tests_testing.dir/clean:
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/test && $(CMAKE_COMMAND) -P CMakeFiles/_run_tests_testing.dir/cmake_clean.cmake
.PHONY : AMMR/test/CMakeFiles/_run_tests_testing.dir/clean

AMMR/test/CMakeFiles/_run_tests_testing.dir/depend:
	cd /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src /home/aiRobots/aiRobots/aiRobots_AMMR/Software/src/AMMR/test /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/test /home/aiRobots/aiRobots/aiRobots_AMMR/Software/build/AMMR/test/CMakeFiles/_run_tests_testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : AMMR/test/CMakeFiles/_run_tests_testing.dir/depend

