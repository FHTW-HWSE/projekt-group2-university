#include "../headerFiles/headers.h"


stringNode *createStringNode(char *content)
{
    stringNode *newStringNode = (stringNode *) calloc(1, sizeof(stringNode*));
    //newStringNode->content = content;
    newStringNode->content = (char*) malloc(100*sizeof(char));
    strcpy(newStringNode->content, content);
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
        printf("%s\n",head->content);
        head = head->nextStringNode;
    }
}
