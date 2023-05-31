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
    newLectureHall->name = (char *)malloc(4 * sizeof(char));
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
    printf("%s: %i: %i\n", lectureHall->name, lectureHall->row, lectureHall->column);
}

/**
 * @brief insert into a list of Lecture Halls
 *
 * @param list
 * @param newLectureHall
 * @return lectureHall*
 */
void insertIntoLectureHallList(lectureHall **list, lectureHall *newLectureHall) // Update to be alphabetisch
{
    if (*list == NULL)
    {
        *list = newLectureHall;
        return;
    }

    newLectureHall->nextLectureHall = *list;
    // changing the new head to this freshly entered node
    *list = newLectureHall;
}

/**
 * @brief prints one Lecture Hall
 *
 * @param head given Lecture Hall struct to print
 */
void printLectureHallList(lectureHall *head)
{
    while (head != NULL)
    {
        printf("%s ", head->name);
        head = head->nextLectureHall;
    }
    printf("\n");
}

lectureHall *createLectureHallFromString(char *string)
{

    char str[20] = {0};
    char* result[2];
    strcpy(str, string);
    const char s[2] = ";";
    char *token;

    token = strtok(str, s);

    int i=0;
    while(token != NULL) {
        //printf("%s\n", token);
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
        insertIntoLectureHallList(lectureHallList, createLectureHallFromString(stringList->content));
        //lectureHall *tmp = createLectureHallFromString(stringList->content);
        //printf("%s\n", stringList->content);
        stringList = stringList->nextStringNode;
    }
}