#include <catch2/catch.hpp>
#include "../../headerFiles/headers.h"

TEST_CASE("createStringNode creates a string node with the given content", "[createStringNode]")
{
    SECTION("Valid content")
    {
        const char *content = "Hello, World!";
        stringNode *node = createStringNode(const_cast<char*>(content));
        REQUIRE(node != nullptr);
        REQUIRE(strcmp(node->content, content) == 0);
        REQUIRE(node->nextStringNode == nullptr);
        free(node);
    }

    SECTION("Empty content")
    {
        const char *content = "";
        stringNode *node = createStringNode(const_cast<char*>(content));
        REQUIRE(node != nullptr);
        REQUIRE(strcmp(node->content, content) == 0);
        REQUIRE(node->nextStringNode == nullptr);
        free(node);
    }

    /*
    SECTION("Content exceeding STRING_MAX")
    {
        const char *content = "This is a very long string that exceeds the maximum length AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA AAAAAAAAAAAAAaaaaaaa";
        stringNode *node = createStringNode(const_cast<char*>(content));
        REQUIRE(node != nullptr);
        REQUIRE(strcmp(node->content, content) != 0); 
        REQUIRE(strlen(node->content) == STRING_MAX - 1);
        REQUIRE(node->nextStringNode == nullptr);
        free(node);
    }
    */
}