#include "headerFiles/headers.h"
#define ADMIN_PWD (char *)"pwd"

bool isAdmin = false;


void adminWorkflow(lectureHall **lectureHallList)
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

    int input;
    getchar();
    input = getchar();
    if(input == '1') {
        printLectureHallList(*lectureHallList);
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
    stringNode *stringList = (stringNode *)malloc(sizeof(stringNode *));
    stringList = NULL;
    if (!readCsv((char *)"../assets/lecturehalls.csv", &stringList))
    {
        perror("FILE NOT FOUND");
        // exit(0);
    }

    

    stringlistToLectureHallList(stringList, &lectureHallList);
    freeStringList(stringList);

    printf("Welcome\n");
    printf("Login as Admin: Press 1\n");
    printf("Login as Student: Press any key\n");

    int c;
    c = getchar();
    getchar();

    if (c == '1')
    {
        adminWorkflow(&lectureHallList);
    }
    else
    {
        studentWorkflow();
    }

   

    return 0;
}