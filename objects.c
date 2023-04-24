#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

typedef struct teacher
{
    long int id;
    char *firstName;
    char *lastName;
    struct teacher *nextTeacher;
} teacher;

typedef struct lectureHall
{
    char *name;
    int row;
    int column;
    struct lectureHall *nextLectureHall;
} lectureHall;

long int generateRandomId()
{
    return 0;
}

student *createStudent(char *firstName, char *lastName)
{
    student *newStudent = calloc(1, sizeof(student));
    newStudent->id = generateRandomId();
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    return newStudent;
}

teacher *createTeacher(char *firstName, char *lastName)
{
    teacher *newTeacher = calloc(1, sizeof(teacher));
    newTeacher->id = generateRandomId();
    newTeacher->firstName = firstName;
    newTeacher->lastName = lastName;
    return newTeacher;
}

lectureHall *createLectureHall(char *name, int row, int column)
{
    lectureHall *newLectureHall = calloc(1, sizeof(lectureHall));
    newLectureHall->name = name;
    newLectureHall->row = row;
    newLectureHall->column = column;
    return newLectureHall;
}

void printStudent(student *student)
{
    printf("%s %s\n", student->firstName, student->lastName);
}

void printTeacher(teacher *teacher)
{
    printf("%s %s\n", teacher->firstName, teacher->lastName);
}

void printLectureHall(lectureHall *lectureHall)
{
    printf("%s\n", lectureHall->name);
}

void insertStudentIntoList(student *head, student *newStudent) {
    if(head == NULL) {
        printf("FEHLER");
        head = newStudent;
        return ;
    }

   while(head->nextStudent != NULL) {
    head = head->nextStudent;
   }
   head->nextStudent = newStudent;
}

void printStudentList(student *head)
{
    student *current = head;
    while (current != NULL)
    {
        printStudent(current);
        current = current->nextStudent;
    }
}

int main()
{
    student *a = createStudent("Marwan", "Georg");
    student *head = a;
    student *b = createStudent("Marwan", "Abdafgrfglla");
    student *c = createStudent("Marwan", "Abdalla");
    student *d = createStudent("Marwan", "Abdalla");
    student *e = createStudent("Marwan", "Adebdalla");
    student *f = createStudent("Marwan", "Abdadedlla");
    insertStudentIntoList(head, b);
    insertStudentIntoList(head, c);
    insertStudentIntoList(head, d);
    insertStudentIntoList(head, e);
    insertStudentIntoList(head, f);
    printStudentList(head);
    return 0;
}