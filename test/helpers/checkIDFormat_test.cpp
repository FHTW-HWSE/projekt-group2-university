#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"


TEST_CASE("checkIDFormat function tests", "[checkIDFormat]") {
    SECTION("Valid ID format") {
        char id1[] = "AB123456";
        REQUIRE(checkIDFormat(id1) == true);

        char id2[] = "CD789012";
        REQUIRE(checkIDFormat(id2) == true);
    }

    SECTION("Invalid ID format") {
        char id1[] = "12345678"; // Starts with a digit
        REQUIRE(checkIDFormat(id1) == false);

        char id2[] = "ABCD"; // Too short
        REQUIRE(checkIDFormat(id2) == false);

        char id3[] = "ABC1234X"; // Contains a non-digit character
        REQUIRE(checkIDFormat(id3) == false);
    }
}