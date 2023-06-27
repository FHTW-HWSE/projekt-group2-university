#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Count occurrences of character in string") {
    // Define a sample string and character
    char *str = (char*)"Hello, World!";
    char character = 'o';

    // Count the occurrences of the character in the string
    int result = countCharInString(str, character);

    // Assert that the result is as expected
    REQUIRE(result == 2);
}

TEST_CASE("Count occurrences of character in empty string") {
    // Define an empty string and a character
    char *str = (char*)"";
    char character = 'a';

    // Count the occurrences of the character in the string
    int result = countCharInString(str, character);

    // Assert that the result is 0
    REQUIRE(result == 0);
}

TEST_CASE("Count occurrences of character in string with no match") {
    // Define a string and a character that does not occur in the string
    char *str = (char*)"Hello, World!";
    char character = 'x';

    // Count the occurrences of the character in the string
    int result = countCharInString(str, character);

    // Assert that the result is 0
    REQUIRE(result == 0);
}