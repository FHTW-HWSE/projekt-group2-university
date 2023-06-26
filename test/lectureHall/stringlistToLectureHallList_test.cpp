#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Convert string list to lecture hall list", "[lectureHall][stringList]") {

    char *string1 = (char*)"XXXX;10;20";
    char *string2 = (char*)"YYYY;15;25";
    char *string3 = (char*)"ZZZZ;20;30";
    stringNode* stringList = createStringNode(string1);
    stringList->nextStringNode = createStringNode(string2);
    stringList->nextStringNode->nextStringNode = createStringNode(string3);
    lectureHall* lectureHallList = nullptr;

    stringlistToLectureHallList(stringList, &lectureHallList);

    REQUIRE(lectureHallList != nullptr);
    REQUIRE(strcmp(lectureHallList->name, "XXXX") == 0);
    REQUIRE(lectureHallList->row == 10);
    REQUIRE(lectureHallList->column == 20);
    REQUIRE(lectureHallList->nextLectureHall != nullptr);
    REQUIRE(strcmp(lectureHallList->nextLectureHall->name, "YYYY") == 0);
    REQUIRE(lectureHallList->nextLectureHall->row == 15);
    REQUIRE(lectureHallList->nextLectureHall->column == 25);
    REQUIRE(lectureHallList->nextLectureHall->nextLectureHall != nullptr);
    REQUIRE(strcmp(lectureHallList->nextLectureHall->nextLectureHall->name, "ZZZZ") == 0);
    REQUIRE(lectureHallList->nextLectureHall->nextLectureHall->row == 20);
    REQUIRE(lectureHallList->nextLectureHall->nextLectureHall->column == 30);

    freeLectureHallList(lectureHallList);
    freeStringList(stringList);
}
