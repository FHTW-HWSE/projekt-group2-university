#ifndef LECTUREHALL_H // Include guard
#define LECTUREHALL_H
#include "string_list.h"

#define LECTUREHALL_FILE 30
typedef struct lectureHall
{
    char *name;
    int row;
    int column;
    struct lectureHall *nextLectureHall;
} lectureHall;

lectureHall *createLectureHall(char *name, int row, int column);

bool printLectureHall(lectureHall *lectureHall);

lectureHall *searchLectureHall(lectureHall* head, char *name);

bool insertIntoLectureHallList(lectureHall **list, lectureHall *newLectureHall, bool csvflag); // Update to be alphabetisch

bool printLectureHallList(lectureHall *head);

bool stringlistToLectureHallList(stringNode *stringList, lectureHall **lectureHallList);

lectureHall *createLectureHallFromString(char *string);

bool freeLectureHallList(lectureHall *head);

#endif