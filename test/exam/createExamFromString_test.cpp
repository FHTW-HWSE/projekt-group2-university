#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <cstring>

TEST_CASE("Create exam from valid string") {
    // Create a sample lecture hall
    lectureHall* lectureHall1 = new lectureHall;
    lectureHall1->name = (char*)"LectureHall1";
    lectureHall1->row = 10;
    lectureHall1->column = 20;
    lectureHall1->nextLectureHall = nullptr;

    // Create an exam string
    char *examString = (char*)"Exam1;3;LectureHall1\n";

    // Create the exam from the string
    exam* newExam = createExamFromString(examString, lectureHall1);

    // Assert that the exam was created correctly
    REQUIRE(std::strcmp(newExam->name, (char*)"Exam1") == 0);
    REQUIRE(newExam->workload == 3);
    REQUIRE(newExam->lectureHall == lectureHall1);
    REQUIRE(newExam->studentcounter == 0);

}
