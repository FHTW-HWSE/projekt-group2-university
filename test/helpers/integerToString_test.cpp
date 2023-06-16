#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("integerToString function tests", "[integerToString]") {
    SECTION("Positive integer") {
        int num = 12345;
        char* result = integerToString(num);
        REQUIRE(strcmp(result, "12345") == 0);
        free(result);
    }

    SECTION("Negative integer") {
        int num = -9876;
        char* result = integerToString(num);
        REQUIRE(strcmp(result, "-9876") == 0);
        free(result);
    }

    SECTION("Zero") {
        int num = 0;
        char* result = integerToString(num);
        REQUIRE(strcmp(result, "0") == 0);
        free(result);
    }
}