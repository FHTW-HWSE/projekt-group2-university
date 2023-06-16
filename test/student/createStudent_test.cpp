#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("createStudent function tests", "[createStudent]") {
    SECTION("Valid student creation") {
        char id[] = "12345678";
        char firstName[] = "John";
        char lastName[] = "Doe";

        student* newStudent = createStudent(id, firstName, lastName);

        REQUIRE(newStudent != nullptr);
        REQUIRE(strcmp(newStudent->id, id) == 0);
        REQUIRE(strcmp(newStudent->firstName, firstName) == 0);
        REQUIRE(strcmp(newStudent->lastName, lastName) == 0);

        free(newStudent->id);
        free(newStudent->firstName);
        free(newStudent->lastName);
        free(newStudent);
    }
}