
cmake_minimum_required(VERSION 3.1...3.26)


project(
  Sitzplatzgenerator
  VERSION 1.0
  LANGUAGES CXX)

  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)

  add_executable(generator main.cpp helpers.cpp structs/exam.cpp structs/lectureHall.cpp structs/string.cpp structs/student.cpp services/csv-service.cpp)
