// Einbinden des Catch2-Headers
#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"
#include <sstream>
#include <cstdio>
#include <iostream>

TEST_CASE("printStringList prints the content of a list of string nodes", "[printStringList]")
{
// Erstellt eine Liste von stringNodes mit den Inhalten "Hello", " ", "world" und "!"
stringNode node1;
strcpy(node1.content, "Hello");
stringNode node2;
strcpy(node2.content, " ");
stringNode node3;
strcpy(node3.content, "world");
stringNode node4;
strcpy(node4.content, "!");

node1.nextStringNode = &node2;
node2.nextStringNode = &node3;
node3.nextStringNode = &node4;
node4.nextStringNode = NULL;

// Leitet die Standardausgabe in einen Puffer um
std::stringstream buffer;
std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

// Ruft die Funktion printStringList auf
printStringList(&node1);

// Stellt die Standardausgabe wieder her
std::cout.rdbuf(old);

// Überprüft, ob der Puffer den erwarteten Inhalt enthält
REQUIRE(buffer.str() == "Hello world!\n");
}