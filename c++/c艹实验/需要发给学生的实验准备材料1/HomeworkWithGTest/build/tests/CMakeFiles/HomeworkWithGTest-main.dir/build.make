# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\VSCodeProjects\C++Course\HomeworkWithGTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\VSCodeProjects\C++Course\HomeworkWithGTest\build

# Include any dependencies generated for this target.
include tests/CMakeFiles/HomeworkWithGTest-main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/HomeworkWithGTest-main.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/HomeworkWithGTest-main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/HomeworkWithGTest-main.dir/flags.make

tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj: tests/CMakeFiles/HomeworkWithGTest-main.dir/flags.make
tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj: tests/CMakeFiles/HomeworkWithGTest-main.dir/includes_CXX.rsp
tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj: D:/VSCodeProjects/C++Course/HomeworkWithGTest/tests/test.cpp
tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj: tests/CMakeFiles/HomeworkWithGTest-main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj -MF CMakeFiles\HomeworkWithGTest-main.dir\test.cpp.obj.d -o CMakeFiles\HomeworkWithGTest-main.dir\test.cpp.obj -c D:\VSCodeProjects\C++Course\HomeworkWithGTest\tests\test.cpp

tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.i"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\VSCodeProjects\C++Course\HomeworkWithGTest\tests\test.cpp > CMakeFiles\HomeworkWithGTest-main.dir\test.cpp.i

tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.s"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\VSCodeProjects\C++Course\HomeworkWithGTest\tests\test.cpp -o CMakeFiles\HomeworkWithGTest-main.dir\test.cpp.s

# Object files for target HomeworkWithGTest-main
HomeworkWithGTest__main_OBJECTS = \
"CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj"

# External object files for target HomeworkWithGTest-main
HomeworkWithGTest__main_EXTERNAL_OBJECTS =

D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: tests/CMakeFiles/HomeworkWithGTest-main.dir/test.cpp.obj
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: tests/CMakeFiles/HomeworkWithGTest-main.dir/build.make
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/libHomeworkWithGTest.a
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: lib/libgtest_main.a
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: lib/libgtest.a
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: tests/CMakeFiles/HomeworkWithGTest-main.dir/linklibs.rsp
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: tests/CMakeFiles/HomeworkWithGTest-main.dir/objects1.rsp
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe: tests/CMakeFiles/HomeworkWithGTest-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D:\VSCodeProjects\C++Course\HomeworkWithGTest\bin\HomeworkWithGTest-main.exe"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HomeworkWithGTest-main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/HomeworkWithGTest-main.dir/build: D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/HomeworkWithGTest-main.exe
.PHONY : tests/CMakeFiles/HomeworkWithGTest-main.dir/build

tests/CMakeFiles/HomeworkWithGTest-main.dir/clean:
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests && $(CMAKE_COMMAND) -P CMakeFiles\HomeworkWithGTest-main.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/HomeworkWithGTest-main.dir/clean

tests/CMakeFiles/HomeworkWithGTest-main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\VSCodeProjects\C++Course\HomeworkWithGTest D:\VSCodeProjects\C++Course\HomeworkWithGTest\tests D:\VSCodeProjects\C++Course\HomeworkWithGTest\build D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\tests\CMakeFiles\HomeworkWithGTest-main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/HomeworkWithGTest-main.dir/depend

