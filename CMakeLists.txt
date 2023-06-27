cmake_minimum_required(VERSION 3.1...3.26)


project(
  Sitzplatzgenerator
  VERSION 1.0
  LANGUAGES CXX)

  find_package(Catch2 REQUIRED)

  include(CTest)
  include(Catch)

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_BUILD_TYPE Debug)

  add_library(generator_library services/helpers.cpp lists/exam.cpp lists/lectureHall.cpp lists/string.cpp lists/student.cpp services/csv-service.cpp)
  target_include_directories(generator_library PUBLIC headerFiles)
  
  add_executable(generator main.cpp )
   
  add_executable(test_generator 
  test/main.cpp

  #test/csv-service/readCsvLectureHall_test.cpp

  test/exam/createExam_test.cpp
  test/exam/searchExam_test.cpp
  test/exam/createExamFromString_test.cpp
  test/helpers/checkIDFormat_test.cpp
  test/helpers/equals_test.cpp
  test/helpers/examIsFull_test.cpp
  test/helpers/getAmountFromWorkload_test.cpp
  test/helpers/getMaxStudentsFromLecturehall_test.cpp
  test/helpers/integerToString_test.cpp
  test/helpers/checkIfFormatMatch_test.cpp
  test/helpers/fileExists_test.cpp
  test/helpers/countCharInString_test.cpp
  test/lectureHall/createLectureHall_test.cpp
  test/lectureHall/searchLectureHall_test.cpp
  test/lectureHall/stringlistToLectureHallList_test.cpp
  test/lectureHall/createLectureHallFromString_test.cpp
  test/lectureHall/insertIntoLectureHallList_test.cpp
  test/string/createStringNode_test.cpp
  test/student/createStudent_test.cpp
  test/student/insertStudentIntoList_test.cpp
  test/student/searchStudent_test.cpp
  test/student/createStudentFromString_test.cpp
  test/student/stringlistToStudentList_test.cpp

  )


  target_link_libraries(generator generator_library)
  
  target_link_libraries(test_generator generator_library)

  # Add a target coverage that will run the tests and report the coverage of the 
  # library in a folder coverage
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    include(CodeCoverage.cmake)
    append_coverage_compiler_flags_to_target(generator_library)
    setup_target_for_coverage_lcov(
        NAME coverage
        EXECUTABLE test_generator
        EXCLUDE "/usr/include/*" "test/*" "main.cpp"
    )
  endif()