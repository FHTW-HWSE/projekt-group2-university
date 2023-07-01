#include "../headerFiles/headers.h"


stringNode *createStringNode(char *content)
{
    stringNode *newStringNode = (stringNode *) calloc(1, sizeof(stringNode));
    int i=0;
    while(content[i] != '\0') {
        newStringNode->content[i] = content[i];
        i++;
    }
    //content[i+1] = '\0';
    newStringNode->content[i] = '\0';
    newStringNode->nextStringNode = NULL;
    //newStringNode->content = (char*) malloc(STRING_MAX * sizeof(char));
    //strcpy(newStringNode->content, content);
    return newStringNode;
}


bool printStringNode(stringNode *stringNode)
{
    printf("%s\n", stringNode->content);
    return true;
}

bool insertIntoStringList(stringNode **list, stringNode *newStringNode)	//Update to be alphabetisch
{

   if(*list == NULL) {
    *list = newStringNode;
    return true;
   }

        stringNode *current = *list;

        //last node's next address will be NULL.
        while(current->nextStringNode != NULL)
        {
            current = current->nextStringNode;
        }

        //add the newNode at the end of the linked list
        current->nextStringNode = newStringNode;
        return true;
      
}


bool printStringList(stringNode *head)
{
     while(head!=NULL){
        if(head->content != NULL) {
            printf("%s",head->content);
            head = head->nextStringNode;
        }
    }
        printf("\n");
        return true;
}

bool freeStringList(stringNode *head) {
    stringNode* tmp;
    while(head != NULL) {
        tmp = head->nextStringNode;
        free(head);
        head = tmp;
    }
    free(head);
    return true;
}