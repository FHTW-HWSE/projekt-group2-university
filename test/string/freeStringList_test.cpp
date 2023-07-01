#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Free empty string list") {
    REQUIRE(freeStringList(NULL) == true);
}

TEST_CASE("Free string list with one stringNode") {
    stringNode* s = (stringNode*)malloc(sizeof(stringNode));
    strcpy(s->content, (char*)"Hello");
    s->nextStringNode = NULL;

    REQUIRE(freeStringList(s) == true);
}

TEST_CASE("Free string list with multiple stringNodes") {
    stringNode* s1 = (stringNode*)malloc(sizeof(stringNode));
    strcpy(s1->content, (char*)"Hello");
    s1->nextStringNode = NULL;

    stringNode* s2 = (stringNode*)malloc(sizeof(stringNode));
    strcpy(s2->content, (char*)"World");
    s2->nextStringNode = NULL;

    s1->nextStringNode = s2;

    REQUIRE(freeStringList(s1) == true);
}