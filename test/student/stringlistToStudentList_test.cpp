#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Convert string list to student list") {

    char *string1 = (char*)"BB567432;Rick;Sanchez";
    char *string2 = (char*)"CC125634;Carlos;Klinge";
    char *string3 = (char*)"OO985623;Jimmy;Neutron";
    stringNode* stringList = createStringNode(string1);
    stringList->nextStringNode = createStringNode(string2);
    stringList->nextStringNode->nextStringNode = createStringNode(string3);
    student* studentList = nullptr;

    stringlistToStudentList(stringList, &studentList);

    REQUIRE(studentList != nullptr);
    REQUIRE(strcmp(studentList->id, "BB567432") == 0);
    REQUIRE(strcmp(studentList->firstName, "Rick") == 0);
    REQUIRE(strcmp(studentList->lastName, "Sanchez") == 0);
    REQUIRE(studentList->nextStudent != nullptr);
    REQUIRE(strcmp(studentList->nextStudent->id, "CC125634") == 0);
    REQUIRE(strcmp(studentList->nextStudent->firstName, "Carlos") == 0);
    REQUIRE(strcmp(studentList->nextStudent->lastName, "Klinge") == 0);
    REQUIRE(studentList->nextStudent->nextStudent != nullptr);
    REQUIRE(strcmp(studentList->nextStudent->nextStudent->id, "OO985623") == 0);
    REQUIRE(strcmp(studentList->nextStudent->nextStudent->firstName, "Jimmy") == 0);
    REQUIRE(strcmp(studentList->nextStudent->nextStudent->lastName, "Neutron") == 0);

    freeStudentList(studentList);
    freeStringList(stringList);
}