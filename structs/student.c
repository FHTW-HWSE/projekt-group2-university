#include "../headerFiles/headers.h"

long int generateRandomId()
{
    return 0;
}

student *createStudent(char *firstName, char *lastName)
{
    student *newStudent = calloc(1, sizeof(student *));
    newStudent->id = generateRandomId();
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    return newStudent;
}

void printStudent(student *student)
{
    printf("%s %s\n", student->firstName, student->lastName);
}

student *insertStudentIntoList(student *list, student *newStudent) {
	student *current;
	if (list == NULL || (list)->lastName >= newStudent->lastName) {
		newStudent->nextStudent = list;
		list = newStudent;
	} else {
		current = list;
		while (current->nextStudent != NULL
				&& strcmp(current->nextStudent->lastName, newStudent->lastName)
						< 0) {
			current = current->nextStudent;
		}
		newStudent->nextStudent = current->nextStudent;
		current->nextStudent = newStudent;
	}
	return list;
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

