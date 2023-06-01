#ifndef EXAM_H // Include guard
#define EXAM_H

#define strong 2
#define medium 1
#define weak 0

#include "headers.h"

typedef struct exam
{
    char *name;
    int workload; 
    struct lectureHall *lectureHall;
    struct exam *nextExam;
} exam;

exam *createExam(char *name, int workload, lectureHall *lectureHall);

void printExam(exam *exam);

void insertIntoExamList(exam **list, exam *newExam, bool csvflag);	//Update to be alphabetisch


#endif