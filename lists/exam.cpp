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
    exam *newExam = (exam *)calloc(1, sizeof(exam) + sizeof(student) * getMaxStudentsFromLecturehall(lecturehall));
    newExam->name = (char *)malloc(EXAM_FILE * sizeof(char));
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
    if (exam->workload == WEAK)
    {
        strcpy(workload, "25%");
    }
    else if (exam->workload == MEDIUM)
    {
        strcpy(workload, "50%");
    }
    else
    {
        strcpy(workload, "100%");
    }
    printf("Exam name: %10s   Workload: %4s   Lecture hall: %6s   Seats: %2d/%2d\n", exam->name, workload, exam->lectureHall->name, exam->studentcounter, exam->maxStudents);
}

exam *searchExam(exam *head, char *name)
{
    exam *current = head;
    while (current != NULL)
    {
        if (equals(current->name, name))
        {
            // printf("element gefunden\n");
            return current;
        }
        current = current->nextExam;
    }
    // printf("element nicht gefunden\n");
    return NULL;
}

bool insertIntoExamList(exam **list, exam *newExam, bool csvflag) // Update to be alphabetisch
{

    if (newExam == NULL)
    {
        perror("newExam is NULL\n");
        return false;
    }

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
    char newfile[EXAM_FILE] = "../assets/exams/";
    strcat(newfile, newExam->name);
    strcat(newfile, (char *)".csv");
    if (!fileExists(newfile))
    {
        writeLineInCsv(newfile, (char *)""); // creates a empty examfile
    }

    if (csvflag)
    {

        char csvstring[EXAM_FILE] = {0};
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
    printf("\tList of all exams\n");
    while (head != NULL)
    {
        printExam(head);
        head = head->nextExam;
    }
    printf("\n");
}

exam *createExamFromString(char *string, lectureHall *lectureHallList)
{

    if (countCharInString(string, ';') != 2 && strlen(string) > EXAM_FILE)
    {
        perror("String in exam invalid");
        return NULL;
    }
    char str[EXAM_FILE] = {0};
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
        printf("Lecture hall does not exist\n");
        exit(0);
    }
    // printLectureHall(tmp);
    return createExam(result[0], atoi(result[1]), tmp);
}

bool fillExamWithStudents(exam *exam)
{
    char filename[EXAM_FILE] = {0};
    strcat(filename, (char *)"../assets/exams/");
    strcat(filename, exam->name);
    strcat(filename, (char *)".csv");
    if (fileExists(filename))
    {
        FILE *fp;

        char row[STRING_MAX];
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
            return false;
        }
        struct stat stat_record;
        stat(filename, &stat_record);
        if (stat_record.st_size <= 1) // checks if file is empty
        {
            fclose(fp);
            return true;
        }
        else
        { // otherwise read studens and insert in array
            while (feof(fp) != true)
            {
                if (examIsFull(exam))
                {
                    perror("Exam is full");
                    break;
                }
                fgets(row, STRING_MAX, fp);
                // printf("%s", row);
                student *tmp = createStudentFromString(row);
                exam->students[exam->studentcounter] = tmp;
                exam->studentcounter++;
            }
        }
        fclose(fp);
    }
    return true;
}

void stringlistToExamList(stringNode *stringList, exam **examList, lectureHall *lectureHallList)
{
    while (stringList != NULL)
    {
        exam *tmp = createExamFromString(stringList->content, lectureHallList);
        fillExamWithStudents(tmp);
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

bool insertStudentIntoExam(student *student, exam *exam)
{
    // creating student string
    char studenttext[STUDENT_FILE] = {0};
    strcat(studenttext, student->id);
    strcat(studenttext, (char *)";");
    strcat(studenttext, student->firstName);
    strcat(studenttext, (char *)";");
    strcat(studenttext, student->lastName);

    // creating examfile string
    char examfile[EXAM_FILE] = "../assets/exams/";
    strcat(examfile, exam->name);
    strcat(examfile, (char *)".csv");

    // insertIntoArray
    if (!examIsFull(exam))
    {
        exam->students[exam->studentcounter] = student;
        exam->studentcounter++;
    }
    else
    {
        return false;
    }

    return writeLineInCsv(examfile, studenttext);
}

void printExamRoom(exam *exam)
{
    int workload = exam->workload;
    lectureHall *lecturehall = exam->lectureHall;
    int row = lecturehall->row, col = lecturehall->column;
    student *room[row][col];
    int studentindex = 0;
    int operant;
    printf("\t\tSeating plan for the exam %s\n", exam->name);
    if (exam->workload == WEAK)
    {
        bool empty = row != 1 ? false : true;
        for (int y = 0; y < row; y++)
        {
            empty = !empty;
            printf("\t");
            for (int x = 0; x < col; x++)
            {
                //room[y][x] = x % 2 == 0 ? NULL : exam->students[studentindex];
                if(x % 2 == 0 && !empty && studentindex<(exam->studentcounter)) {
                    room[y][x] = exam->students[studentindex];
                    printf("%s   ", room[y][x]->id);
                    studentindex++;
                } else {
                    room[y][x] = NULL;
                    printf((char*)"--------   ");
                }
            }
            printf("\n");
        }
    } else {
        int switcher = 0;
        int modolo = workload == MEDIUM? 2 : 1;

        for (int y = 0; y < row; y++)
        {
            if(workload == MEDIUM) {
                switcher = switcher == 0 ? 1 : 0;
            }
            printf("\t");
            for (int x = 0; x < col; x++)
            {
                if(x%modolo == switcher && studentindex<(exam->studentcounter)) {
                    room[y][x] = exam->students[studentindex];
                    printf("%s   ", room[y][x]->id);
                    studentindex++;
                } else {
                    room[y][x] = NULL;
                    printf((char*)"--------   ");
                }
            }
            printf("\n");
        }
    }
}