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
CMAKE_COMMAND = /usr/local/jetbrains/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/jetbrains/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cs/usr/shaked.weitz/ClionProjects/cppex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex3.dir/flags.make

CMakeFiles/ex3.dir/my_set_tester.cpp.o: CMakeFiles/ex3.dir/flags.make
CMakeFiles/ex3.dir/my_set_tester.cpp.o: ../my_set_tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex3.dir/my_set_tester.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex3.dir/my_set_tester.cpp.o -c /cs/usr/shaked.weitz/ClionProjects/cppex3/my_set_tester.cpp

CMakeFiles/ex3.dir/my_set_tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3.dir/my_set_tester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/usr/shaked.weitz/ClionProjects/cppex3/my_set_tester.cpp > CMakeFiles/ex3.dir/my_set_tester.cpp.i

CMakeFiles/ex3.dir/my_set_tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3.dir/my_set_tester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/usr/shaked.weitz/ClionProjects/cppex3/my_set_tester.cpp -o CMakeFiles/ex3.dir/my_set_tester.cpp.s

CMakeFiles/ex3.dir/my_set_tester.cpp.o.requires:

.PHONY : CMakeFiles/ex3.dir/my_set_tester.cpp.o.requires

CMakeFiles/ex3.dir/my_set_tester.cpp.o.provides: CMakeFiles/ex3.dir/my_set_tester.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/my_set_tester.cpp.o.provides.build
.PHONY : CMakeFiles/ex3.dir/my_set_tester.cpp.o.provides

CMakeFiles/ex3.dir/my_set_tester.cpp.o.provides.build: CMakeFiles/ex3.dir/my_set_tester.cpp.o


# Object files for target ex3
ex3_OBJECTS = \
"CMakeFiles/ex3.dir/my_set_tester.cpp.o"

# External object files for target ex3
ex3_EXTERNAL_OBJECTS =

ex3: CMakeFiles/ex3.dir/my_set_tester.cpp.o
ex3: CMakeFiles/ex3.dir/build.make
ex3: CMakeFiles/ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex3.dir/build: ex3

.PHONY : CMakeFiles/ex3.dir/build

CMakeFiles/ex3.dir/requires: CMakeFiles/ex3.dir/my_set_tester.cpp.o.requires

.PHONY : CMakeFiles/ex3.dir/requires

CMakeFiles/ex3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex3.dir/clean

CMakeFiles/ex3.dir/depend:
	cd /cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cs/usr/shaked.weitz/ClionProjects/cppex3 /cs/usr/shaked.weitz/ClionProjects/cppex3 /cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug /cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug /cs/usr/shaked.weitz/ClionProjects/cppex3/cmake-build-debug/CMakeFiles/ex3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex3.dir/depend

