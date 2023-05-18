#include "../headerFiles/headers.h"

void readCsv(char *filepath, stringNode **list) {
    FILE *fp;
    char row[100];
    fp = fopen(filepath, "r");
    if(fp == NULL) {
        return ;
    }
    while (feof(fp) != true)
    {
        fgets(row, 100, fp);
        insertIntoStringList(list, createStringNode(row));
    }
    fclose(fp);
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

