// Einbinden des Catch2-Headers
#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Print empty string list") {
    REQUIRE(printStringList(NULL) == true);
}

TEST_CASE("Print string list with one stringNode") {
    stringNode s;
    strcpy(s.content, (char*)"Hello");
    s.nextStringNode = NULL;

    REQUIRE(printStringList(&s) == true);
}

TEST_CASE("Print string list with multiple stringNodes") {
    stringNode s1;
    strcpy(s1.content, (char*)"Hello");
    s1.nextStringNode = NULL;

    stringNode s2;
    strcpy(s2.content, (char*)"World");
    s2.nextStringNode = NULL;

    s1.nextStringNode = &s2;

    REQUIRE(printStringList(&s1) == true);
}