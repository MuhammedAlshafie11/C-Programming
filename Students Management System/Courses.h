#ifndef COURSES_H_
#define COURSES_H_
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_NO 30
/**********************************************
                 Data Types
**********************************************/
typedef struct {
    char id[6];
    char course_name[100];
    int  creditHours;
}Course;
extern Course courses_list[MAX_LIST_NO];
#endif // COURSES_H_
