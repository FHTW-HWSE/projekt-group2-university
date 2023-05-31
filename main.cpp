#include "headerFiles/headers.h"
int main()
{


    

    
    stringNode *stringList = (stringNode*)malloc(sizeof(stringNode*));
    stringList = NULL;
    if(!readCsv((char*)"../assets/lecturehalls.csv", &stringList)) {
        perror("FILE NOT FOUND");
        //exit(0);
    }

    lectureHall *lectureHallList = (lectureHall*)malloc(sizeof(lectureHall*));
    lectureHallList = NULL;
 
    stringlistToLectureHallList(stringList, &lectureHallList);
    printLectureHallList(lectureHallList);
   
    return 0;
}