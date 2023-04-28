#ifndef LECTUREHALL_H // Include guard
#define LECTUREHALL_H

typedef struct lectureHall
{
    char *name;
    int row;
    int column;
    struct lectureHall *nextLectureHall;
} lectureHall;

lectureHall *createLectureHall(char *name, int row, int column);

void printLectureHall(lectureHall *lectureHall);

lectureHall *insertLecureHallIntoList(lectureHall *list, lectureHall *newLectureHall);

void printLectureHallList(lectureHall *head);



#endif