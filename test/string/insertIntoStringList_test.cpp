#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Insert into empty string list") {
    stringNode* list = NULL;
    stringNode s;
    strcpy(s.content, (char*)"Hello");
    s.nextStringNode = NULL;

    REQUIRE(insertIntoStringList(&list, &s) == true);
    REQUIRE(list == &s);
}

TEST_CASE("Insert into non-empty string list at beginning") {
    stringNode* list = NULL;

    stringNode s1;
    strcpy(s1.content, (char*)"Hello");
    s1.nextStringNode = NULL;

    stringNode s2;
    strcpy(s2.content, (char*)"Apple");
    s2.nextStringNode = NULL;

    insertIntoStringList(&list, &s1);
    REQUIRE(insertIntoStringList(&list, &s2) == true);
}

TEST_CASE("Insert into non-empty string list at the end") {
    stringNode* list = NULL;

    stringNode s1;
    strcpy(s1.content, (char*)"Apple");
    s1.nextStringNode = NULL;

    stringNode s2;
    strcpy(s2.content, (char*)"Banana");
    s2.nextStringNode = NULL;

    stringNode s3;
    strcpy(s3.content, (char*)"Hello");
    s3.nextStringNode = NULL;

    insertIntoStringList(&list, &s1);
    insertIntoStringList(&list, &s2);
    REQUIRE(insertIntoStringList(&list, &s3) == true);
    REQUIRE(list == &s1);
    REQUIRE(s1.nextStringNode == &s2);
    REQUIRE(s2.nextStringNode == &s3);
}