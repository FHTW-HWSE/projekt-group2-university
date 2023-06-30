#ifndef STRING_LIST_H // Include guard
#define STRING_LIST_H

#define STRING_MAX 100
typedef struct stringNode
{
   char content[STRING_MAX];
   stringNode *nextStringNode;
} stringNode;

stringNode *createStringNode(char *content);

bool printStringNode(stringNode *stringNode);

bool insertIntoStringList(stringNode **list, stringNode *newStringNode);

bool printStringList(stringNode *head);

bool freeStringList(stringNode *head);


#endif