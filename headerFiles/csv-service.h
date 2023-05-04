#ifndef CSVSERVICE_H // Include guard
#define CSVSERVICE_H


#include "headers.h"

bool readCsv(char *filepath);

bool writeCsv(char *filename, char *line);
#endif