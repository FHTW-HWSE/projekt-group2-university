#ifndef EXAM_H // Include guard
#define EXAM_H


#include "headers.h"

typedef struct exam
{
    char *name;
    struct lectureHall *lectureHall;
    struct exam *nextExam;
} exam;

#endif