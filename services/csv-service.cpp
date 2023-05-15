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
        //printStringNode(tmp);
        insertIntoStringList(&list, createStringNode((char*) row));
        //printf("Row: %s", row);
    }
    fclose(fp);
    //printStringList(list);
    return list;
}

bool writeCsv(char *filename, stringNode *list) {
    FILE *fpt;
    fpt = fopen(filename, "a");
    if(fpt == NULL) {
        return false;
    }
    while(list != NULL) {
        fprintf(fpt,"%s\n", list->content);
        list = list->nextStringNode;
    }
    fclose(fpt);
    return true;
}

