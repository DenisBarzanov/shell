# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/denisbarzanov2002/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/denisbarzanov2002/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denisbarzanov2002/CLionProjects/os_shell_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug

# Utility rule file for apue_target.

# Include the progress variables for this target.
include CMakeFiles/apue_target.dir/progress.make

CMakeFiles/apue_target: ../apue.3e/lib/libapue.a


../apue.3e/lib/libapue.a:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../apue.3e/lib/libapue.a"
	cd /home/denisbarzanov2002/CLionProjects/os_shell_1/apue.3e/lib && make

apue_target: CMakeFiles/apue_target
apue_target: ../apue.3e/lib/libapue.a
apue_target: CMakeFiles/apue_target.dir/build.make

.PHONY : apue_target

# Rule to build all files generated by this target.
CMakeFiles/apue_target.dir/build: apue_target

.PHONY : CMakeFiles/apue_target.dir/build

CMakeFiles/apue_target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apue_target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apue_target.dir/clean

CMakeFiles/apue_target.dir/depend:
	cd /home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denisbarzanov2002/CLionProjects/os_shell_1 /home/denisbarzanov2002/CLionProjects/os_shell_1 /home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug /home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug /home/denisbarzanov2002/CLionProjects/os_shell_1/cmake-build-debug/CMakeFiles/apue_target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/apue_target.dir/depend
