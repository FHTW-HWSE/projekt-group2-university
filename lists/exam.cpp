#include "../headerFiles/headers.h"

/**
 * @brief Create a Exam object
 * 
 * @param name name of the exam
 * @param lectureHall the Lecture Hall in which the Exam is hold
 * @return exam* new Exam Object
 */
exam *createExam(char *name, int workload, lectureHall *lecturehall) {
    exam *newExam = (exam *) calloc(1, sizeof(exam));
    newExam->name = (char *)malloc(20 * sizeof(char));
    strcpy(newExam->name, name);
    newExam->workload = workload;
    newExam->lectureHall = (lectureHall*) malloc(sizeof(lectureHall));
    newExam->lectureHall = lecturehall;
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
    printf("Examname: %5s   Workload: %6s   Lecturehall: %5s\n", exam->name, workload, exam->lectureHall->name);
}

exam *searchExam(exam* head, char *name) {
    exam *current = head;
    while(current != NULL) {
        if(equals(current->name, name)) {
            //printf("elemet gefunden\n");
            return current;
        }
        current = current->nextExam;
    }
    //printf("elemet nicht gefunden\n");
    return NULL;
}

bool insertIntoExamList(exam **list, exam *newExam, bool csvflag)	//Update to be alphabetisch
{

   if(*list == NULL) {
    printf("leer\n");
    *list = newExam;
    return true;
   }
    
   if(searchExam(*list, newExam->name) != NULL) {
        return false;
   }
   
        exam *current = *list;
        //last node's next address will be NULL.
        while(current->nextExam != NULL)
        {
            current = current->nextExam;
        }
        //add the newNode at the end of the linked list
        current->nextExam = newExam;
        return true; 
        return true;
}

void printExamList(exam *head)
{
    printf("\tListe aller Prüfungen\n");
    while (head != NULL)
    {
        printExam(head);
        head = head->nextExam;
    }
    printf("\n");
}

exam *createExamFromString(char *string, lectureHall *lectureHallList)
{

    char str[20] = {0};
    char* result[3];
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

    if(result[2][strlen(result[2])-1] == '\n')
	result[2][strlen(result[2])-1] = '\0';

    lectureHall *tmp = searchLectureHall(lectureHallList, result[2]);
    if(tmp == NULL) {
        printf("Lecturehall does not exist\n");
        exit(0);
    }
    //printLectureHall(tmp);
    return createExam(result[0], atoi(result[1]), tmp);

}

void stringlistToExamList(stringNode *stringList, exam **examList,  lectureHall *lectureHallList)
{
    while (stringList != NULL)
    {
        exam *tmp =  createExamFromString(stringList->content, lectureHallList);
        insertIntoExamList(examList, tmp, false);
        stringList = stringList->nextStringNode;
    }
}

