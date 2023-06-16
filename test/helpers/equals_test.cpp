#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("equals function tests", "[equals]") {
    SECTION("Equal strings") {
        char str1[] = "Hello";
        char str2[] = "Hello";
        REQUIRE(equals(str1, str2) == true);
    }

    SECTION("Unequal strings") {
        char str1[] = "Hello";
        char str2[] = "World";
        REQUIRE(equals(str1, str2) == false);
    }

    SECTION("Empty strings") {
        char str1[] = "";
        char str2[] = "";
        REQUIRE(equals(str1, str2) == true);
    }

    SECTION("One empty string, one non-empty string") {
        char str1[] = "";
        char str2[] = "Hello";
        REQUIRE(equals(str1, str2) == false);
        REQUIRE(equals(str2, str1) == false);
    }
}