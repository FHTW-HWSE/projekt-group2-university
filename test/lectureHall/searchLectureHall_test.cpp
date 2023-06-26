#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Search lecture hall in a non-empty list", "[lectureHall]") {

    char *name1 = (char*)"XXXX";
    char *name2 = (char*)"YYYY";
    char *name3 = (char*)"ZZZZ";
    int row = 10;
    int column = 20;
    lectureHall* head = createLectureHall(name1, row, column);
    head->nextLectureHall = createLectureHall(name2, row, column);
    head->nextLectureHall->nextLectureHall = createLectureHall(name3, row, column);

    lectureHall* result1 = searchLectureHall(head, name1);
    lectureHall* result2 = searchLectureHall(head, name2);
    lectureHall* result3 = searchLectureHall(head, name3);

    REQUIRE(result1 != nullptr);
    REQUIRE(strcmp(result1->name, name1) == 0);
    REQUIRE(result2 != nullptr);
    REQUIRE(strcmp(result2->name, name2) == 0);
    REQUIRE(result3 != nullptr);
    REQUIRE(strcmp(result3->name, name3) == 0);

    freeLectureHallList(head);
}

TEST_CASE("Search lecture hall in an empty list", "[lectureHall]") {
    char *name = (char*)"WXYZ";
    lectureHall* head = nullptr;

    lectureHall* result = searchLectureHall(head, name);

    REQUIRE(result == nullptr);
}

TEST_CASE("Search lecture hall with a non-existing name", "[lectureHall]") {

    char *name1 = (char*)"UWVX";
    char *name2 = (char*)"ZYXW";
    int row = 10;
    int column = 20;
    lectureHall* head = createLectureHall(name1, row, column);

    lectureHall* result = searchLectureHall(head, name2);

    REQUIRE(result == nullptr);

    freeLectureHallList(head);
}
