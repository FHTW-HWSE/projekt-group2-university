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


lectureHall *insertLecureHallIntoList(lectureHall *list, lectureHall *newLectureHall) {
	lectureHall *current;
	if (list == NULL || (list)->name >= newLectureHall->name) {
		newLectureHall->nextLectureHall = list;
		list = newLectureHall;
	} else {
		current = list;
		while (current->nextLectureHall != NULL
				&& strcmp(current->nextLectureHall->name, newLectureHall->name)
						< 0) {
			current = current->nextLectureHall;
		}
		newLectureHall->nextLectureHall = current->nextLectureHall;
		current->nextLectureHall = newLectureHall;
	}
	return list;
}

void printLectureHallList(lectureHall *head)
{
    lectureHall *current = head;
    while (current != NULL)
    {
        printLectureHall(current);
        current = current->nextLectureHall;
    }
}
