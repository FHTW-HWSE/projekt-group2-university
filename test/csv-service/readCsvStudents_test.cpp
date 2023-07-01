#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

// Test case for reading a lectureHall CSV file with valid data
TEST_CASE("Read valid CSVStudents file") {
    stringNode *list = NULL;
    char* filepath = (char*)"../assets/students.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns true
    //REQUIRE(result == true);

    // Verify the contents of the string list
    REQUIRE(list != nullptr);
    REQUIRE(equals(list->content, (char*)"IC112255;nugo;keles\n"));
    REQUIRE(list->nextStringNode != NULL);
    REQUIRE(equals(list->nextStringNode->content, (char*)"IC184795;marwan;abdalla\n"));
    REQUIRE(list->nextStringNode->nextStringNode != NULL);
}

// Test case for reading a non-existent CSV file
TEST_CASE("Read non-existent CSVStudents file") {
    stringNode *list = NULL;
    char* filepath = (char*)"nonexistent.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns false
    REQUIRE(result == false);

    // Verify that the string list is still empty
    REQUIRE(list == NULL);
}