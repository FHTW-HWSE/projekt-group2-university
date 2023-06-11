#ifndef STUDENT_H // Include guard
#define STUDENT_H


#define MAX_DIREKT 8
#define MAX_INDIREKT 16
#define IDLENGTH 10
#define MAX_NAMELENGTH 20

typedef struct student
{
    char *id;
    char *firstName;
    char *lastName;
    char *seat;
    struct student *direktSeatNeighbors[MAX_DIREKT];
    struct student *indirektSeatNeighbors[MAX_INDIREKT];
    struct student *nextStudent;
} student;

student *createStudent(char *id, char *firstName, char *lastName);

bool insertStudentIntoList(student **list, student *newStudent, bool csvflag);

void printStudent(student *student);

student* searchStudent(student *head, char *lastname);

void printStudentList(student *head);

student *createStudentFromString(char *string);

void stringlistToStudentList(stringNode *stringList, student **studentList);

void freeStudentList(student *head);

#endif