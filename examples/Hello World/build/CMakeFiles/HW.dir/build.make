# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build"

# Include any dependencies generated for this target.
include CMakeFiles/HW.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HW.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW.dir/flags.make

CMakeFiles/HW.dir/src/main.cpp.obj: CMakeFiles/HW.dir/flags.make
CMakeFiles/HW.dir/src/main.cpp.obj: C:/Users/TheKi/OneDrive\ -\ UVG/Semestre\ VI/Graficas\ por\ computadora/Ejercicios/Hello\ World/src/main.cpp
CMakeFiles/HW.dir/src/main.cpp.obj: CMakeFiles/HW.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW.dir/src/main.cpp.obj"
	C:\llvm\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HW.dir/src/main.cpp.obj -MF CMakeFiles\HW.dir\src\main.cpp.obj.d -o CMakeFiles\HW.dir\src\main.cpp.obj -c "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\src\main.cpp"

CMakeFiles/HW.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HW.dir/src/main.cpp.i"
	C:\llvm\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\src\main.cpp" > CMakeFiles\HW.dir\src\main.cpp.i

CMakeFiles/HW.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HW.dir/src/main.cpp.s"
	C:\llvm\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\src\main.cpp" -o CMakeFiles\HW.dir\src\main.cpp.s

# Object files for target HW
HW_OBJECTS = \
"CMakeFiles/HW.dir/src/main.cpp.obj"

# External object files for target HW
HW_EXTERNAL_OBJECTS =

HW.exe: CMakeFiles/HW.dir/src/main.cpp.obj
HW.exe: CMakeFiles/HW.dir/build.make
HW.exe: CMakeFiles/HW.dir/linkLibs.rsp
HW.exe: CMakeFiles/HW.dir/objects1.rsp
HW.exe: CMakeFiles/HW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW.dir/build: HW.exe
.PHONY : CMakeFiles/HW.dir/build

CMakeFiles/HW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW.dir/clean

CMakeFiles/HW.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World" "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World" "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build" "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build" "C:\Users\TheKi\OneDrive - UVG\Semestre VI\Graficas por computadora\Ejercicios\Hello World\build\CMakeFiles\HW.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/HW.dir/depend

