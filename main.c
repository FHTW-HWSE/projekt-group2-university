#include "headerFiles/headers.h"
int main()
{
    //student *a = createStudent("Marwan", "Georg");
    student *head = malloc(sizeof(student *));
    //head = NULL;
    student *b = createStudent("Basmala", "Elsayad");
    student *c = createStudent("Marwan", "Abdalla");
    student *d = createStudent("Marwan", "Marcel");
    student *e = createStudent("Marwan", "Thomes");
    student *f = createStudent("Marwan", "Manuel");
    insertStudentIntoList(head, b);
    insertStudentIntoList(head, c);
    insertStudentIntoList(head, d);
    insertStudentIntoList(head, e);
    insertStudentIntoList(head, f);
    printStudentList(head);


    return 0;
}