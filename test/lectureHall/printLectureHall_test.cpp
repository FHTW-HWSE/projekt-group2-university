#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print valid lecture hall") {
    lectureHall lh;
    lh.name = (char*)"A101";
    lh.row = 15;
    lh.column = 25;
    lh.nextLectureHall = NULL;

    REQUIRE(printLectureHall(&lh) == true);
}

TEST_CASE("Print NULL lecture hall") {
    REQUIRE(printLectureHall(NULL) == false);
}
