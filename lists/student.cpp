#include "../headerFiles/headers.h"

/**
 * @brief Create a Student object
 *
 * @param firstName firstName of the Student
 * @param lastName lastName of the Student
 * @return student* new Student object
 */
student *createStudent(char *firstName, char *lastName)
{
	student *newStudent = (student *)calloc(1, sizeof(student *));
	newStudent->id = generateRandomId();
	newStudent->firstName = firstName;
	newStudent->lastName = lastName;
	return newStudent;
}

/**
 * @brief prints a single Student
 *
 * @param student given Student to print
 */
void printStudent(student *student)
{
	printf("%s %s\n", student->firstName, student->lastName);
}

/**
 * @brief inserts a new Student in a Studentlist
 *
 * @param list given List to insert the Student into
 * @param newStudent the Student to insert in the List
 * @return student* the new List
 */
student *insertStudentIntoList(student **list, student *newStudent)
{
	student *current;
	if (*list == NULL || (*list)->lastName >= newStudent->lastName)
	{
		newStudent->nextStudent = *list;
		*list = newStudent;
	}
	else
	{
		current = *list;
		while (current->nextStudent != NULL && strcmp(current->nextStudent->lastName, newStudent->lastName) < 0)
		{
			current = current->nextStudent;
		}
		newStudent->nextStudent = current->nextStudent;
		current->nextStudent = newStudent;
	}
	return *list;
}

/**
 * @brief prints a Studentlist
 *
 * @param head the Student List to print
 */
void printStudentList(student *head)
{
	student *current = head;
	while (current != NULL)
	{
		printStudent(current);
		current = current->nextStudent;
	}
}

student *createStudentFromString(char *string)
{

	char str[50] = {0};
	char *result[2];
	strcpy(str, string);
	const char s[2] = ";";
	char *token;

	token = strtok(str, s);

	int i = 0;
	while (token != NULL)
	{
		// printf("%s\n", token);
		result[i] = token;
		token = strtok(NULL, s);
		i++;
	}

	return createStudent(result[0], result[1]);
}

void stringlistToStudentList(stringNode *stringList, student **studentList)
{
    while (stringList != NULL)
    {
        insertStudentIntoList(studentList, createStudentFromString(stringList->content));
        stringList = stringList->nextStringNode;
    }
}