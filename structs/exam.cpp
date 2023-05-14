#include "../headerFiles/headers.h"

/**
 * @brief Create a Exam object
 * 
 * @param name name of the exam
 * @param lectureHall the Lecture Hall in which the Exam is hold
 * @return exam* new Exam Object
 */
exam *createExam(char *name, lectureHall *lectureHall) {
    exam *newExam = (exam *) calloc(1, sizeof(exam *));
    newExam->name = name;
    newExam->lectureHall = lectureHall;
    return newExam;
}

/**
 * @brief prints a Exam
 * 
 * @param exam the Exam to print
 */
void printExam(exam *exam) {
    printf("%s\n", exam->name);
}