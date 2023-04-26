#include "../headerFiles/headers.h"

lectureHall *createLectureHall(char *name, int row, int column)
{
    lectureHall *newLectureHall = calloc(1, sizeof(lectureHall));
    newLectureHall->name = name;
    newLectureHall->row = row;
    newLectureHall->column = column;
    return newLectureHall;
}

void printLectureHall(lectureHall *lectureHall)
{
    printf("%s\n", lectureHall->name);
}
