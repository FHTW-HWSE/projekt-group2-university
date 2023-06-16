#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

// Test case for inserting a student into an empty list
TEST_CASE("Insert student into empty list") {
    student *list = NULL;
    student *newStudent = new student;
    newStudent->lastName = "Smith";
    newStudent->nextStudent = NULL;

    bool result = insertStudentIntoList(&list, newStudent);

    // Verify that the student was inserted successfully
    REQUIRE(result == true);
    REQUIRE(list == newStudent);
}

// Test case for inserting a student with a unique last name
TEST_CASE("Insert student with unique last name") {
    student *list = NULL;
    student *existingStudent = new student;
    existingStudent->lastName = "Smith";
    existingStudent->nextStudent = NULL;
    list = existingStudent;

    student *newStudent = new student;
    newStudent->lastName = "Johnson";
    newStudent->nextStudent = NULL;

    bool result = insertStudentIntoList(&list, newStudent);

    // Verify that the student was inserted successfully
    REQUIRE(result == true);
    REQUIRE(existingStudent->nextStudent == newStudent);
}

// Test case for inserting a student with a duplicate last name
TEST_CASE("Insert student with duplicate last name") {
    student *list = NULL;
    student *existingStudent = new student;
    existingStudent->lastName = "Smith";
    existingStudent->nextStudent = NULL;
    list = existingStudent;

    student *newStudent = new student;
    newStudent->lastName = "Smith";
    newStudent->nextStudent = NULL;

    bool result = insertStudentIntoList(&list, newStudent);

    // Verify that the student was not inserted
    REQUIRE(result == false);
    REQUIRE(existingStudent->nextStudent == NULL);
}

