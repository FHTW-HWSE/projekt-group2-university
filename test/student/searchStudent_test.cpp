#include <catch2/catch.hpp>
#include "../headerFiles/headers.h"

// Test case for searching a student in an empty list
TEST_CASE("Search student in empty list", "[searchStudent]") {
    student *list = NULL;
    char* lastname = "Smith";

    bool result = searchStudent(list, lastname);

    // Verify that the student is not found
    REQUIRE(result == false);
}

// Test case for searching a student with a matching last name
TEST_CASE("Search student with matching last name", "[searchStudent]") {
    student *list = new student;
    list->lastName = "Smith";
    list->nextStudent = NULL;
    char* lastname = "Smith";

    bool result = searchStudent(list, lastname);

    // Verify that the student is found
    REQUIRE(result == true);
}

// Test case for searching a student with a non-matching last name
TEST_CASE("Search student with non-matching last name", "[searchStudent]") {
    student *list = new student;
    list->lastName = "Smith";
    list->nextStudent = NULL;
    char* lastname = "Johnson";

    bool result = searchStudent(list, lastname);

    // Verify that the student is not found
    REQUIRE(result == false);
}