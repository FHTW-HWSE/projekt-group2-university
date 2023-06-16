#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("examIsFull function tests", "[examIsFull]") {
    SECTION("Exam is full") {
        exam e;
        e.studentcounter = 50;
        e.maxStudents = 50;

        bool result = examIsFull(&e);

        REQUIRE(result == true);
    }

    SECTION("Exam is not full") {
        exam e;
        e.studentcounter = 30;
        e.maxStudents = 50;

        bool result = examIsFull(&e);

        REQUIRE(result == false);
    }
}