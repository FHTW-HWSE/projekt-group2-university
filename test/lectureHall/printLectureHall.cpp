#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <sstream>
#include <cstdio>
#include <iostream>

TEST_CASE("Print lecture hall", "[lectureHall]") {

    char name[] = "D"; 
    int row = 15;
    int column = 25;
    lectureHall* hall = createLectureHall(name, row, column);

    std::stringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());
    printLectureHall(hall);
    std::cout.rdbuf(old_cout);

    REQUIRE(output.str() == "Raumname:         D\t Reihen:  15\t Spalten:  25\n");

    free(hall->name);
    free(hall);
}
