#include "headerFiles/headers.h"
int main()
{
    printf("Projekt: Sitzplatzgenerator\n");
    writeCsv("assets/username.csv", "Hallowelt");
    readCsv("assets/username.csv");
    return 0;
}