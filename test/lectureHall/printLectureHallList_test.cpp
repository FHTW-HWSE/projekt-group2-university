#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print empty lecture hall list",) {
    REQUIRE(printLectureHallList(NULL) == false);
}

TEST_CASE("Print lecture hall list with one lecture hall") {
    lectureHall lh;
    lh.name = (char*)"A101";
    lh.row = 15;
    lh.column = 25;
    lh.nextLectureHall = NULL;

    REQUIRE(printLectureHallList(&lh) == true);
}

TEST_CASE("Print lecture hall list with multiple lecture halls") {
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

    lh1.nextLectureHall = &lh2;

    REQUIRE(printLectureHallList(&lh1) == true);
}
