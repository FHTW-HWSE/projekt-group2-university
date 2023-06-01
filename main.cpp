#include "headerFiles/headers.h"
#define ADMIN_PWD (char *)"pwd"

bool isAdmin = false;


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
    return true;
}

bool adminInsertExam(exam *examList, lectureHall *lectureHallList) {
    char name[20];
    char workload;
    char lecturehall[20];
    printf("Enter the name of the Exam: ");
    scanf("%20s", name);
    printf("\nChoose the workload for the Exam\n");
    printf("Enter 0 for weak\nEnter 1 for medium\nEnter 2 for strong\n");
    getchar();
    workload = getchar();
    if(workload != '0' && workload != '1' && workload != '2') {
        printf("\nInvalid Input\n");
        return false;
    }
    printf("Enter the name of the lecutrehall where the exam is hold:\n");
    scanf("%20s", lecturehall);
    printf("%s", lecturehall);
    lectureHall *tmp = searchLectureHall(lectureHallList, lecturehall);
    if(tmp == NULL) {
        printf("This Lecturehall does not exist\n");
        return false;
    }
    //printLectureHall(tmp);
    exam *newExam = createExam(name, atoi(&workload), tmp);
    printf("\n");
    printExam(newExam);


    return true;
}

void adminWorkflow(lectureHall **lectureHallList, student **studentList, exam **examList)
{
    printf("Pls Enter Admin Password: ");
    char pwd[30];
    scanf("%30s", pwd);
    printf("%s", pwd);
    while (!equals(pwd, ADMIN_PWD))
    {
        printf("\nWrong Password. pls ender again or quit with q: ");
        scanf("%30s", pwd);
        if (equals(pwd, (char *)"q"))
        {
            printf("Thank you for using our Software\n");
            exit(0);
        }
    }
    printf("\nPassword is Correct!\nHello Admin!\n");
    isAdmin = true;
    printf("press 1 to show a List of all Rooms\n");
    printf("press 2 to show a List of all Students\n");
    printf("press 3 to generate a new LectureHall\n");
    printf("press 4 to generate a new Exam\n");


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
        adminInsertHall(*lectureHallList);
        break;
    case '4':
        printLectureHallList(*lectureHallList);
        adminInsertExam(NULL, *lectureHallList);
        break;
    default:
        printf("invalid input\n");
        exit(0);
        break;
    }
}

void studentWorkflow()
{
    char firstname[20];
    char lastname[20];

    printf("Pls fill in all the data\n");
    printf("Enter your first name: ");
    scanf("%20s", firstname);
    printf("\nEnter your last name: ");
    scanf("%20s", lastname);
    student *loggedStudent = createStudent(firstname, lastname);
    printf("Welcome %s %s\n", loggedStudent->firstName, loggedStudent->lastName);
}

int main()
{
    lectureHall *lectureHallList = (lectureHall *)malloc(sizeof(lectureHall *));
    lectureHallList = NULL;

    student *studentList = (student*) malloc(sizeof(student*));
    studentList = NULL;

    stringNode *stringListHalls = (stringNode *)malloc(sizeof(stringNode *));
    stringListHalls= NULL;

    stringNode *stringListStudents = (stringNode *)malloc(sizeof(stringNode *));
    stringListStudents = NULL;

    if (!readCsv((char *)"../assets/lecturehalls.csv", &stringListHalls))
    {
        perror("FILE NOT FOUND");
        // exit(0);
    }

     if (!readCsv((char *)"../assets/students.csv", &stringListStudents))
    {
        perror("FILE NOT FOUND");
        // exit(0);
    }
    


    stringlistToLectureHallList(stringListHalls, &lectureHallList);
    stringlistToStudentList(stringListStudents, &studentList);
    
    //freeing the stringLists after copying data into new data structure
    freeStringList(stringListHalls);
    freeStringList(stringListStudents);

    printf("Welcome\n");
    printf("Login as Admin: Press 1\n");
    printf("Login as Student: Press any key\n");

    int c;
    c = getchar();
    getchar();

    if (c == '1')
    {
        adminWorkflow(&lectureHallList, &studentList, NULL);
    }
    else
    {
        studentWorkflow();
    }


    //freeing all used list
    freeLectureHallList(lectureHallList);
    freeStudentList(studentList);

    return 0;
}