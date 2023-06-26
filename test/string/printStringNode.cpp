#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <sstream>
#include <cstdio>
#include <iostream>

TEST_CASE("printStringNode prints the content of a string node", "[printStringNode]")
{
// Erstellt einen String-Knoten zum Testen
char* input = "Hello";
stringNode* node = createStringNode(input);

// Leitet die Standardausgabe in einen Puffer um
std::stringstream buffer;
std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

// Ruft die Funktion auf
printStringNode(node);

// Stellt die Standardausgabe wieder her
std::cout.rdbuf(old);

// Überprüft, ob der Puffer den erwarteten Inhalt enthält
REQUIRE(buffer.str() == "Hello world\n");
}