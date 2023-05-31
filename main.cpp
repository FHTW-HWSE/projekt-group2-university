#include "headerFiles/headers.h"
int main()
{

    
    stringNode *stringList = (stringNode*)malloc(sizeof(stringNode*));
    stringList = NULL;
    if(!readCsv((char*)"../assets/username.csv", &stringList)) {
        perror("FILE NOT FOUND");
        //exit(0);
    }
    //writeCsv((char*)"../assets/username.csv", test);

    lectureHall *lh = (lectureHall*)malloc(sizeof(lectureHall*));
    lh = NULL;
    //stringlistToLectureHallList(stringList, &lh);

    lectureHall *a = createLectureHallFromString((char*)"F202;4;3");
   
    printStringList(stringList);
    return 0;
}