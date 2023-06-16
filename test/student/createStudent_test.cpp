#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("createStudent creates a student with correct values") {
    char firstName[] = "John";
    char lastName[] = "Doe";

    student* result = createStudent(firstName, lastName);

    REQUIRE(result->firstName != nullptr);
    REQUIRE(result->lastName != nullptr);
    REQUIRE(strcmp(result->firstName, firstName) == 0);
    REQUIRE(strcmp(result->lastName, lastName) == 0);

    free(result->firstName);
    free(result->lastName);
    free(result);
}

TEST_CASE("createStudent generates a random ID") {
    char firstName[] = "Jane";
    char lastName[] = "Smith";

    student* result1 = createStudent(firstName, lastName);
    student* result2 = createStudent(firstName, lastName);

    REQUIRE(result1->id != result2->id);

    free(result1->firstName);
    free(result1->lastName);
    free(result1);
    free(result2->firstName);
    free(result2->lastName);
    free(result2);
}