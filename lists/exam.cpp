#include "../headerFiles/headers.h"

/**
 * @brief Create a Exam object
 * 
 * @param name name of the exam
 * @param lectureHall the Lecture Hall in which the Exam is hold
 * @return exam* new Exam Object
 */
exam *createExam(char *name, int workload, lectureHall *lectureHall) {
    exam *newExam = (exam *) calloc(1, sizeof(exam *));
    newExam->name = (char *)malloc(20 * sizeof(char));
    strcpy(newExam->name, name);
    newExam->workload = workload;
    newExam->lectureHall = lectureHall;
    return newExam;
}

/**
 * @brief prints a Exam
 * 
 * @param exam the Exam to print
 */
void printExam(exam *exam) {
    char workload[10];
    if(exam->workload == 0) {
        strcpy(workload, "weak");
    } else if(exam->workload == 1) {
        strcpy(workload, "medium");
    } else {
        strcpy(workload, "strong");
    }
    printf("Examname: %s   Workload: %s   Lecturehall: %s\n", exam->name, workload, exam->lectureHall->name);
}

void insertIntoExamList(exam **list, exam *newExam, bool csvflag)	//Update to be alphabetisch
{

   if(*list == NULL) {
    *list = newExam;
    return;
   }
        exam *current = *list;
        //last node's next address will be NULL.
        while(current->nextExam != NULL)
        {
            current = current->nextExam;
        }
        //add the newNode at the end of the linked list
        current->nextExam = newExam;
}


