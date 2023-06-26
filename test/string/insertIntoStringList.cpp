#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("Insert into String List", "[insertIntoStringList]") {
    stringNode* list = nullptr;

    stringNode* node1 = new stringNode{"Node 1", nullptr};
    stringNode* node2 = new stringNode{"Node 2", nullptr};
    stringNode* node3 = new stringNode{"Node 3", nullptr};

    SECTION("Inserting into string list") {
        insertIntoStringList(&list, node2);
        insertIntoStringList(&list, node1);
        insertIntoStringList(&list, node3);

        REQUIRE(list == node1);
        REQUIRE(node1->nextStringNode == node2);
        REQUIRE(node2->nextStringNode == node3);
        REQUIRE(node3->nextStringNode == nullptr);
    }

    delete node1;
    delete node2;
    delete node3;
}