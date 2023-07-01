#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print empty exam list") {
    REQUIRE(printExamList(NULL) == false);
}

TEST_CASE("Print exam list with one exam") {
    lectureHall lh;
    lh.name = (char*)"A101";
    lh.row = 15;
    lh.column = 25;
    lh.nextLectureHall = NULL;

    exam e;
    e.name = (char*)"Math";
    e.workload = 100;
    e.lectureHall = &lh;
    e.nextExam = NULL;
    e.studentcounter = 20;
    e.maxStudents = 30;

    REQUIRE(printExamList(&e) == true);
}

TEST_CASE("Print exam list with multiple exams") {
    lectureHall lh1;
    lh1.name = (char*)"A101";
    lh1.row = 15;
    lh1.column = 25;
    lh1.nextLectureHall = NULL;

    lectureHall lh2;
    lh2.name = (char*)"B201";
    lh2.row = 20;
    lh2.column = 30;
    lh2.nextLectureHall = NULL;

    exam e1;
    e1.name = (char*)"Math";
    e1.workload = 100;
    e1.lectureHall = &lh1;
    e1.nextExam = NULL;
    e1.studentcounter = 20;
    e1.maxStudents = 30;

    exam e2;
    e2.name = (char*)"Physics";
    e2.workload = 50;
    e2.lectureHall = &lh2;
    e2.nextExam = NULL;
    e2.studentcounter = 15;
    e2.maxStudents = 25;

    e1.nextExam = &e2;

    REQUIRE(printExamList(&e1) == true);
}