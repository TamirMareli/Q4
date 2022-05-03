#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> //uncomment this block to check for heap memory allocation leaks.
// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct StudentCourseGrade
{
	char courseName[35];
	int grade;
}StudentCourseGrade;

typedef struct Student
{
	char name[35];
	StudentCourseGrade* grades; //dynamic array of courses
	int numberOfCourses;
}Student;


//Part A
void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
int countPipes(const char* lineBuffer, int maxCount, char terminator);
char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents);
void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents);
void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor);
void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents);

//Part B
Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents);
void writeToBinFile(const char* fileName, Student* students, int numberOfStudents);
Student* readFromBinFile(const char* fileName);

int main()
{
	//Part A
	int* coursesPerStudent = NULL;
	int numberOfStudents = 0;
	char*** students = makeStudentArrayFromFile("studentList.txt", &coursesPerStudent, &numberOfStudents);
	factorGivenCourse(students, coursesPerStudent, numberOfStudents, "Advanced Topics in C", +5);
	printStudentArray(students, coursesPerStudent, numberOfStudents);
	//studentsToFile(students, coursesPerStudent, numberOfStudents); //this frees all memory. Part B fails if this line runs. uncomment for testing (and comment out Part B)

	//Part B
	Student* transformedStudents = transformStudentArray(students, coursesPerStudent, numberOfStudents);
	writeToBinFile("students.bin", transformedStudents, numberOfStudents);
	Student* testReadStudents = readFromBinFile("students.bin");

	//add code to free all arrays of struct Student


	/*_CrtDumpMemoryLeaks();*/ //uncomment this block to check for heap memory allocation leaks.
	// Read https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

	return 0;
}

void countStudentsAndCourses(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
{
	FILE* f=fopen("studentList.txt", "r");
	if (f == NULL) { exit(1); }
	int numOfRow = 0;
	int numOfCurse = 0;
	char ch;
	while (feof(f)) {
		ch = fgetc(f);
		if (ch == '\n')
			numOfRow++;
	}
	rewind(f);

	coursesPerStudent = (int**)malloc(sizeof(int*));
	if (coursesPerStudent == NULL) { printf("allocation failde"); exit(1); }
	ch = fgetc(f);
	for (int i = 0; i < numOfRow; i++) {
		while (ch != '\n') {
			if (ch == '|')
				numOfCurse++;
			ch = fgetc(f);
		}
		coursesPerStudent[i] = (int*)malloc(sizeof(int));
		if (coursesPerStudent == NULL) { printf("allocation failde"); exit(1); }
		*coursesPerStudent[i] = numOfCurse;
		numOfCurse = 0;
	}
	fclose(f);
}

int countPipes(const char* lineBuffer, int maxCount, char terminator)
{
	if (lineBuffer== NULL) { return -1; }
	if (maxCount <= 0) { return 0; }
	int count = 0;
	for (int i = 0; i < maxCount; i++) {
		if (lineBuffer[i] == '\0') { return count; }
		if (lineBuffer[i] == '|') { count++; }
	}
	return count;
}

char*** makeStudentArrayFromFile(const char* fileName, int** coursesPerStudent, int* numberOfStudents)
{
	countStudentsAndCourses(fileName, coursesPerStudent, numberOfStudents);
	FILE* f = fopen("studentList.txt", "r");
	if (f == NULL) { exit(1); }
	char*** arrayS = (char***)malloc(sizeof(char**) *(*numberOfStudents) );
	if (arrayS == NULL) { printf("alloction failde\n"); exit(1); }
	for (int i = 0; i < *numberOfStudents; i++) {
		arrayS[i] = (char**)malloc(sizeof(char*) * (1 + 2 * sizeof(*coursesPerStudent[i])));
		if(arrayS[i]==NULL){ printf("alloction failde\n"); exit(1); }

	}

}

void factorGivenCourse(char** const* students, const int* coursesPerStudent, int numberOfStudents, const char* courseName, int factor)
{
	//add code here
}

void printStudentArray(const char* const* const* students, const int* coursesPerStudent, int numberOfStudents)
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		printf("name: %s\n*********\n", students[i][0]);
		for (int j = 1; j <= 2 * coursesPerStudent[i]; j += 2)
		{
			printf("course: %s\n", students[i][j]);
			printf("grade: %s\n", students[i][j + 1]);
		}
		printf("\n");
	}
}

void studentsToFile(char*** students, int* coursesPerStudent, int numberOfStudents)
{
	//add code here
}

void writeToBinFile(const char* fileName, Student* students, int numberOfStudents)
{
	//add code here
}

Student* readFromBinFile(const char* fileName)
{
	//add code here
}

Student* transformStudentArray(char*** students, const int* coursesPerStudent, int numberOfStudents)
{
	//add code here
}
