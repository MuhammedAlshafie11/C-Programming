/*
 ============================================================================
 Name        : Student.c
 Author      : Muhammed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Students.h"
#include "Courses.h"
enum {
	AddStudent = 1, SearchStudent, RemoveStudent, AddCourse, EXIT
};


unsigned int user_choice;
int main(void) {
	do {
		printf("Welcome to the School of Engineering \n");
		printf("choose 1 to Add a Student \n");
		printf("choose 2 to Search a Student using the ID\n");
		printf("choose 3 to Remove a Student using the ID \n");
		printf("choose 4 to Add Course  \n");
		printf("choose 5 to Exit the Program\n");
		scanf("%d", &user_choice);
		if (user_choice == AddStudent) {
			printf("Choice 1\n");
			addStudent();
		}
		else if (user_choice == SearchStudent) {
			printf("Choice 2\n");
			searchStudetAndDisplay();
		}
		else if (user_choice == RemoveStudent) {
			printf("Choice 3\n");
			removeStudent();
		}
		else if (user_choice == AddCourse) {
			printf("Choice 4\n");
			addCourse();
			
		}

	} while (user_choice != EXIT);
	printf("Choice 5\n");
	return 0;
}
