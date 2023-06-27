#ifndef HELPERS_H // Include guard
#define HELPERS_H

#include "exam.h"

bool equals(char *a, char *b);

bool checkIDFormat(char *id);

char* timeToString(time_t *time);

time_t *stringToTime(char* str);

bool checkIfFormatMatch(char *string, char *format);

char* integerToString(int num);

bool fileExists (char *filename);

int getMaxStudentsFromLecturehall(lectureHall *lectureHall);

int getAmountFromWorkload(int amount, int workload);

bool examIsFull(exam *exam);

int countCharInString(char *string, char character);
#endif