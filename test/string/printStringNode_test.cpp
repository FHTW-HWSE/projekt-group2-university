#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print valid stringNode", "[printStringNode]") {
    stringNode s;
    strcpy(s.content, "Hello, world!");
    s.nextStringNode = NULL;

    REQUIRE(printStringNode(&s) == true);
}