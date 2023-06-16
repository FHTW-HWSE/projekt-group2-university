#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("getMaxStudentsFromLecturehall function tests", "[getMaxStudentsFromLecturehall]") {
    SECTION("Lecture hall with positive dimensions") {
        lectureHall hall;
        hall.row = 5;
        hall.column = 6;

        int result = getMaxStudentsFromLecturehall(&hall);

        REQUIRE(result == 30);
    }

    SECTION("Lecture hall with zero dimensions") {
        lectureHall hall;
        hall.row = 0;
        hall.column = 8;

        int result = getMaxStudentsFromLecturehall(&hall);

        REQUIRE(result == 0);
    }

    SECTION("Lecture hall with negative dimensions") {
        lectureHall hall;
        hall.row = -3;
        hall.column = 4;

        int result = getMaxStudentsFromLecturehall(&hall);

        REQUIRE(result == -12);
    }
}