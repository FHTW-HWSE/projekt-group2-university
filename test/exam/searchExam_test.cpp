#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <cstring>

TEST_CASE("Search existing exam", "[searchExam]") {
    // Create some sample exams
    exam* exam1 = new exam;
    exam1->name = (char*)"Exam1";
    exam1->nextExam = nullptr;

    exam* exam2 = new exam;
    exam2->name = (char*)"Exam2";
    exam2->nextExam = nullptr;

    exam* exam3 = new exam;
    exam3->name = (char*)"Exam3";
    exam3->nextExam = nullptr;

    // Build the exam linked list
    exam1->nextExam = exam2;
    exam2->nextExam = exam3;

    // Search for an existing exam
    exam* result = searchExam(exam1, (char*)"Exam2");

    // Assert that the exam was found
    REQUIRE(result != nullptr);
    REQUIRE(std::strcmp(result->name, (char*)"Exam2") == 0);
}

TEST_CASE("Search non-existing exam", "[searchExam]") {
    // Create some sample exams
    exam* exam1 = new exam;
    exam1->name = (char*)"Exam1";
    exam1->nextExam = nullptr;

    exam* exam2 = new exam;
    exam2->name = (char*)"Exam2";
    exam2->nextExam = nullptr;

    exam* exam3 = new exam;
    exam3->name = (char*)"Exam3";
    exam3->nextExam = nullptr;

    // Build the exam linked list
    exam1->nextExam = exam2;
    exam2->nextExam = exam3;

    // Search for a non-existing exam
    exam* result = searchExam(exam1, (char*)"Exam4");

    // Assert that the exam was not found
    REQUIRE(result == nullptr);
}