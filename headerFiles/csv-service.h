#ifndef CSVSERVICE_H // Include guard
#define CSVSERVICE_H


#include "headers.h"

stringNode *readCsv(char *filepath);

bool writeCsv(char *filename, stringNode *list);
#endif