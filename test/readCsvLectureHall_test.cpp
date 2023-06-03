#include <catch2/catch.hpp>
#include "../headerFiles/headers.h"

// Test case for reading a lectureHall CSV file with valid data
TEST_CASE("Read valid CSV file") {
    stringNode *list = NULL;
    char* filepath = "../assets/lecturehalls.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns true
    REQUIRE(result == true);

    // Verify the contents of the string list
    REQUIRE(list != NULL);
    REQUIRE(list->content == "A341;4;3\n");
    REQUIRE(list->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->content == "F707;4;7\n");
    REQUIRE(list->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->content == "F202;5;5\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->content == "F707;1;2\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->content == "Q121;20;20\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->content == "F301;4;2\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->content == "AAAA;7;6\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode != NULL);
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->content == "BBBB;8;90\n");
    REQUIRE(list->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode->nextStringNode == NULL);
}

// Test case for reading a non-existent CSV file
TEST_CASE("Read non-existent CSV file") {
    stringNode *list = NULL;
    char* filepath = "nonexistent.csv";

    // Call the readCsv function
    bool result = readCsv(filepath, &list);

    // Verify that the function returns false
    REQUIRE(result == false);

    // Verify that the string list is still empty
    REQUIRE(list == NULL);
}