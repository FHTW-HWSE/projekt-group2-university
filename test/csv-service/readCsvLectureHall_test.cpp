#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <cstring>

TEST_CASE("Read valid CSV file", "[readCsv]") {
    
    stringNode *list = nullptr;
    char* filepath = (char*)"../../assets/lecturehalls.csv";

    // Read the CSV file
    bool success = readCsv(const_cast<char*>(filepath), &list);

    // Assert that the read operation was successful
    REQUIRE(success);

    // Assert that the list contains the correct data
    REQUIRE(list != nullptr);
    REQUIRE(std::strcmp(list->value, "John,Doe,25\n") == 0);
    REQUIRE(list->next != nullptr);
    REQUIRE(std::strcmp(list->next->value, "Jane,Smith,30\n") == 0);

    // Clean up
    remove(filepath);
}



/*
// Test case for reading a lectureHall CSV file with valid data
TEST_CASE("Read valid CSV file") {
    stringNode *list = NULL;
    char* filepath = (char*)"../../assets/lecturehalls.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns true
    //REQUIRE(result == true);

    // Verify the contents of the string list
    REQUIRE(list != nullptr);
    REQUIRE(list->content == "A341;4;3\n");
    REQUIRE(list->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->content == "F407;4;7\n");
    REQUIRE(list->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->content == "F202;5;5\n");
}
*/

// Test case for reading a non-existent CSV file
TEST_CASE("Read non-existent CSV file") {
    stringNode *list = NULL;
    char* filepath = (char*)"nonexistent.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns false
    REQUIRE(result == false);

    // Verify that the string list is still empty
    REQUIRE(list == NULL);
}