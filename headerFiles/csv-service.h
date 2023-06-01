#ifndef CSVSERVICE_H // Include guard
#define CSVSERVICE_H


#include "headers.h"

bool readCsv(char *filepath, stringNode **list);

bool writeCsv(char *filename, stringNode *list);

bool writeLineInCsv(char *filename, char *content);

#endif