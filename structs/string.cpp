#include "../headerFiles/headers.h"


stringNode *createStringNode(char *content)
{
    stringNode *newStringNode = (stringNode *) calloc(1, sizeof(stringNode*));
    newStringNode->content = content;
    return newStringNode;
}


void printStringNode(stringNode *stringNode)
{
    printf("%s\n", stringNode->content);
}

void insertIntoStringList(stringNode **list, stringNode *newStringNode)	//Update to be alphabetisch
{

  //printStringNode(newStringNode);
  newStringNode->nextStringNode = *list;
  //changing the new head to this freshly entered node
  *list = newStringNode;
}


void printStringList(stringNode *head)
{
     while(head!=NULL){
        printf("%s\t",head->content);
        head = head->nextStringNode;
    }
    printf("\n");
}
