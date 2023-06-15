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
    int studentcounter;
    int maxStudents;
    student* students[];
} exam;

exam *createExam(char *name, int workload, lectureHall *lectureHall);

void printExam(exam *exam);

bool insertIntoExamList(exam **list, exam *newExam, bool csvflag);	//Update to be alphabetisch

void printExamList(exam *head);

exam *searchExam(exam *head, char *name);

exam *createExamFromString(char *string, lectureHall *lectureHallList);

void stringlistToExamList(stringNode *stringList, exam **examList,  lectureHall *lectureHallList);

void freeExamList(exam *head);

bool insertStudentIntoExam(student *student, exam *exam);

void printExamRoom(exam *exam);

#endif