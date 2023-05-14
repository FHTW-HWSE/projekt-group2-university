#include "headerFiles/headers.h"

/**
 * @brief compares if 2 Strings are equal or not
 * 
 * @param a first String to compare
 * @param b second String to compare
 * @return true if a and b contain the same message
 * @return false if a and b are not the same
 */
bool equals(char *a, char *b) {
    return strcmp(a, b) == 0;
}

/**
 * @brief generated a Random ID
 * 
 * @return long int new Random ID
 */
long int generateRandomId()
{
    return 0;   //muss noch angepasst werden
}


char* timeToString(time_t *time) {
    return asctime(gmtime(time));
}

bool checkIfFormatMatch(char *string, char *format) {
    struct tm time_info;
    return (strptime(string, format, &time_info) != NULL);
}

time_t *stringToTime(char* str) {
    struct tm tm_time = {0};
    strptime(str, "%a %b %d %H:%M:%S %Y", &tm_time);
    time_t timestamp = mktime(&tm_time);
    time_t *result = &timestamp;
    return result;
}


