#include "../headerFiles/headers.h"

bool readCsv(char *filepath, stringNode **list)
{
    FILE *fp;
    char row[STRING_MAX];
    fp = fopen(filepath, "r");
    if (fp == NULL)
    {
        return false;
    }
    while (feof(fp) != true)
    {
        fgets(row, STRING_MAX, fp);
        insertIntoStringList(list, createStringNode(row));
    }
    fclose(fp);
    return true;
}

bool writeCsv(char *filename, stringNode *list)
{
    FILE *fpt;
    fpt = fopen(filename, "a");
    if (fpt == NULL)
    {
        return false;
    }
    while (list != NULL)
    {
        fprintf(fpt, "%s", list->content);
        list = list->nextStringNode;
    }
    fclose(fpt);
    return true;
}

bool writeLineInCsv(char *filename, char *content)
{
    FILE *fpt;
    fpt = fopen(filename, "a");
    fseek (fpt, 0, SEEK_END);
    long size = ftell(fpt);

    if (fpt == NULL)
    {
        return false;
    }

    if(size == 0) {
        fprintf(fpt, "%s", content);
    } else {
        fprintf(fpt, "\n%s", content);
    }
    fclose(fpt);
    return true;
}
