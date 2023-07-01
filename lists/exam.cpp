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
bool printExam(exam *exam)
{
    if(exam == NULL) {
        return false;
    }
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
    return true;
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

bool printExamList(exam *head)
{
    if(head == NULL)  {
        return false;
    }
    printf("\tList of all exams\n");
    while (head != NULL)
    {
        printExam(head);
        head = head->nextExam;
    }
    printf("\n");
    return true;
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

bool stringlistToExamList(stringNode *stringList, exam **examList, lectureHall *lectureHallList)
{
    while (stringList != NULL)
    {
        exam *tmp = createExamFromString(stringList->content, lectureHallList);
        fillExamWithStudents(tmp);
        insertIntoExamList(examList, tmp, false);
        stringList = stringList->nextStringNode;
    }
    return true;
}

bool freeExamList(exam *head)
{
    exam *tmp;
    while (head != NULL)
    {
        tmp = head->nextExam;
        free(head);
        head = tmp;
    }
    free(head);
    return true;
}

bool insertStudentIntoExam(student *student, exam *exam)
{
    // check if student is in exam
    for (int i = 0; i < exam->studentcounter; i++)
    {
        if (equals(exam->students[i]->id, student->id))
        {
            printf("You already written in exam '%s'\n", exam->name);
            return false;
        }
    }

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

    if (!examIsFull(exam))
    {
        exam->students[exam->studentcounter] = student;
        exam->studentcounter++;
        student->exams[student->examcounter] = exam;
        student->examcounter++;
    }
    else
    {
        printf("Exam is already full\n");
        return false;
    }

    return writeLineInCsv(examfile, studenttext);
}

bool printExamRoom(exam *exam)
{
    if(exam == NULL) {
        return false;
    }
    int workload = exam->workload;
    lectureHall *lecturehall = exam->lectureHall;
    int row = lecturehall->row, col = lecturehall->column;
    student *room[row][col];
    int studentindex = 0;
    int operant;
    printf("\t\tSeating plan for the exam %s\n\n", exam->name);
    if (exam->workload == WEAK)
    {
        bool empty = row != 1 ? false : true;
        for (int y = 0; y < row; y++)
        {
            empty = !empty;
            printf("\t");
            for (int x = 0; x < col; x++)
            {
                // room[y][x] = x % 2 == 0 ? NULL : exam->students[studentindex];
                if (x % 2 == 0 && !empty && studentindex < (exam->studentcounter))
                {
                    room[y][x] = exam->students[studentindex];
                    printf("%s   ", room[y][x]->id);
                    studentindex++;
                }
                else
                {
                    room[y][x] = NULL;
                    printf((char *)"--------   ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        int switcher = 0;
        int modolo = workload == MEDIUM ? 2 : 1;

        for (int y = 0; y < row; y++)
        {
            if (workload == MEDIUM)
            {
                switcher = switcher == 0 ? 1 : 0;
            }
            printf("\t");
            for (int x = 0; x < col; x++)
            {
                if (x % modolo == switcher && studentindex < (exam->studentcounter))
                {
                    room[y][x] = exam->students[studentindex];
                    printf("%s   ", room[y][x]->id);
                    studentindex++;
                }
                else
                {
                    room[y][x] = NULL;
                    printf((char *)"--------   ");
                }
            }
            printf("\n\n");
        }
    }
    printf("Press [1] to see neighbours of a student\n");
    printf("Press [any key] to return to menu\n");
    int c;
    getchar();
    c = getchar();
    if (c == '1')
    {
        char id[IDLENGTH] = {0};
        printf("Enter student ID: ");
        scanf("%10s", id);
        if (!checkIDFormat(id))
        {
            printf("Invalid ID\n");
            return false;
        }

        // schleife für direkte nachbarn

        for (int y = 0; y < row; y++)
        {
            for (int x = 0; x < col; x++)
            {
                if (room[y][x] != NULL && equals(room[y][x]->id, id))
                {

                    printf("\n\tList of direct seat neighbours\n");

                    // print neighbors
                    if (y != 0)
                    {
                        if (x != 0)
                            printStudent(room[y - 1][x - 1]);
                        printStudent(room[y - 1][x]);
                        if (x != col - 1)
                            printStudent(room[y - 1][x + 1]);
                    }

                    if (x != col - 1)
                        printStudent(room[y][x + 1]);
                    if (y != row - 1)
                    {
                        if (x != col - 1)
                            printStudent(room[y + 1][x + 1]);
                        printStudent(room[y + 1][x]);
                        if (x != 0)
                            printStudent(room[y + 1][x - 1]);
                    }

                    if (x != 0 && room[y][x - 1] != NULL)
                        printStudent(room[y][x - 1]);
                }
            }
        }

        // schleife für indirekte nachbarn

        for (int y = 0; y < row; y++)
        {
            for (int x = 0; x < col; x++)
            {

                if (room[y][x] != NULL && equals(room[y][x]->id, id))
                {
                    printf("\n\tList of indirect seat neighbours\n");

                    if (y > 1 && y < row - 2 && x > 1 && x < col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y - 2][x + 2]); // 5
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                        printStudent(room[y + 2][x - 2]); // 13
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16 */
                    }
                    else if (y == 0 && x == 0)
                    {
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                    }
                    else if (y == 0 && x == 1)
                    {
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                    }
                    else if (y == 1 && x == 0)
                    {
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                    }
                    else if (y == 1 && x == 1)
                    {
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                    }
                    else if (y == row - 2 && x == col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == row - 2 && x == col - 1)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == row - 1 && x == col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == row - 1 && x == col - 1)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == 0 && x > 1 && x < col - 2)
                    {
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                        printStudent(room[y + 2][x - 2]); // 13
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                    }
                    else if (y == 1 && x > 1 && x < col - 2)
                    {
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                        printStudent(room[y + 2][x - 2]); // 13
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == row - 1 && x > 1 && x < col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y - 2][x + 2]); // 5
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y == row - 2 && x > 1 && x < col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y - 2][x + 2]); // 5
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y > 1 && y < row - 2 && x == 0)
                    {
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y - 2][x + 2]); // 5
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                    }
                    else if (y > 1 && y < row - 2 && x == 1)
                    {
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y - 2][x + 2]); // 5
                        printStudent(room[y - 1][x + 2]); // 6
                        printStudent(room[y][x + 2]);     // 7
                        printStudent(room[y + 1][x + 2]); // 8
                        printStudent(room[y + 2][x + 2]); // 9
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                    }
                    else if (y > 1 && y < row - 2 && x == col - 1)
                    {

                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                        printStudent(room[y + 2][x - 2]); // 13
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }
                    else if (y > 1 && y < row - 2 && x == col - 2)
                    {
                        printStudent(room[y - 2][x - 2]); // 1
                        printStudent(room[y - 2][x - 1]); // 2
                        printStudent(room[y - 2][x]);     // 3
                        printStudent(room[y - 2][x + 1]); // 4
                        printStudent(room[y + 2][x + 1]); // 10
                        printStudent(room[y + 2][x]);     // 11
                        printStudent(room[y + 2][x - 1]); // 12
                        printStudent(room[y + 2][x - 2]); // 13
                        printStudent(room[y + 1][x - 2]); // 14
                        printStudent(room[y][x - 2]);     // 15
                        printStudent(room[y - 1][x - 2]); // 16
                    }

                    return true;
                }
            }
        }

        printf("Id not found\n");
        return false;
    }
    else
    {
        return true;
    }
}