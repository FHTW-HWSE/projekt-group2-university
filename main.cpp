#include "headerFiles/headers.h"
int main()
{

    


    /* writeCsv((char *)"assets/username.csv", (char *)"Hallowelt");
    stringNodereadCsv((char *)"assets/username.csv"); */

  

    //char *date_string = (char *)"2023-05-13 12:34:56";
    //time_t *date = stringToTime(date_string);
    //printf("%s\n", date_string);


    //stringNode *list = readCsv((char *)"assets/username.csv");
    //printStringList(list);

    stringNode *head = (stringNode*)malloc(sizeof(stringNode*));
    head = NULL;

    stringNode *a = createStringNode((char *)"Hallo");
    stringNode *b = createStringNode((char *) "Hdedllo");
    stringNode *c = createStringNode((char *) "Hallededeo");

    insertIntoStringList(&head, a);
    insertIntoStringList(&head, b);
    insertIntoStringList(&head, c);
    printStringList(head);


    stringNode *newlist = (stringNode*)calloc(1, sizeof(stringNode*));
    writeCsv((char*)"assets/username.csv", head);

    printStringList(newlist);


    return 0;
}