#include "../headerFiles/headers.h"

/**
 * @brief Create a Lecture Hall object
 *
 * @param name name of Lecture Hall
 * @param row numer of rows
 * @param column number of columns
 * @return new Lecture Hall object
 */
lectureHall *createLectureHall(char *name, int row, int column)
{
    lectureHall *newLectureHall = (lectureHall *)calloc(1, sizeof(lectureHall));
    newLectureHall->name = (char *)malloc(20 * sizeof(char));
    strcpy(newLectureHall->name, name);
    newLectureHall->row = row;
    newLectureHall->column = column;
    return newLectureHall;
}

/**
 * @brief Prints one Lecture Hall
 *
 * @param lectureHall LectureHall to Print
 */
void printLectureHall(lectureHall *lectureHall)
{
    printf("Raumname: %9s\t Reihen: %3d\t Spalten: %3d\n", lectureHall->name, lectureHall->row, lectureHall->column);
}

/**
 * @brief insert into a list of Lecture Halls
 *
 * @param list
 * @param newLectureHall
 * @return lectureHall*
 */

lectureHall *searchLectureHall(lectureHall *head, char *name)
{
    lectureHall *current = head;
    while (current != NULL)
    {
        if (equals(current->name, name))
        {
            // printf("elemet gefunden\n");
            return current;
        }
        current = current->nextLectureHall;
    }
    // printf("elemet nicht gefunden\n");
    return NULL;
}

bool insertIntoLectureHallList(lectureHall **list, lectureHall *newLectureHall, bool csvflag) // Update to be alphabetisch
{
    if (*list == NULL)
    {
        *list = newLectureHall;
    }
    else

        if (searchLectureHall(*list, newLectureHall->name) != NULL)
    {
        return false;
    }
    else
    {

        lectureHall *current = *list;

        // last node's next address will be NULL.
        while (current->nextLectureHall != NULL)
        {
            current = current->nextLectureHall;
        }

        // add the newNode at the end of the linked list
        current->nextLectureHall = newLectureHall;
    }
    if (csvflag)
    {
        char csvstring[30] = {0};
        strcat(csvstring, newLectureHall->name);
        strcat(csvstring, ";");
        strcat(csvstring, integerToString(newLectureHall->row));
        strcat(csvstring, ";");
        strcat(csvstring, integerToString(newLectureHall->column));
        // strcat(csvstring, itoa(newLectureHall->row));
        writeLineInCsv((char *)"../assets/lecturehalls.csv", csvstring);
    }
    return true;
}

/**
 * @brief prints one Lecture Hall
 *
 * @param head given Lecture Hall struct to print
 */
void printLectureHallList(lectureHall *head)
{
    printf("\tListe aller Räume\n");
    while (head != NULL)
    {
        printLectureHall(head);
        head = head->nextLectureHall;
    }
    printf("\n");
}

lectureHall *createLectureHallFromString(char *string)
{

    char str[20] = {0};
    char *result[3];
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

    return createLectureHall(result[0], atoi(result[1]), atoi(result[2]));
}

void stringlistToLectureHallList(stringNode *stringList, lectureHall **lectureHallList)
{
    while (stringList != NULL)
    {
        insertIntoLectureHallList(lectureHallList, createLectureHallFromString(stringList->content), false);
        stringList = stringList->nextStringNode;
    }
}

void freeLectureHallList(lectureHall *head)
{
    lectureHall *tmp;
    while (head != NULL)
    {
        tmp = head->nextLectureHall;
        free(head);
        head = tmp;
    }
    free(head);
}