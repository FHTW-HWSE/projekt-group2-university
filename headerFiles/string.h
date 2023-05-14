#ifndef STRING_H // Include guard
#define STRING_H


typedef struct stringNode
{
   char* content;
   stringNode *nextStringNode;
} stringNode;

stringNode *createStringNode(char *content);

void printStringNode(stringNode *stringNode);

void insertIntoStringList(stringNode **list, stringNode *newStringNode);

void printStringList(stringNode *head);

#endif