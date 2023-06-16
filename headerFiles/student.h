#ifndef STUDENT_H // Include guard
#define STUDENT_H


#define IDLENGTH 10
#define MAX_NAMELENGTH 20

typedef struct student
{
    char *id;
    char *firstName;
    char *lastName;    
    struct student *nextStudent;
    int examcounter;
    struct exam *exams[];
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