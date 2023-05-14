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
void insertIntoLectureHallList(lectureHall **list, lectureHall *newLectureHall)	//Update to be alphabetisch
{
	if(*list == NULL) {
		*list = newLectureHall;
		return;
	}

  newLectureHall->nextLectureHall = *list;
  //changing the new head to this freshly entered node
  *list = newLectureHall;
}

/**
 * @brief prints one Lecture Hall
 * 
 * @param head given Lecture Hall struct to print
 */
void printLectureHallList(lectureHall *head)
{
     while(head!=NULL){
        printf("%s ",head->name);
        head = head->nextLectureHall;
    }
    
    printf("\n");
}
