# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug

# Utility rule file for IMDAP_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/IMDAP_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IMDAP_autogen.dir/progress.make

CMakeFiles/IMDAP_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target IMDAP"
	/usr/local/Cellar/cmake/3.26.4/bin/cmake -E cmake_autogen /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles/IMDAP_autogen.dir/AutogenInfo.json Debug

IMDAP_autogen: CMakeFiles/IMDAP_autogen
IMDAP_autogen: CMakeFiles/IMDAP_autogen.dir/build.make
.PHONY : IMDAP_autogen

# Rule to build all files generated by this target.
CMakeFiles/IMDAP_autogen.dir/build: IMDAP_autogen
.PHONY : CMakeFiles/IMDAP_autogen.dir/build

CMakeFiles/IMDAP_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IMDAP_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IMDAP_autogen.dir/clean

CMakeFiles/IMDAP_autogen.dir/depend:
	cd /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles/IMDAP_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IMDAP_autogen.dir/depend
