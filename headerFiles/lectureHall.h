#ifndef LECTUREHALL_H // Include guard
#define LECTUREHALL_H


typedef struct lectureHall
{
    char *name;
    int row;
    int column;
    struct lectureHall *nextLectureHall;
} lectureHall;

#endif