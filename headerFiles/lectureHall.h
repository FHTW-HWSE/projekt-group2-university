#ifndef LECTUREHALL_H // Include guard
#define LECTUREHALL_H
#include "string_list.h"
typedef struct lectureHall
{
    char *name;
    int row;
    int column;
    struct lectureHall *nextLectureHall;
} lectureHall;

lectureHall *createLectureHall(char *name, int row, int column);

void printLectureHall(lectureHall *lectureHall);

lectureHall *searchLectureHall(lectureHall* head, char *name);

bool insertIntoLectureHallList(lectureHall **list, lectureHall *newLectureHall, bool csvflag); // Update to be alphabetisch

void printLectureHallList(lectureHall *head);

void stringlistToLectureHallList(stringNode *stringList, lectureHall **lectureHallList);

lectureHall *createLectureHallFromString(char *string);

void freeLectureHallList(lectureHall *head);

#endif