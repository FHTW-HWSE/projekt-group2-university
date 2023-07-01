#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Free empty student list") {
    REQUIRE(freeStudentList(NULL) == true);
}

TEST_CASE("Free student list with one student") {
    student* s = (student*)malloc(sizeof(student));
    s->id = (char*)"12345678";
    s->firstName = (char*)"John";
    s->lastName = (char*)"Doe";
    s->nextStudent = NULL;
    s->examcounter = 0;

    REQUIRE(freeStudentList(s) == true);
}

TEST_CASE("Free student list with multiple students") {
    student* s1 = (student*)malloc(sizeof(student));
    s1->id = (char*)"12345678";
    s1->firstName = (char*)"John";
    s1->lastName = (char*)"Doe";
    s1->nextStudent = NULL;
    s1->examcounter = 0;

    student* s2 = (student*)malloc(sizeof(student));
    s2->id = (char*)"87654321";
    s2->firstName = (char*)"Jane";
    s2->lastName = (char*)"Smith";
    s2->nextStudent = NULL;
    s2->examcounter = 0;

    s1->nextStudent = s2;

    REQUIRE(freeStudentList(s1) == true);
}