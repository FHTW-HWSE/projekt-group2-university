#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("createExam creates a new Exam object", "[createExam]")
{
    lectureHall *hall = (lectureHall *)malloc(sizeof(lectureHall));
    hall->name = (char *)"ZZZZ";
    hall->row = 5;
    hall->column = 10;

    exam *newExam = createExam((char *)"TEST", 50, hall);

    REQUIRE(newExam->name == std::string("TEST"));
    REQUIRE(newExam->workload == 50);
    REQUIRE(newExam->lectureHall == hall);
    REQUIRE(newExam->studentcounter == 0);
    REQUIRE(newExam->maxStudents == 50);

    free(newExam->name);
    free(newExam->lectureHall);
    free(newExam);
}