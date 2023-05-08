#ifndef HELPERS_H // Include guard
#define HELPERS_H

bool equals(char *a, char *b);

long int generateRandomId();

void timeToString(struct tm *timeptr, char *str, size_t max_len);

char* stringToTime(time_t *time);

#endif