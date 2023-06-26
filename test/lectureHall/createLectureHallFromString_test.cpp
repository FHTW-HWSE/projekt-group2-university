#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Create lecture hall from a valid string", "[lectureHall]") {
    char *string = (char*)"XXXX;10;20";

    lectureHall* hall = createLectureHallFromString(string);

    REQUIRE(hall != nullptr);
    REQUIRE(strcmp(hall->name, "XXXX") == 0);
    REQUIRE(hall->row == 10);
    REQUIRE(hall->column == 20);
}

/* 
TEST_CASE("Create lecture hall from an invalid string with too many semicolons", "[lectureHall]") {
    char *string = (char*)"YYYY;10;20;30";

    lectureHall* hall = createLectureHallFromString(string);

    REQUIRE(hall == NULL);
}

TEST_CASE("Create lecture hall from an invalid string with too long name", "[lectureHall]") {
    char *string = (char*)"VWXYZ;10;20";

    lectureHall* hall = createLectureHallFromString(string);

    REQUIRE(hall == NULL);
}
*/