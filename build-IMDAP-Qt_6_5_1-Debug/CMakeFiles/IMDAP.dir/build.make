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

# Include any dependencies generated for this target.
include CMakeFiles/IMDAP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IMDAP.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IMDAP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IMDAP.dir/flags.make

IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/icons.qrc
IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp: CMakeFiles/IMDAP_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json
IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/icons/pingjunzhi.png
IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/icons/wenjian.png
IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp: /opt/homebrew/share/qt/libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for icons.qrc"
	/usr/local/Cellar/cmake/3.26.4/bin/cmake -E cmake_autorcc /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles/IMDAP_autogen.dir/AutoRcc_icons_EWIEGA46WW_Info.json Debug

IMDAP_autogen/EWIEGA46WW/qrc_data.cpp: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/data.qrc
IMDAP_autogen/EWIEGA46WW/qrc_data.cpp: CMakeFiles/IMDAP_autogen.dir/AutoRcc_data_EWIEGA46WW_Info.json
IMDAP_autogen/EWIEGA46WW/qrc_data.cpp: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/data/breast-cancer.csv
IMDAP_autogen/EWIEGA46WW/qrc_data.cpp: /opt/homebrew/share/qt/libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for data.qrc"
	/usr/local/Cellar/cmake/3.26.4/bin/cmake -E cmake_autorcc /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles/IMDAP_autogen.dir/AutoRcc_data_EWIEGA46WW_Info.json Debug

CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o: IMDAP_autogen/mocs_compilation.cpp
CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o -MF CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/mocs_compilation.cpp

CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/mocs_compilation.cpp > CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.i

CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/mocs_compilation.cpp -o CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.s

CMakeFiles/IMDAP.dir/main.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/main.cpp.o: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/main.cpp
CMakeFiles/IMDAP.dir/main.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/IMDAP.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/main.cpp.o -MF CMakeFiles/IMDAP.dir/main.cpp.o.d -o CMakeFiles/IMDAP.dir/main.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/main.cpp

CMakeFiles/IMDAP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/main.cpp > CMakeFiles/IMDAP.dir/main.cpp.i

CMakeFiles/IMDAP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/main.cpp -o CMakeFiles/IMDAP.dir/main.cpp.s

CMakeFiles/IMDAP.dir/mainwindow.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/mainwindow.cpp.o: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/mainwindow.cpp
CMakeFiles/IMDAP.dir/mainwindow.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/IMDAP.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/mainwindow.cpp.o -MF CMakeFiles/IMDAP.dir/mainwindow.cpp.o.d -o CMakeFiles/IMDAP.dir/mainwindow.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/mainwindow.cpp

CMakeFiles/IMDAP.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/mainwindow.cpp > CMakeFiles/IMDAP.dir/mainwindow.cpp.i

CMakeFiles/IMDAP.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/mainwindow.cpp -o CMakeFiles/IMDAP.dir/mainwindow.cpp.s

CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o: /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/averageandmeandialog.cpp
CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o -MF CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o.d -o CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/averageandmeandialog.cpp

CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/averageandmeandialog.cpp > CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.i

CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP/averageandmeandialog.cpp -o CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.s

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o: IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp
CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o -MF CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o.d -o CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp > CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.i

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp -o CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.s

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o: CMakeFiles/IMDAP.dir/flags.make
CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o: IMDAP_autogen/EWIEGA46WW/qrc_data.cpp
CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o: CMakeFiles/IMDAP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o -MF CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o.d -o CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o -c /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp > CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.i

CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp -o CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.s

# Object files for target IMDAP
IMDAP_OBJECTS = \
"CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/IMDAP.dir/main.cpp.o" \
"CMakeFiles/IMDAP.dir/mainwindow.cpp.o" \
"CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o" \
"CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o" \
"CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o"

# External object files for target IMDAP
IMDAP_EXTERNAL_OBJECTS =

IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/IMDAP_autogen/mocs_compilation.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/main.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/mainwindow.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/averageandmeandialog.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/IMDAP_autogen/EWIEGA46WW/qrc_data.cpp.o
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/build.make
IMDAP.app/Contents/MacOS/IMDAP: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
IMDAP.app/Contents/MacOS/IMDAP: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
IMDAP.app/Contents/MacOS/IMDAP: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
IMDAP.app/Contents/MacOS/IMDAP: CMakeFiles/IMDAP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable IMDAP.app/Contents/MacOS/IMDAP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IMDAP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IMDAP.dir/build: IMDAP.app/Contents/MacOS/IMDAP
.PHONY : CMakeFiles/IMDAP.dir/build

CMakeFiles/IMDAP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IMDAP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IMDAP.dir/clean

CMakeFiles/IMDAP.dir/depend: IMDAP_autogen/EWIEGA46WW/qrc_data.cpp
CMakeFiles/IMDAP.dir/depend: IMDAP_autogen/EWIEGA46WW/qrc_icons.cpp
	cd /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP /Users/suxingjian/Documents/GitHub/IMDAP/IMDAP /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug /Users/suxingjian/Documents/GitHub/IMDAP/build-IMDAP-Qt_6_5_1-Debug/CMakeFiles/IMDAP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IMDAP.dir/depend

