#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Check if format matches string") {
    // Define a sample string and format
    char *dateString = (char*)"2023-06-27";
    char *formatString = (char*)"%Y-%m-%d";

    // Check if the format matches the string
    bool result = checkIfFormatMatch(dateString, formatString);

    // Assert that the format matches
    REQUIRE(result);
}

TEST_CASE("Check if format does not match string") {
    // Define a sample string and format
    char *dateString = (char*)"2023-06-27";
    char *formatString = (char*)"%d-%m-%Y";

    // Check if the format matches the string
    bool result = checkIfFormatMatch(dateString, formatString);

    // Assert that the format does not match
    REQUIRE_FALSE(result);
}

TEST_CASE("Check with invalid string or format") {
    // Define an invalid string and format
    char *dateString = (char*)"2023-06-27";
    char *formatString = (char*)"%Y-%m-%";

    // Check if the format matches the string
    bool result = checkIfFormatMatch(dateString, formatString);

    // Assert that the format does not match due to an invalid format
    REQUIRE_FALSE(result);
}