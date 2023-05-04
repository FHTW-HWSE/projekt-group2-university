#include "headerFiles/headers.h"
int main()
{

    struct tm my_time = {
        .tm_year = 121,   // year - 1900
        .tm_mon = 4,      // month (0 - 11)
        .tm_mday = 5,     // day of month (1 - 31)
        .tm_hour = 12,    // hour (0 - 23)
        .tm_min = 30,     // minute (0 - 59)
        .tm_sec = 0       // second (0 - 60)
    };
    char str[20];
    timeToString(&my_time, str, sizeof(str));
    printf("%s\n", str);
    printf("Projekt: Sitzplatzgenerator\n");
    writeCsv("assets/username.csv", "Hallowelt");
    readCsv("assets/username.csv");
    return 0;
}