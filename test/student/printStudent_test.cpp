#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print valid student") {
    student s;
    s.id = (char*)"12345678";
    s.firstName = (char*)"John";
    s.lastName = (char*)"Doe";
    

    REQUIRE(printStudent(&s) == true);
}

TEST_CASE("Print NULL student") {
    REQUIRE(printStudent(NULL) == false);
}