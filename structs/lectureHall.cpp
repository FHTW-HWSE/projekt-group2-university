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
    lectureHall *newLectureHall = (lectureHall *) calloc(1, sizeof(lectureHall));
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
    printf("%s\n", lectureHall->name);
}

/**
 * @brief insert into a list of Lecture Halls
 * 
 * @param list 
 * @param newLectureHall 
 * @return lectureHall* 
 */
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

/**
 * @brief prints one Lecture Hall
 * 
 * @param head given Lecture Hall struct to print
 */
void printLectureHallList(lectureHall *head)
{
    lectureHall *current = head;
    while (current != NULL)
    {
        printLectureHall(current);
        current = current->nextLectureHall;
    }
}
