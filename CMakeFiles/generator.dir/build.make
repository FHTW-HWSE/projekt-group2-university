# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator

# Include any dependencies generated for this target.
include CMakeFiles/generator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/generator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generator.dir/flags.make

CMakeFiles/generator.dir/main.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/main.cpp.o: main.cpp
CMakeFiles/generator.dir/main.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/main.cpp.o -MF CMakeFiles/generator.dir/main.cpp.o.d -o CMakeFiles/generator.dir/main.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/main.cpp

CMakeFiles/generator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/main.cpp > CMakeFiles/generator.dir/main.cpp.i

CMakeFiles/generator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/main.cpp -o CMakeFiles/generator.dir/main.cpp.s

CMakeFiles/generator.dir/helpers.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/helpers.cpp.o: helpers.cpp
CMakeFiles/generator.dir/helpers.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generator.dir/helpers.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/helpers.cpp.o -MF CMakeFiles/generator.dir/helpers.cpp.o.d -o CMakeFiles/generator.dir/helpers.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/helpers.cpp

CMakeFiles/generator.dir/helpers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/helpers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/helpers.cpp > CMakeFiles/generator.dir/helpers.cpp.i

CMakeFiles/generator.dir/helpers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/helpers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/helpers.cpp -o CMakeFiles/generator.dir/helpers.cpp.s

CMakeFiles/generator.dir/structs/exam.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/structs/exam.cpp.o: structs/exam.cpp
CMakeFiles/generator.dir/structs/exam.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/generator.dir/structs/exam.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/structs/exam.cpp.o -MF CMakeFiles/generator.dir/structs/exam.cpp.o.d -o CMakeFiles/generator.dir/structs/exam.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/exam.cpp

CMakeFiles/generator.dir/structs/exam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/structs/exam.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/exam.cpp > CMakeFiles/generator.dir/structs/exam.cpp.i

CMakeFiles/generator.dir/structs/exam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/structs/exam.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/exam.cpp -o CMakeFiles/generator.dir/structs/exam.cpp.s

CMakeFiles/generator.dir/structs/lectureHall.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/structs/lectureHall.cpp.o: structs/lectureHall.cpp
CMakeFiles/generator.dir/structs/lectureHall.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/generator.dir/structs/lectureHall.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/structs/lectureHall.cpp.o -MF CMakeFiles/generator.dir/structs/lectureHall.cpp.o.d -o CMakeFiles/generator.dir/structs/lectureHall.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/lectureHall.cpp

CMakeFiles/generator.dir/structs/lectureHall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/structs/lectureHall.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/lectureHall.cpp > CMakeFiles/generator.dir/structs/lectureHall.cpp.i

CMakeFiles/generator.dir/structs/lectureHall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/structs/lectureHall.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/lectureHall.cpp -o CMakeFiles/generator.dir/structs/lectureHall.cpp.s

CMakeFiles/generator.dir/structs/string.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/structs/string.cpp.o: structs/string.cpp
CMakeFiles/generator.dir/structs/string.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/generator.dir/structs/string.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/structs/string.cpp.o -MF CMakeFiles/generator.dir/structs/string.cpp.o.d -o CMakeFiles/generator.dir/structs/string.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/string.cpp

CMakeFiles/generator.dir/structs/string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/structs/string.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/string.cpp > CMakeFiles/generator.dir/structs/string.cpp.i

CMakeFiles/generator.dir/structs/string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/structs/string.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/string.cpp -o CMakeFiles/generator.dir/structs/string.cpp.s

CMakeFiles/generator.dir/structs/student.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/structs/student.cpp.o: structs/student.cpp
CMakeFiles/generator.dir/structs/student.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/generator.dir/structs/student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/structs/student.cpp.o -MF CMakeFiles/generator.dir/structs/student.cpp.o.d -o CMakeFiles/generator.dir/structs/student.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/student.cpp

CMakeFiles/generator.dir/structs/student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/structs/student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/student.cpp > CMakeFiles/generator.dir/structs/student.cpp.i

CMakeFiles/generator.dir/structs/student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/structs/student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/structs/student.cpp -o CMakeFiles/generator.dir/structs/student.cpp.s

CMakeFiles/generator.dir/services/csv-service.cpp.o: CMakeFiles/generator.dir/flags.make
CMakeFiles/generator.dir/services/csv-service.cpp.o: services/csv-service.cpp
CMakeFiles/generator.dir/services/csv-service.cpp.o: CMakeFiles/generator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/generator.dir/services/csv-service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/generator.dir/services/csv-service.cpp.o -MF CMakeFiles/generator.dir/services/csv-service.cpp.o.d -o CMakeFiles/generator.dir/services/csv-service.cpp.o -c /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/services/csv-service.cpp

CMakeFiles/generator.dir/services/csv-service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/services/csv-service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/services/csv-service.cpp > CMakeFiles/generator.dir/services/csv-service.cpp.i

CMakeFiles/generator.dir/services/csv-service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/services/csv-service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/services/csv-service.cpp -o CMakeFiles/generator.dir/services/csv-service.cpp.s

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles/generator.dir/main.cpp.o" \
"CMakeFiles/generator.dir/helpers.cpp.o" \
"CMakeFiles/generator.dir/structs/exam.cpp.o" \
"CMakeFiles/generator.dir/structs/lectureHall.cpp.o" \
"CMakeFiles/generator.dir/structs/string.cpp.o" \
"CMakeFiles/generator.dir/structs/student.cpp.o" \
"CMakeFiles/generator.dir/services/csv-service.cpp.o"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator: CMakeFiles/generator.dir/main.cpp.o
generator: CMakeFiles/generator.dir/helpers.cpp.o
generator: CMakeFiles/generator.dir/structs/exam.cpp.o
generator: CMakeFiles/generator.dir/structs/lectureHall.cpp.o
generator: CMakeFiles/generator.dir/structs/string.cpp.o
generator: CMakeFiles/generator.dir/structs/student.cpp.o
generator: CMakeFiles/generator.dir/services/csv-service.cpp.o
generator: CMakeFiles/generator.dir/build.make
generator: CMakeFiles/generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generator.dir/build: generator
.PHONY : CMakeFiles/generator.dir/build

CMakeFiles/generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generator.dir/clean

CMakeFiles/generator.dir/depend:
	cd /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator /home/marwan/Technikum/Softwareentwicklung/Sitzplatzgenerator/CMakeFiles/generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generator.dir/depend

