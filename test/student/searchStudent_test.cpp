#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"


TEST_CASE("Search student in a non-empty list") {

    char *id1 = (char*)"TT345678";
    char *firstName1 = (char*)"John";
    char *lastName1 = (char*)"Doe";

    char *id2 = (char*)"TT987654";
    char *firstName2 = (char*)"Alice";
    char *lastName2 = (char*)"Wonderland";

    student* head = createStudent(id1, firstName1, lastName1);
    head->nextStudent = createStudent(id2, firstName2, lastName2);

    student* result1 = searchStudent(head, id1);
    student* result2 = searchStudent(head, id2);

    REQUIRE(result1 != nullptr);
    REQUIRE(strcmp(result1->id, id1) == 0);
    REQUIRE(result2 != nullptr);
    REQUIRE(strcmp(result2->id, id2) == 0);

    freeStudentList(head);
}

TEST_CASE("Search student in an empty list") {
    char *id = (char*)"TT123456";
    student* head = nullptr;

    student* result = searchStudent(head, id);

    REQUIRE(result == nullptr);
}

TEST_CASE("Search student with a non-existing id") {

    char *id1 = (char*)"TT654321";
    char *firstName1 = (char*)"John";
    char *lastName1 = (char*)"Doe";
    char *id2 = (char*)"TT898797";
    
    student* head = createStudent(id1, firstName1, lastName1);

    student* result = searchStudent(head, id2);

    REQUIRE(result == nullptr);

    freeStudentList(head);
}