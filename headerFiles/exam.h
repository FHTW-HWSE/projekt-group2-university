#ifndef EXAM_H // Include guard
#define EXAM_H

#define STRONG 2
#define MEDIUM 1
#define WEAK 0
#define EXAM_FILE 50

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

bool printExam(exam *exam);

bool insertIntoExamList(exam **list, exam *newExam, bool csvflag);	//Update to be alphabetisch

bool printExamList(exam *head);

exam *searchExam(exam *head, char *name);

exam *createExamFromString(char *string, lectureHall *lectureHallList);

bool stringlistToExamList(stringNode *stringList, exam **examList,  lectureHall *lectureHallList);

bool freeExamList(exam *head);

bool insertStudentIntoExam(student *student, exam *exam);

bool printExamRoom(exam *exam);

#endif