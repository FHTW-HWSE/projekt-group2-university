#include "headerFiles/headers.h"
#define ADMIN_PWD (char *)"pwd"

bool isAdmin = false;

void initStringLists(stringNode** students, stringNode** lecturehalls, stringNode** exams ) {
 if (!readCsv((char *)"../assets/lecturehalls.csv", lecturehalls))
    {
        perror("FILE lecturehalls NOT FOUND");
        // exit(0);
    }

     if (!readCsv((char *)"../assets/students.csv", students))
    {
        perror("FILE students NOT FOUND");
        // exit(0);
    }

    if (!readCsv((char *)"../assets/exams.csv", exams))
    {
        perror("FILE exams NOT FOUND");
        // exit(0);
    }
}

bool adminPrintExamRoom(exam *examList) {
    printf("Enter the name of the exam you want to print: ");
    char examName[10];
    scanf("%9s", examName);
    exam *exam = searchExam(examList, examName);
    if(exam == NULL) {
        printf("This exam does not exist\n");
        return false;
    } 
    printExamRoom(exam);
    return false;
}


bool adminInsertHall(lectureHall *list) {
    char name[20];
    char row[3];
    char col[3];
    printf("Enter lecture hall name: ");
    scanf("%20s", name);
    printf("Enter amount of rows in the hall: ");
    scanf("%3s", row);
    printf("Enter amount of columns in the hall: ");
    scanf("%3s", col);
    lectureHall *tmp = createLectureHall(name, atoi(row), atoi(col));
    //printLectureHall(tmp);
    if(!insertIntoLectureHallList(&list, tmp, true)) {
        printf("Lecture hall with this name already exists\n");
        return false;
    }
    printf("Successfully added lecture hall '%s'\n", tmp->name);
    return true;
}

bool adminInsertExam(exam *examList, lectureHall *lectureHallList) {
    char name[20];
    char workload;
    char lecturehall[20];
    printf("Enter the name of the Exam: ");
    scanf("%20s", name);
    printf("\nChoose the workload for the exam\n");
    printf("Enter 0 for weak\nEnter 1 for medium\nEnter 2 for strong\n");
    getchar();
    workload = getchar();
    if(workload != '0' && workload != '1' && workload != '2') {
        printf("\nInvalid Input\n");
        return false;
    }
    printf("Enter the name of the lecture hall where the exam is hold:\n");
    scanf("%20s", lecturehall);
    lectureHall *tmp = searchLectureHall(lectureHallList, lecturehall);
    if(tmp == NULL) {
        printf("This lecture hall does not exist\n");
        return false;
    }
    //printLectureHall(tmp);
    exam *newExam = createExam(name, atoi(&workload), tmp);
    insertIntoExamList(&examList, newExam, true);
    printf("Successfully added exam '%s'\n", newExam->name);
    return true;
}

void studentEnterExam(exam **examList, student *student) {
    char examname[20];
    printExamList(*examList);
    printf("Enter the name of the exam you want to join:\n");
    scanf("%20s", examname);
    exam *tmp = searchExam(*examList, examname);
    if(tmp == NULL) {
        printf("Exam does not exist\n");
        exit(0);
    }
    insertStudentIntoExam(student, tmp);
    printf("You joined exam '%s'\n", tmp->name);
}


