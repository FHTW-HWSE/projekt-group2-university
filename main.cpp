#include "headerFiles/headers.h"
#define ADMIN_PWD (char*)"sitzplatzgenerator"
int main()
{
    bool isAdmin = false;

    printf("Welcome\n");
    printf("Login as Admin: Press 1\n");
    printf("Login as Student: Press any key\n");

    int c;
    c = getchar();
    getchar();

    if(c == '1') {
        printf("Pls Enter Admin Password: ");
        char pwd[30];
        scanf("%30s", pwd);
        printf("%s", pwd);
        while(!equals(pwd, ADMIN_PWD)) {
            printf("\nWrong Password. pls ender again or quit with q: ");
            scanf("%30s", pwd);
            if(equals(pwd, (char*)"q")) {
                printf("Thank you for using our Software\n");
                exit(0);
            }
        }
            printf("Password is Correct!\nHello Admin!\n");
            isAdmin = true;
    } else {
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

    
    stringNode *stringList = (stringNode*)malloc(sizeof(stringNode*));
    stringList = NULL;
    if(!readCsv((char*)"../assets/lecturehalls.csv", &stringList)) {
        perror("FILE NOT FOUND");
        //exit(0);
    }

    lectureHall *lectureHallList = (lectureHall*)malloc(sizeof(lectureHall*));
    lectureHallList = NULL;
 
    stringlistToLectureHallList(stringList, &lectureHallList);
   // printLectureHallList(lectureHallList);
   
    return 0;
}