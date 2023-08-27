#include "Students.h"
#include "Courses.h"
#include <string.h>

#define MAX_NO_STUD 2
#define MAX_ACD_YEAR 2014

/* Creating Array of Students */

/***************************************
          Function Definition
***************************************/
Student pupils[MAX_NO_STUD]; // creat an array of students 
static unsigned int PupilIndex = 0; // to loop inside the array of Pupils

void addStudent() {
    if (PupilIndex == MAX_NO_STUD) {
        printf("........SYSTEM IS FULL NO ROOM TO ADD MORE STUDENT........\n");
        return;
    }
    printf("Please enter your First and Last name Without Spaces\n");
    scanf("%s", &pupils[PupilIndex].name);
// check the name if it has any integer
    char* str = pupils[PupilIndex].name;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            printf("You entered wrong name please enter it again \n");
            scanf("%s", &pupils[PupilIndex].name);
            i = 0;
        }
    }


    printf("Please enter your ID\n");
    scanf("%d", &pupils[PupilIndex].id);
    checkID(pupils[PupilIndex].id);



    printf("Please choose male or female with 0 or 1\n");
    scanf("%d", &pupils[PupilIndex].g);
    while (pupils[PupilIndex].g != 0 && pupils[PupilIndex].g != 1) {
        printf("you entered wrong number please reenter male or female with 0 or 1\n ");
        scanf("%d", &pupils[PupilIndex].g);

    }


    printf("Please enter the year\n");
    scanf("%d", &pupils[PupilIndex].year);
    while (pupils[PupilIndex].year > MAX_ACD_YEAR) {
        printf("you entered wrong year Please Enter again \n ");
        scanf("%d", &pupils[PupilIndex].year);
    }


     printf("Please enter your number of courses \n");
     scanf("%d", &pupils[PupilIndex].numCourses);
     while (pupils[PupilIndex].numCourses > MAX_COURSE_NO || pupils[PupilIndex].numCourses < 0 ) {
         printf("You entered wrong number of courses please try again  \n");
         scanf("%d", &pupils[PupilIndex].numCourses);
     }




    
    for (unsigned int i = 0; i < pupils[PupilIndex].numCourses; i++) {
        printf("Please enter your courses ID\n");
        scanf("%s", &pupils[PupilIndex].course_ID[i]);
        str = pupils[PupilIndex].course_ID[i];
        while (str != NULL) {
            if (str[0] =='0') {
                printf("You Entered A wrong ID Try again Please \n");
                scanf("%s", &pupils[PupilIndex].course_ID[i]);
            }
            else if (strlen(pupils[PupilIndex].course_ID[i]) > 6) {
                printf("You Entered A wrong ID Try again Please \n");
                scanf("%s", &pupils[PupilIndex].course_ID[i]);
            }
            else {
                str = NULL;
            }
            
        }
    }
  


    
    for (unsigned int i = 0; i < pupils[PupilIndex].numCourses; i++) {
        printf("Please enter your courses Grade\n");
        scanf("%d", &pupils[PupilIndex].courseGrade[i]);
        while (pupils[PupilIndex].courseGrade[i] > 100 || pupils[PupilIndex].courseGrade[i] < 0) { //  to check that the grade is within range
            printf("You Entered A wrong grade Try again Please \n");
            scanf("%d", &pupils[PupilIndex].courseGrade[i]);
        }
    }

    printf("\n");

    pupils[PupilIndex].gba = calculateGPA(pupils[PupilIndex]);
    
    PupilIndex++;
}
void searchStudetAndDisplay() {
    unsigned int id = 0;
    printf("Please enter the student ID\n");
    scanf("%d", &id);
    
    // to check we have Registered a student first
    if (PupilIndex == 0) {
        printf("Student with ID %d not found.\n", id);
    }

    int studentFound = 0; // Flag to track if the student is found
     
    //Displaying all the characteristics of the student 
    for (unsigned int j = 0; j < PupilIndex; j++) {
        if (id == pupils[j].id) {
            studentFound = 1;
            printf("Student name is %s\n", pupils[j].name);
            printf("Student ID is %d\n", pupils[j].id);
            if (pupils[j].g) {
                printf("Student Gender is Female\n");
            }
            else {
                printf("Student Gender is male\n");
            }
            printf("Student ACD YEAR is %d\n", pupils[j].year);

            for (unsigned int CouIdIndex = 0; CouIdIndex < pupils[j].numCourses; CouIdIndex++) {
                for (unsigned int CourseIndex = 0; CourseIndex < MAX_COURSE_NO; CourseIndex++) {
                    if (strcmp(pupils[j].course_ID[CouIdIndex], courses_list[CourseIndex].id) == 0) {
                        printf("Course ID is %s\n", pupils[j].course_ID[CouIdIndex]);
                        printf("Course Name is %s\n", courses_list[CourseIndex].course_name);
                        printf("Course Grade is %d\n", pupils[j].courseGrade[CouIdIndex]);
                    }
                }

            }
            printf("Student GPA: %.2f\n", pupils[j].gba);
            printf("\n");
        }
    }
    if (!studentFound) {
        printf("Student with ID %d not found.\n", id);
    }

}
void removeStudent() {
    unsigned int id = 0;
    printf("Please enter the student ID\n");
    scanf("%d", &id);

    // to check we have Registered a student first
    if (PupilIndex == 0) {
        printf("Student with ID %d not found.\n", id);
    }
    int foundIndex = -1; // To keep track of the index where the student is found

    // Find the index of the student with the given ID
    for (unsigned int i = 0; i < PupilIndex; i++) {
        if (pupils[i].id == id) {
            foundIndex = i;
            break; // Found the student, exit the loop
        }
    }

    if (foundIndex != -1) {
        // Shift elements to remove the student
        for (unsigned int i = foundIndex; i < PupilIndex - 1; i++) {
            pupils[i] = pupils[i + 1];
        }
        PupilIndex--; // Decrement the number of registered students
        printf("Student with ID %d has been removed.\n", id);
    }
    else {
        printf("Student with ID %d not found.\n", id);
    }
}
void addCourse() {
    unsigned int id = 0;
    printf("Please enter the student ID\n");
    scanf("%d", &id);
    unsigned char new_courseID[6] ;
    unsigned int new_courseGrade ;
    unsigned int studentIndex = 0;
    // to check we have Registered a student first
    if (PupilIndex == 0) {
        printf("Student with ID %d not found.\n", id);
    }
    int studentFound = 0; // Flag to track if the student is found
    for (unsigned int j = 0; j < PupilIndex; j++) {
        if (id == pupils[j].id) {
            studentFound = 1;
            studentIndex = j; // to save the index of the student in the array who we have his ID
        }
        // Enter the new Course ID 
        printf("Please enter the new course ID\n");
        scanf("%s", &new_courseID);
        while (new_courseID[0] == '0' || strlen(new_courseID) >= 6) {
            printf("You Entered A wrong ID Try again Please \n");
            scanf("%s", new_courseID);
        }

        // Enter the New Grade
        printf("Please enter the new  course Grade\n");
        scanf("%d", &new_courseGrade);
        while (new_courseGrade > 100 || new_courseGrade < 0) { //  to check that the grade is within range
            printf("You Entered A wrong grade Try again Please \n");
            scanf("%d", &new_courseGrade);
        }

        strcpy(pupils[studentIndex].course_ID[pupils[studentIndex].numCourses], new_courseID);
        pupils[studentIndex].courseGrade[pupils[studentIndex].numCourses] = new_courseGrade;
        pupils[studentIndex].numCourses++; // because we added a new course ;
        pupils[studentIndex].gba = calculateGPA(pupils[studentIndex]);
    }

    if (!studentFound) {
        printf("Student with ID %d not found.\n", id);
    } 


}


void checkID(unsigned int id) {
    unsigned int count = 0;
    while (id != 0)
    {
        id = id / 10;

        count++;
    }
    if (count != 7) {
        printf("THIS ID YOU ENTERED IS NOT 7 DIGITS PLEASE ENTER A NEW ONE \n");
        scanf("%d", &pupils[PupilIndex].id);
        checkID(pupils[PupilIndex].id);
    }
    for (unsigned int j = 0; j < PupilIndex; j++) {
        if (pupils[PupilIndex].id == pupils[j].id) {
            printf("THIS ID IS ALERADY EXISIT PLEASE ENTER A NEW ONE\n");
            scanf("%d", &pupils[PupilIndex].id);
            checkID(pupils[PupilIndex].id);
        }
    }
}
float calculateGPA(Student student) {
    float totalPoints = 0.0;
    int totalCredits = 0;

    for (unsigned int i = 0; i < pupils[PupilIndex].numCourses; i++) {


        totalPoints += (float)(student.courseGrade[i] * courses_list[i].creditHours);
        totalCredits += courses_list[i].creditHours;
    }

    if (totalCredits == 0) {
        return 0.0;  // To avoid division by zero
    }

    return totalPoints / totalCredits;
}

