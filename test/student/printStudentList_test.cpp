#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print empty student list") {
    REQUIRE(printStudentList(NULL) == false);
}

TEST_CASE("Print student list with one student") {
    student s;
    s.id = (char*)"12345678";
    s.firstName = (char*)"John";
    s.lastName = (char*)"Doe";
    s.nextStudent = NULL;
    s.examcounter = 0;

    REQUIRE(printStudentList(&s) == true);
}

TEST_CASE("Print student list with multiple students") {
    student s1;
    s1.id = (char*)"12345678";
    s1.firstName = (char*)"John";
    s1.lastName = (char*)"Doe";
    s1.nextStudent = NULL;
    s1.examcounter = 0;

    student s2;
    s2.id = (char*)"87654321";
    s2.firstName = (char*)"Jane";
    s2.lastName = (char*)"Smith";
    s2.nextStudent = NULL;
    s2.examcounter = 0;

    s1.nextStudent = &s2;

    REQUIRE(printStudentList(&s1) == true);
}