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
	student *newStudent = (student *)calloc(1, sizeof(student));
	newStudent->id = generateRandomId();
	newStudent->firstName = (char *)malloc(20 * sizeof(char));
    strcpy(newStudent->firstName, firstName);
	newStudent->lastName = (char *)malloc(20 * sizeof(char));
    strcpy(newStudent->lastName, lastName);
	return newStudent;
}

/**
 * @brief prints a single Student
 *
 * @param student given Student to print
 */
void printStudent(student *student)
{
	printf("Firstname: %10s\t  Lastname: %10s\n", student->firstName, student->lastName);
}

/**
 * @brief inserts a new Student in a Studentlist
 *
 * @param list given List to insert the Student into
 * @param newStudent the Student to insert in the List
 * @return student* the new List
 */
bool insertStudentIntoList(student **list, student *newStudent, bool csvflag)
{
	if(*list == NULL) {
    *list = newStudent;
    return true;
   }

   if(searchStudent(*list, newStudent->lastName)) {
        return false;
   }

        student *current = *list;

        //last node's next address will be NULL.
        while(current->nextStudent != NULL)
        {
            current = current->nextStudent;
        }

        //add the newNode at the end of the linked list
        current->nextStudent= newStudent;

         if(csvflag) {
            char csvstring[40] = {0};
            strcat(csvstring, newStudent->firstName);
            strcat(csvstring, ";");
            strcat(csvstring, newStudent->lastName);
            writeLineInCsv((char*)"../assets/students.csv", csvstring);
        }
		return true;
}

/**
 * @brief prints a Studentlist
 *
 * @param head the Student List to print
 */

bool searchStudent(student* head, char *lastname) {
    while(head != NULL) {
        if(equals(head->lastName, lastname)) {
            //printf("elemet gefunden\n");
            return true;
        }
        head = head->nextStudent;
    }
    //printf("elemet nicht gefunden\n");
    return false;
}

void printStudentList(student *head)
{
	printf("\tListe aller Studenten\n");
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
	if(result[1][strlen(result[1])-1] == '\n')
	result[1][strlen(result[1])-1] = '\0';


	return createStudent(result[0], result[1]);
}

void stringlistToStudentList(stringNode *stringList, student **studentList)
{
    while (stringList != NULL)
    {
        insertStudentIntoList(studentList, createStudentFromString(stringList->content), false);
        stringList = stringList->nextStringNode;
    }
	//printStudentList(*studentList);
}


void freeStudentList(student *head) {
    student* tmp;
    while(head != NULL) {
        tmp = head->nextStudent;
        free(head);
        head = tmp;
    }
    free(head);
}