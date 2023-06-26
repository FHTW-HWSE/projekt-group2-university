#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Create lecture hall", "[lectureHall]") {

    char name[] = "A";
    int row = 10;
    int column = 20;

    lectureHall* hall = createLectureHall(name, row, column);

    REQUIRE(hall != nullptr);
    REQUIRE(strcmp(hall->name, name) == 0);
    REQUIRE(hall->row == row);
    REQUIRE(hall->column == column);

    free(hall->name);
    free(hall);
}

TEST_CASE("Create lecture hall with invalid row", "[lectureHall]") {

    char name[] = "B";
    int row = 0;
    int column = 20;

    lectureHall* hall = createLectureHall(name, row, column);

    REQUIRE(hall == nullptr);
}

TEST_CASE("Create lecture hall with invalid column", "[lectureHall]") {

    char name[] = "C";
    int row = 10;
    int column = 0;

    lectureHall* hall = createLectureHall(name, row, column);

    REQUIRE(hall == nullptr);
}
