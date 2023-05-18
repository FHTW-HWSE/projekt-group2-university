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

   if(*list == NULL) {
    *list = newStringNode;
    return;
   }

        stringNode *current = *list;

        //last node's next address will be NULL.
        while(current->nextStringNode != NULL)
        {
            current = current->nextStringNode;
        }

        //add the newNode at the end of the linked list
        current->nextStringNode = newStringNode;
      
}


void printStringList(stringNode *head)
{
     while(head->nextStringNode!=NULL){
        if(head->content != NULL) {
            printf("%s",head->content);
            head = head->nextStringNode;
        }
        
    }
        printf("%s\n",head->content);
}

void freeStringList(stringNode *head) {
    stringNode* tmp;
    while(head != NULL) {
        tmp = head->nextStringNode;
        free(head);
        head = tmp;
    }
}