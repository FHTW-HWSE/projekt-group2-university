#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

/*
TEST_CASE("Check if file exists") {
    // Create a sample file
    char* filename = (char*)"../../assets/lecturehalls.csv";
    FILE* file = fopen(filename, "r");
    if (file != nullptr) {
        fclose(file);
    }

    // Check if the file exists
    bool result = fileExists(filename);

    // Assert that the file exists
    REQUIRE(result);

    // Clean up
    remove(filename);
}
*/

TEST_CASE("Check if file does not exist", "[fileExists]") {
    // Specify a non-existing file
    char* filename = (char*)"non_existing.txt";

    // Check if the file exists
    bool result = fileExists(filename);

    // Assert that the file does not exist
    REQUIRE_FALSE(result);
}