void adminWorkflow(lectureHall **lectureHallList, student **studentList, exam **examList)
{
    int errcount = 3;
    printf("Enter admin password: ");
    char pwd[30];
    scanf("%30s", pwd);
    while (!equals(pwd, ADMIN_PWD))
    {
        errcount--;
        if (errcount==0)
        {
            printf("Too many wrong tries.\n");
            exit(0);
        }
        printf("\nWrong password. Tries left: %d. Enter again or quit with q: ", errcount);
        scanf("%30s", pwd);
        if (equals(pwd, (char *)"q"))
        {
            printf("Thank you for using our software\n");
            exit(0);
        }
    }
    printf("\nPassword is correct!\nHello admin!\n");
    isAdmin = true;
    while(true){
    printf("Press 1 to show a list of all rooms\n");
    printf("Press 2 to show a list of all students\n");
    printf("Press 3 to show a list of all exams\n");
    printf("Press 4 to generate a new lecture hall\n");
    printf("Press 5 to generate a new exam\n");
    printf("Press 6 to print a exam room\n");
    printf("Press q to exit\n");


    int input;
    getchar();
    input = getchar();
    switch (input)
    {
        case '1':
            printLectureHallList(*lectureHallList);
            break;
        case '2': 
            printStudentList(*studentList);
            break;
        case '3':
            printExamList(*examList);
            break;
        case '4': 
            adminInsertHall(*lectureHallList);
            break;
        case '5':
            printLectureHallList(*lectureHallList);
            adminInsertExam(*examList, *lectureHallList);
            break;
        case '6':
            printExamList(*examList);
            adminPrintExamRoom(*examList);
            break;
        case 'q':
            printf("Thank You for using admin services.\n");
            exit(0);
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }

}

void studentWorkflow(student **studentList, exam **examList)
{
    char id[10];
    char firstname[20];
    char lastname[20];
    int errcount = 3;

    printf("Please enter your student info\n");
    printf("Enter your matriculation number: ");
    scanf("%10s", id);
    while (!checkIDFormat(id)){
        errcount--;
        if (errcount==0){
            printf("Too many wrong tries.\n");
            exit(0);
        }
        printf("ID invalid. Tries left: %d\n", errcount);
        printf("Enter your matriculation number: ");
        scanf("%10s", id);
    } 
    student *loggedStudent;
    if(searchStudent(*studentList, id)) {
        loggedStudent = searchStudent(*studentList, id);
        printf("You logged in with your account\n");
    } else {
        printf("Enter your first name: ");
        scanf("%20s", firstname);
        printf("Enter your last name: ");
        scanf("%20s", lastname);
        loggedStudent = createStudent(id, firstname, lastname);
        printf("You created a new account\n");
    }
    
    insertStudentIntoList(studentList, loggedStudent, true);
    printf("Welcome %s %s\n", loggedStudent->firstName, loggedStudent->lastName);

    while(true){
        printf("Press 1 to see lists of all exams\n");
        printf("Press 2 to enter a exam\n");
        printf("Press q to exit\n");

        char input[1];
        scanf("%1s", input);

        switch (input[0]) // fehler bei mehr als 1 char eingabe
        {
        case '1':
            printExamList(*examList);
            break;
        case '2':
            studentEnterExam(examList, loggedStudent);
            break;
        case 'q':
            printf("Thank You for using student services.\n");
            exit(0);
            break;
        default:
            break;
        }
    }
}

int main()
{
    //creating empty stringlists for reading data from csv
    stringNode *stringListHalls = (stringNode *)malloc(sizeof(stringNode *));
    stringListHalls= NULL;

    stringNode *stringListStudents = (stringNode *)malloc(sizeof(stringNode *));
    stringListStudents = NULL;

    stringNode *stringListExam = (stringNode *)malloc(sizeof(stringNode *));
    stringListExam = NULL;


    //initializing data from csv into the stringlists
    initStringLists(&stringListStudents, &stringListHalls, &stringListExam);
    


    //creating empty datalists 
    lectureHall *lectureHallList = (lectureHall *)malloc(sizeof(lectureHall *));
    lectureHallList = NULL;

    student *studentList = (student*) malloc(sizeof(student*));
    studentList = NULL;

    exam *examList = (exam*) malloc(sizeof(student*));
    examList = NULL;

    // Mapping stringLists into DataLists
    stringlistToLectureHallList(stringListHalls, &lectureHallList);
    stringlistToStudentList(stringListStudents, &studentList);
    stringlistToExamList(stringListExam, &examList, lectureHallList);
   
    //freeing the stringLists after copying data into new data structure
    freeStringList(stringListHalls);
    freeStringList(stringListStudents);

    printf("Welcome\n");
    printf("Login as admin: Press 1\n");
    printf("Login as student: Press any key\n");

    int input;
    input = getchar();
    getchar();

    if (input == '1')
    {
        adminWorkflow(&lectureHallList, &studentList, &examList);
    }
    else
    {
        studentWorkflow(&studentList, &examList);
    }




    //freeing all used list
    freeLectureHallList(lectureHallList);
    freeStudentList(studentList);
    freeExamList(examList);

    return 0;
}