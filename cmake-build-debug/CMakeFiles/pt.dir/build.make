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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hashibami/Desktop/2018/pt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hashibami/Desktop/2018/pt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pt.dir/flags.make

CMakeFiles/pt.dir/main.cpp.o: CMakeFiles/pt.dir/flags.make
CMakeFiles/pt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hashibami/Desktop/2018/pt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pt.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pt.dir/main.cpp.o -c /Users/hashibami/Desktop/2018/pt/main.cpp

CMakeFiles/pt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pt.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hashibami/Desktop/2018/pt/main.cpp > CMakeFiles/pt.dir/main.cpp.i

CMakeFiles/pt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pt.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hashibami/Desktop/2018/pt/main.cpp -o CMakeFiles/pt.dir/main.cpp.s

CMakeFiles/pt.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pt.dir/main.cpp.o.requires

CMakeFiles/pt.dir/main.cpp.o.provides: CMakeFiles/pt.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pt.dir/build.make CMakeFiles/pt.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pt.dir/main.cpp.o.provides

CMakeFiles/pt.dir/main.cpp.o.provides.build: CMakeFiles/pt.dir/main.cpp.o


# Object files for target pt
pt_OBJECTS = \
"CMakeFiles/pt.dir/main.cpp.o"

# External object files for target pt
pt_EXTERNAL_OBJECTS =

pt: CMakeFiles/pt.dir/main.cpp.o
pt: CMakeFiles/pt.dir/build.make
pt: CMakeFiles/pt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hashibami/Desktop/2018/pt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pt.dir/build: pt

.PHONY : CMakeFiles/pt.dir/build

CMakeFiles/pt.dir/requires: CMakeFiles/pt.dir/main.cpp.o.requires

.PHONY : CMakeFiles/pt.dir/requires

CMakeFiles/pt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pt.dir/clean

CMakeFiles/pt.dir/depend:
	cd /Users/hashibami/Desktop/2018/pt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hashibami/Desktop/2018/pt /Users/hashibami/Desktop/2018/pt /Users/hashibami/Desktop/2018/pt/cmake-build-debug /Users/hashibami/Desktop/2018/pt/cmake-build-debug /Users/hashibami/Desktop/2018/pt/cmake-build-debug/CMakeFiles/pt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pt.dir/depend
