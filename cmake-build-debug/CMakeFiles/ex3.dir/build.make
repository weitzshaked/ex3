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
CMAKE_COMMAND = /cygdrive/c/Users/weitz/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/weitz/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/weitz/Desktop/ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex3.dir/flags.make

CMakeFiles/ex3.dir/my_set.cpp.o: CMakeFiles/ex3.dir/flags.make
CMakeFiles/ex3.dir/my_set.cpp.o: ../my_set.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex3.dir/my_set.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex3.dir/my_set.cpp.o -c /cygdrive/c/Users/weitz/Desktop/ex3/my_set.cpp

CMakeFiles/ex3.dir/my_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3.dir/my_set.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/weitz/Desktop/ex3/my_set.cpp > CMakeFiles/ex3.dir/my_set.cpp.i

CMakeFiles/ex3.dir/my_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3.dir/my_set.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/weitz/Desktop/ex3/my_set.cpp -o CMakeFiles/ex3.dir/my_set.cpp.s

CMakeFiles/ex3.dir/my_set.cpp.o.requires:

.PHONY : CMakeFiles/ex3.dir/my_set.cpp.o.requires

CMakeFiles/ex3.dir/my_set.cpp.o.provides: CMakeFiles/ex3.dir/my_set.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/my_set.cpp.o.provides.build
.PHONY : CMakeFiles/ex3.dir/my_set.cpp.o.provides

CMakeFiles/ex3.dir/my_set.cpp.o.provides.build: CMakeFiles/ex3.dir/my_set.cpp.o


# Object files for target ex3
ex3_OBJECTS = \
"CMakeFiles/ex3.dir/my_set.cpp.o"

# External object files for target ex3
ex3_EXTERNAL_OBJECTS =

ex3.exe: CMakeFiles/ex3.dir/my_set.cpp.o
ex3.exe: CMakeFiles/ex3.dir/build.make
ex3.exe: CMakeFiles/ex3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex3.dir/build: ex3.exe

.PHONY : CMakeFiles/ex3.dir/build

CMakeFiles/ex3.dir/requires: CMakeFiles/ex3.dir/my_set.cpp.o.requires

.PHONY : CMakeFiles/ex3.dir/requires

CMakeFiles/ex3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex3.dir/clean

CMakeFiles/ex3.dir/depend:
	cd /cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/weitz/Desktop/ex3 /cygdrive/c/Users/weitz/Desktop/ex3 /cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug /cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug /cygdrive/c/Users/weitz/Desktop/ex3/cmake-build-debug/CMakeFiles/ex3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex3.dir/depend

