#ifndef CSVSERVICE_H // Include guard
#define CSVSERVICE_H


#include "headers.h"

void readCsv(char *filepath, stringNode **list);

bool writeCsv(char *filename, stringNode *list);
#endif