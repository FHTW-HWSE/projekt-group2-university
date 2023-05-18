#ifndef STRING_LIST_H // Include guard
#define STRING_LIST_H


typedef struct stringNode
{
   char* content;
   stringNode *nextStringNode;
} stringNode;

stringNode *createStringNode(char *content);

void printStringNode(stringNode *stringNode);

void insertIntoStringList(stringNode **list, stringNode *newStringNode);

void printStringList(stringNode *head);

void freeStringList(stringNode *head);


#endif