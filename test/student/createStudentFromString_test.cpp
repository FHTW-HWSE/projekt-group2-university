#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Create student from a valid string") {
    char *string = (char*)"AA986532;Tom;Turbo";

    student* newStudent = createStudentFromString(string);

    REQUIRE(newStudent != nullptr);
    REQUIRE(strcmp(newStudent->id, "AA986532") == 0);
    REQUIRE(strcmp(newStudent->firstName, "Tom") == 0);
    REQUIRE(strcmp(newStudent->lastName, "Turbo") == 0);
}