#include "../headerFiles/headers.h"

int readCsv(char *filename) {
    FILE *fp;
    char row[100];
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Fehler");
        EXIT_FAILURE;
    }
    while (feof(fp) != true)
    {
        fgets(row, 100, fp);
        printf("Row: %s", row);
    }
    return 0;
}