#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("insertStudentIntoList function tests", "[insertStudentIntoList]") {
    student* list = nullptr;

    SECTION("Insert first student into empty list") {
        student* newStudent = new student;
        newStudent->id = strdup("12345678");
        newStudent->firstName = strdup("John");
        newStudent->lastName = strdup("Doe");
        newStudent->nextStudent = nullptr;

        bool result = insertStudentIntoList(&list, newStudent, false);

        REQUIRE(result == true);
        REQUIRE(list != nullptr);
        REQUIRE(list->id == newStudent->id);
        REQUIRE(list->firstName == newStudent->firstName);
        REQUIRE(list->lastName == newStudent->lastName);
        REQUIRE(list->nextStudent == nullptr);
    }

    SECTION("Insert student with existing ID") {
        student* existingStudent = new student;
        existingStudent->id = strdup("12345678");
        existingStudent->firstName = strdup("Jane");
        existingStudent->lastName = strdup("Smith");
        existingStudent->nextStudent = nullptr;
        list = existingStudent;

        student* newStudent = new student;
        newStudent->id = strdup("12345678");
        newStudent->firstName = strdup("John");
        newStudent->lastName = strdup("Doe");
        newStudent->nextStudent = nullptr;

        bool result = insertStudentIntoList(&list, newStudent, false);

        REQUIRE(result == false);
    }

    SECTION("Insert student at the end of the list") {
        student* student1 = new student;
        student1->id = strdup("12345678");
        student1->firstName = strdup("John");
        student1->lastName = strdup("Doe");
        student1->nextStudent = nullptr;
        list = student1;

        student* student2 = new student;
        student2->id = strdup("87654321");
        student2->firstName = strdup("Jane");
        student2->lastName = strdup("Smith");
        student2->nextStudent = nullptr;
        student1->nextStudent = student2;

        student* newStudent = new student;
        newStudent->id = strdup("98765432");
        newStudent->firstName = strdup("Alice");
        newStudent->lastName = strdup("Johnson");
        newStudent->nextStudent = nullptr;

        bool result = insertStudentIntoList(&list, newStudent, false);

        REQUIRE(result == true);
        REQUIRE(student2->nextStudent == newStudent);
        REQUIRE(newStudent->nextStudent == nullptr);
    }
}

