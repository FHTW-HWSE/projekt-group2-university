#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <sstream>
#include <cstdio>
#include <iostream>

TEST_CASE("Insert into lecture hall list", "[lectureHall]") {
    char *name = (char*)"ZZZZ";
    lectureHall* list = NULL;
    lectureHall* newLectureHall = createLectureHall(name, 10, 20);
    bool csvflag = false;

    SECTION("Inserting a valid lecture hall") {
        bool result = insertIntoLectureHallList(&list, newLectureHall, csvflag);

        REQUIRE(result == true);
        REQUIRE(list == newLectureHall);
    }

    SECTION("Inserting a NULL lecture hall") {

        bool result = insertIntoLectureHallList(&list, NULL, csvflag);

        REQUIRE(result == false);
        REQUIRE(list == NULL);
    }

    SECTION("Inserting an existing lecture hall") {

        insertIntoLectureHallList(&list, newLectureHall, csvflag);

        lectureHall* existingLectureHall = createLectureHall(name, 10, 20);

        bool result = insertIntoLectureHallList(&list, existingLectureHall, csvflag);

        REQUIRE(result == false);
        REQUIRE(list->nextLectureHall == NULL);

        freeLectureHallList(existingLectureHall);
    }

    freeLectureHallList(list);
}
