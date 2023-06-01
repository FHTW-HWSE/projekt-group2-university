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
    if (fpt == NULL)
    {
        return false;
    }
    fprintf(fpt, "\n%s", content);
    return true;
}
