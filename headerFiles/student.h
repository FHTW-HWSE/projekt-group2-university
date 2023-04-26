#ifndef STUDENT_H // Include guard
#define STUDENT_H


#define MAX_DIREKT 8
#define MAX_INDIREKT 16

typedef struct student
{
    long int id;
    char *firstName;
    char *lastName;
    char *seat;
    struct student *direktSeatNeighbors[MAX_DIREKT];
    struct student *indirektSeatNeighbors[MAX_INDIREKT];
    struct student *nextStudent;
} student;

student *createStudent(char *firstName, char *lastName);

student *insertStudentIntoList(student *list, student *newStudent);

void printStudent(student *student);

void printStudentList(student *head);


#endif