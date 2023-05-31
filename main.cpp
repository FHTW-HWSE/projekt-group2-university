#include "headerFiles/headers.h"
int main()
{

    
    stringNode *stringList = (stringNode*)malloc(sizeof(stringNode*));
    stringList = NULL;
    if(!readCsv((char*)"../assets/lecturehalls.csv", &stringList)) {
        perror("FILE NOT FOUND");
        //exit(0);
    }
    //writeCsv((char*)"../assets/username.csv", test);

    lectureHall *lh = (lectureHall*)malloc(sizeof(lectureHall*));
    lh = NULL;
    //stringlistToLectureHallList(stringList, &lh);

    //printLectureHall(a);
   
    printStringList(stringList);

    //printLectureHall(a);
    stringlistToLectureHallList(stringList, &lh);
    printLectureHallList(lh);
   
    return 0;
}