#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Free empty lecture hall list") {
    REQUIRE(freeLectureHallList(NULL) == true);
}

TEST_CASE("Free lecture hall list with one lecture hall") {
    lectureHall* lh = (lectureHall*)malloc(sizeof(lectureHall));
    lh->name = (char*)"A101";
    lh->row = 15;
    lh->column = 25;
    lh->nextLectureHall = NULL;

    REQUIRE(freeLectureHallList(lh) == true);
}

TEST_CASE("Free lecture hall list with multiple lecture halls") {
    lectureHall* lh1 = (lectureHall*)malloc(sizeof(lectureHall));
    lh1->name = (char*)"A101";
    lh1->row = 15;
    lh1->column = 25;
    lh1->nextLectureHall = NULL;

    lectureHall* lh2 = (lectureHall*)malloc(sizeof(lectureHall));
    lh2->name = (char*)"B201";
    lh2->row = 20;
    lh2->column = 30;
    lh2->nextLectureHall = NULL;

    lh1->nextLectureHall = lh2;

    REQUIRE(freeLectureHallList(lh1) == true);
}