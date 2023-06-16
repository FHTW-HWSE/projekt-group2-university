#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("getAmountFromWorkload function tests", "[getAmountFromWorkload]") {
    SECTION("Workload 0") {
        int result = getAmountFromWorkload(20, 0);
        REQUIRE(result == 5);
    }

    SECTION("Workload 1") {
        int result = getAmountFromWorkload(30, 1);
        REQUIRE(result == 15);
    }

    SECTION("Workload other than 0 or 1") {
        int result = getAmountFromWorkload(40, 2);
        REQUIRE(result == 40);
    }
}