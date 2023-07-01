#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print valid exam") {
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

    REQUIRE(printExam(&e) == true);
}

TEST_CASE("Print NULL exam") {
    REQUIRE(printExam(NULL) == false);
}