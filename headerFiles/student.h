#ifndef STUDENT_H // Include guard
#define STUDENT_H


#define IDLENGTH 10
#define MAX_NAMELENGTH 20
#define STUDENT_FILE 50


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

bool printStudent(student *student);

student* searchStudent(student *head, char *lastname);

bool printStudentList(student *head);

student *createStudentFromString(char *string);

bool stringlistToStudentList(stringNode *stringList, student **studentList);

bool freeStudentList(student *head);

#endif