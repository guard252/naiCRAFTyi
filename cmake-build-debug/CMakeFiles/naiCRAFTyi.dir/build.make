# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danylo/dev/naiCRAFTyi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danylo/dev/naiCRAFTyi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/naiCRAFTyi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/naiCRAFTyi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/naiCRAFTyi.dir/flags.make

CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/main.cpp

CMakeFiles/naiCRAFTyi.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/main.cpp > CMakeFiles/naiCRAFTyi.dir/src/main.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/main.cpp -o CMakeFiles/naiCRAFTyi.dir/src/main.cpp.s

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o: ../src/GLAbstraction/Tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Tools.cpp

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Tools.cpp > CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Tools.cpp -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.s

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o: ../src/GLAbstraction/VBO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VBO.cpp

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VBO.cpp > CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VBO.cpp -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.s

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o: ../src/GLAbstraction/VAO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VAO.cpp

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VAO.cpp > CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/VAO.cpp -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.s

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o: ../src/GLAbstraction/ShaderProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/ShaderProgram.cpp

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/ShaderProgram.cpp > CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/ShaderProgram.cpp -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.s

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o: CMakeFiles/naiCRAFTyi.dir/flags.make
CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o: ../src/GLAbstraction/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o -c /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Texture.cpp

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Texture.cpp > CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.i

CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/danylo/dev/naiCRAFTyi/src/GLAbstraction/Texture.cpp -o CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.s

# Object files for target naiCRAFTyi
naiCRAFTyi_OBJECTS = \
"CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o" \
"CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o" \
"CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o" \
"CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o" \
"CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o" \
"CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o"

# External object files for target naiCRAFTyi
naiCRAFTyi_EXTERNAL_OBJECTS =

naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/main.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Tools.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VBO.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/VAO.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/ShaderProgram.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/src/GLAbstraction/Texture.cpp.o
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/build.make
naiCRAFTyi: CMakeFiles/naiCRAFTyi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable naiCRAFTyi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/naiCRAFTyi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/naiCRAFTyi.dir/build: naiCRAFTyi

.PHONY : CMakeFiles/naiCRAFTyi.dir/build

CMakeFiles/naiCRAFTyi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/naiCRAFTyi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/naiCRAFTyi.dir/clean

CMakeFiles/naiCRAFTyi.dir/depend:
	cd /home/danylo/dev/naiCRAFTyi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danylo/dev/naiCRAFTyi /home/danylo/dev/naiCRAFTyi /home/danylo/dev/naiCRAFTyi/cmake-build-debug /home/danylo/dev/naiCRAFTyi/cmake-build-debug /home/danylo/dev/naiCRAFTyi/cmake-build-debug/CMakeFiles/naiCRAFTyi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/naiCRAFTyi.dir/depend

