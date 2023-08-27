#ifndef STUDENT_H_
#define STUDENT_H_
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE  30
#define MAX_COURSE_NO  30

/**********************************************
                 Data Types
**********************************************/

typedef enum {
    MAlE = 0, FEMALE,
    N_A =2
}gender;

typedef struct {
    char name[MAX_NAME_SIZE];
    unsigned int id;
    gender g;
    unsigned int year;
    float gba;
    unsigned int numCourses;
    char course_ID[MAX_COURSE_NO][6];
    unsigned int courseGrade[MAX_COURSE_NO];
}Student;


/**********************************************
                 Function Prototypes
**********************************************/
void addStudent();
void removeStudent();
void searchStudetAndDisplay();
void addCourse();
void checkID(unsigned int id);
float calculateGPA(Student student);
#endif // STUDENT_H_

