#include "headerFiles/headers.h"
int main()
{

    


    /* writeCsv((char *)"assets/username.csv", (char *)"Hallowelt");
    readCsv((char *)"assets/username.csv"); */

     char* str = (char*) "Sun May 14 17:55:51 2023";

     time_t *a = stringToTime(str);

     char *result = timeToString(a);

     printf("%s", result);

    //char *date_string = (char *)"2023-05-13 12:34:56";
    //time_t *date = stringToTime(date_string);
    //printf("%s\n", date_string);

    return 0;
}