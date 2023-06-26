#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <sstream>
#include <cstdio>
#include <iostream>


TEST_CASE("Print lecture hall list", "[lectureHall]") {
    char* name1 = "R";
    char* name2 = "S";
    char* name3 = "T";
    int row = 10;
    int column = 20;
    lectureHall* head = createLectureHall(name1, row, column);
    head->nextLectureHall = createLectureHall(name2, row, column);
    head->nextLectureHall->nextLectureHall = createLectureHall(name3, row, column);

    std::stringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());
    printLectureHallList(head);

    std::cout.rdbuf(old_cout);

    std::string expectedOutput = "\tListe aller Räume\n";
    expectedOutput += "Raumname:         R\t Reihen:  10\t Spalten:  20\n";
    expectedOutput += "Raumname:         S\t Reihen:  10\t Spalten:  20\n";
    expectedOutput += "Raumname:         T\t Reihen:  10\t Spalten:  20\n";
    expectedOutput += "\n";

    REQUIRE(output.str() == expectedOutput);
}
