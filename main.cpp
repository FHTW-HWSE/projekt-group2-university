#include "headerFiles/headers.h"
int main()
{

   
    char str[20];
    printf("%s\n", str);
    printf("Projekt: Sitzplatzgenerator\n");
    writeCsv("assets/username.csv", "Hallowelt");
    readCsv("assets/username.csv");
    return 0;
}