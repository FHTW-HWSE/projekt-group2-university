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

 bool checkIDFormat(char *id){
    
    if(strlen(id)!=8){
        return false;
    }

    if(!isalpha(id[0]) || !isalpha(id[1])){
        return false;
    }
    for(int i=2; i<8;i++){
        if(!isdigit(id[i])){
            return false;
        }
    }
    return true;

 }


// ALLES WAS MIT ZEIT ZU TUN HAT

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

//ALLES WAS MIT ZEIT ZU TUN HAT ENDE

char* integerToString(int num) {
    // Determine the length of the integer
    int length = snprintf(NULL, 0, "%d", num);

    // Allocate memory for the string representation
    char *str = (char*) malloc((length + 1) * sizeof(char));

    // Convert the integer to a string
    snprintf(str, length + 1, "%d", num);

    return str;
}

bool fileExists (char *filename) {
  struct stat buffer;   
  return (stat (filename, &buffer) == 0);
}