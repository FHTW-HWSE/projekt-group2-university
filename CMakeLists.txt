cmake_minimum_required(VERSION 3.1...3.26)


project(
  Sitzplatzgenerator
  VERSION 1.0
  LANGUAGES CXX)

  find_package(Catch2 REQUIRED)

  include(CTest)
  include(Catch)

  add_library(generator_library helpers.cpp lists/exam.cpp lists/lectureHall.cpp lists/string.cpp lists/student.cpp services/csv-service.cpp)
  target_include_directories(generator_library PUBLIC headerFiles)
  
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set(CMAKE_BUILD_TYPE Debug)

  add_executable(generator main.cpp )
  target_link_libraries(generator generator_library)