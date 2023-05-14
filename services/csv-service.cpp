#include "../headerFiles/headers.h"

stringNode *readCsv(char *filepath) {
    stringNode *list = (stringNode*) malloc(sizeof(stringNode*));
    FILE *fp;
    char row[100];
    fp = fopen(filepath, "r");
    if(fp == NULL) {
        return NULL;
    }
    while (feof(fp) != true)
    {
        fgets(row, 100, fp);
        stringNode *tmp = createStringNode((char*) row);
        printStringNode(tmp);
        insertIntoStringList(&list, tmp);
        //printf("Row: %s", row);
    }
    fclose(fp);
    printStringList(list);
    return list;
}

bool writeCsv(char *filename, stringNode *list) {
    FILE *fpt;
    fpt = fopen(filename, "a");
    if(fpt == NULL) {
        return false;
    }
    printStringList(list);
    while(list != NULL) {
        fprintf(fpt,"%s\n", list->content);
        list = list->nextStringNode;
    }
    fclose(fpt);
    return true;
}

