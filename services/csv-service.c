#include "../headerFiles/headers.h"

bool readCsv(char *filepath) {
    FILE *fp;
    char row[100];
    fp = fopen(filepath, "r");
    if(fp == NULL) {
        return false;
    }
    while (feof(fp) != true)
    {
        fgets(row, 100, fp);
        printf("Row: %s", row);
    }
    fclose(fp);
    printf("\n");
    return true;
}

bool writeCsv(char *filename, char *line) {
    FILE *fpt;
    fpt = fopen(filename, "a");
    if(fpt == NULL) {
        return false;
    }
    fprintf(fpt,"%s\n", line);
    fclose(fpt);
    return true;
}

