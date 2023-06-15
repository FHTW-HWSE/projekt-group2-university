#include "../headerFiles/headers.h"

/**
 * @brief Create a Exam object
 *
 * @param name name of the exam
 * @param lectureHall the Lecture Hall in which the Exam is hold
 * @return exam* new Exam Object
 */
exam *createExam(char *name, int workload, lectureHall *lecturehall)
{
    exam *newExam = (exam *)calloc(1, sizeof(exam) + sizeof(student)*getMaxStudentsFromLecturehall(lecturehall));
    newExam->name = (char *)malloc(20 * sizeof(char));
    strcpy(newExam->name, name);
    newExam->workload = workload;
    newExam->lectureHall = (lectureHall *)malloc(sizeof(lectureHall));
    newExam->lectureHall = lecturehall;
    newExam->studentcounter = 0;
    int tmp = getMaxStudentsFromLecturehall(lecturehall);
    newExam->maxStudents = getAmountFromWorkload(tmp, workload);
    return newExam;
}

/**
 * @brief prints a Exam
 *
 * @param exam the Exam to print
 */
void printExam(exam *exam)
{
    char workload[10];
    if (exam->workload == 0)
    {
        strcpy(workload, "25%");
    }
    else if (exam->workload == 1)
    {
        strcpy(workload, "50%");
    }
    else
    {
        strcpy(workload, "100%");
    }
    printf("Examname: %10s   Workload: %4s   Lecturehall: %6s   amount: %2d/%2d\n", exam->name, workload, exam->lectureHall->name, exam->studentcounter, exam->maxStudents);
}

exam *searchExam(exam *head, char *name)
{
    exam *current = head;
    while (current != NULL)
    {
        if (equals(current->name, name))
        {
            // printf("elemet gefunden\n");
            return current;
        }
        current = current->nextExam;
    }
    // printf("elemet nicht gefunden\n");
    return NULL;
}

bool insertIntoExamList(exam **list, exam *newExam, bool csvflag) // Update to be alphabetisch
{

    if (*list == NULL)
    {
        *list = newExam;
    }
    else

        if (searchExam(*list, newExam->name) != NULL)
    {
        return false;
    }
    else
    {

        exam *current = *list;
        // last node's next address will be NULL.
        while (current->nextExam != NULL)
        {
            current = current->nextExam;
        }
        // add the newNode at the end of the linked list
        current->nextExam = newExam;
    }
        char newfile[50] = "../assets/exams/";
        strcat(newfile, newExam->name);
        strcat(newfile, (char*)".csv");
        if(!fileExists(newfile)) {
            writeLineInCsv(newfile, (char*)""); //creates a empty examfile
        }
        


    if (csvflag)
    {
        

        char csvstring[50] = {0};
        strcat(csvstring, newExam->name);
        strcat(csvstring, ";");
        strcat(csvstring, integerToString(newExam->workload));
        strcat(csvstring, ";");
        strcat(csvstring, newExam->lectureHall->name);
        writeLineInCsv((char *)"../assets/exams.csv", csvstring);
    }
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
    char *result[3];
    strcpy(str, string);
    const char s[2] = ";";
    char *token;

    token = strtok(str, s);

    int i = 0;
    while (token != NULL)
    {
        // printf("%s\n", token);
        result[i] = token;
        token = strtok(NULL, s);
        i++;
    }

    if (result[2][strlen(result[2]) - 1] == '\n')
        result[2][strlen(result[2]) - 1] = '\0';

    lectureHall *tmp = searchLectureHall(lectureHallList, result[2]);
    if (tmp == NULL)
    {
        printf("Lecturehall does not exist\n");
        exit(0);
    }
    // printLectureHall(tmp);
    return createExam(result[0], atoi(result[1]), tmp);
}

void stringlistToExamList(stringNode *stringList, exam **examList, lectureHall *lectureHallList)
{
    while (stringList != NULL)
    {
        exam *tmp = createExamFromString(stringList->content, lectureHallList);
        insertIntoExamList(examList, tmp, false);
        stringList = stringList->nextStringNode;
    }
}

void freeExamList(exam *head)
{
    exam *tmp;
    while (head != NULL)
    {
        tmp = head->nextExam;
        free(head);
        head = tmp;
    }
    free(head);
}

bool insertStudentIntoExam(student *student, exam *exam) {
    //creating student string
    char studenttext[50] = {0};
    strcat(studenttext, student->id);
    strcat(studenttext, (char*)";");
    strcat(studenttext, student->firstName);
    strcat(studenttext, (char*)";");
    strcat(studenttext, student->lastName);

    //creating examfile string
    char examfile[50] = "../assets/exams/";
    strcat(examfile, exam->name);
    strcat(examfile, (char*)".csv");

    //insertIntoArray
    if(!examIsFull(exam)) {
        exam->students[exam->studentcounter] = student;
        exam->studentcounter++;
    } else {
        return false;
    }
   

    return writeLineInCsv(examfile, studenttext);
}