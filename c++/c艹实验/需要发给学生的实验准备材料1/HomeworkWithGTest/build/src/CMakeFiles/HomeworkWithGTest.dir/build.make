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
include src/CMakeFiles/HomeworkWithGTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/HomeworkWithGTest.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/HomeworkWithGTest.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/HomeworkWithGTest.dir/flags.make

src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj: src/CMakeFiles/HomeworkWithGTest.dir/flags.make
src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj: src/CMakeFiles/HomeworkWithGTest.dir/includes_CXX.rsp
src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj: D:/VSCodeProjects/C++Course/HomeworkWithGTest/src/ch4_homework/MyArray.cpp
src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj: src/CMakeFiles/HomeworkWithGTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj -MF CMakeFiles\HomeworkWithGTest.dir\ch4_homework\MyArray.cpp.obj.d -o CMakeFiles\HomeworkWithGTest.dir\ch4_homework\MyArray.cpp.obj -c D:\VSCodeProjects\C++Course\HomeworkWithGTest\src\ch4_homework\MyArray.cpp

src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.i"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\VSCodeProjects\C++Course\HomeworkWithGTest\src\ch4_homework\MyArray.cpp > CMakeFiles\HomeworkWithGTest.dir\ch4_homework\MyArray.cpp.i

src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.s"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\VSCodeProjects\C++Course\HomeworkWithGTest\src\ch4_homework\MyArray.cpp -o CMakeFiles\HomeworkWithGTest.dir\ch4_homework\MyArray.cpp.s

# Object files for target HomeworkWithGTest
HomeworkWithGTest_OBJECTS = \
"CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj"

# External object files for target HomeworkWithGTest
HomeworkWithGTest_EXTERNAL_OBJECTS =

D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/libHomeworkWithGTest.a: src/CMakeFiles/HomeworkWithGTest.dir/ch4_homework/MyArray.cpp.obj
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/libHomeworkWithGTest.a: src/CMakeFiles/HomeworkWithGTest.dir/build.make
D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/libHomeworkWithGTest.a: src/CMakeFiles/HomeworkWithGTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library D:\VSCodeProjects\C++Course\HomeworkWithGTest\bin\libHomeworkWithGTest.a"
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && $(CMAKE_COMMAND) -P CMakeFiles\HomeworkWithGTest.dir\cmake_clean_target.cmake
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HomeworkWithGTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/HomeworkWithGTest.dir/build: D:/VSCodeProjects/C++Course/HomeworkWithGTest/bin/libHomeworkWithGTest.a
.PHONY : src/CMakeFiles/HomeworkWithGTest.dir/build

src/CMakeFiles/HomeworkWithGTest.dir/clean:
	cd /d D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src && $(CMAKE_COMMAND) -P CMakeFiles\HomeworkWithGTest.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/HomeworkWithGTest.dir/clean

src/CMakeFiles/HomeworkWithGTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\VSCodeProjects\C++Course\HomeworkWithGTest D:\VSCodeProjects\C++Course\HomeworkWithGTest\src D:\VSCodeProjects\C++Course\HomeworkWithGTest\build D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src D:\VSCodeProjects\C++Course\HomeworkWithGTest\build\src\CMakeFiles\HomeworkWithGTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/HomeworkWithGTest.dir/depend

