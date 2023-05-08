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

void timeToString(struct tm *timeptr, char *str, size_t max_len) {
    strftime(str, max_len, "%Y-%m-%d %H:%M:%S", timeptr);
}

char* stringToTime(time_t *time) {
    return asctime(gmtime(time));
}
