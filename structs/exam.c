#include "../headerFiles/headers.h"

exam *createExam(char *name, lectureHall *lectureHall) {
    exam *newExam = calloc(1, sizeof(exam *));
    newExam->name = name;
    newExam->lectureHall = lectureHall;
    return newExam;
}

void printExam(exam *exam) {
    printf("%s\n", exam->name);
}