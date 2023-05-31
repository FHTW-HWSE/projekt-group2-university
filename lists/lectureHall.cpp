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
    newLectureHall->name = name;
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
    int i = 0;
    char **params = (char**) calloc(3, sizeof(char*));
    for(int i=0; i<3; i++) {
        params[i] = (char*) malloc(100*sizeof(char));
    }
    int paramCounter = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ';')
        {
            paramCounter++;
        }
        else
        {
            strncat(params[paramCounter], &string[i], sizeof(char));
        }
        i++;
    }
    printf("%s", params[0]);
    lectureHall * hall = createLectureHall(params[0], atoi(params[1]), atoi(params[2]));
    
}

void stringlistToLectureHallList(stringNode *stringList, lectureHall **lectureHallList)
{
    while(stringList != NULL) {
        //insertIntoLectureHallList(lectureHallList, createLectureHallFromString(stringList->content));
        //printLectureHall()
        createLectureHallFromString(stringList->content);
        stringList = stringList->nextStringNode;
    }
}