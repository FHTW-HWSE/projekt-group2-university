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

    stringNode *a = createStringNode((char *)"mein");
    stringNode *b = createStringNode((char *) "name");
    stringNode *c = createStringNode((char *) "ist");

    insertIntoStringList(&head, a);
    insertIntoStringList(&head, b);
    insertIntoStringList(&head, c);


    //stringNode *newlist = (stringNode*)calloc(1, sizeof(stringNode*));
    //writeCsv((char*)"assets/username.csv", head);

    //readCsv((char*)"assets/username.csv");
    //printStringList(head);

    
    stringNode *test = (stringNode*)malloc(sizeof(stringNode*));
    test = NULL;
    readCsv((char*)"../assets/username.csv", &test);
    printStringList(test);
    return 0;
}