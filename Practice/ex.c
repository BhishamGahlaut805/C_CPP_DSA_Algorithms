#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
/***I used #define to define constants because it's a common way to declare
constants in C programs***/

/*** Structure to store student details ***/
struct Student
{
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
    char grade;
};

/*** Function to calculate grade based on marks ***/
char calculateGrade(float marks)
{
    if (marks >= 90)
        return 'A';
    else if (marks >= 80)
        return 'B';
    else if (marks >= 70)
        return 'C';
    else if (marks >= 60)
        return 'D';
    else
        return 'F';
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int n, i;
    char searchName[MAX_NAME_LENGTH];

    /*** Input the number of students ***/
    printf("Enter the number of students: ");
    scanf("%d", &n);

    /*** Input student details ***/
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        /*** Calculate grade ***/
        students[i].grade = calculateGrade(students[i].marks);
    }

    /*** Search for student marks by name ***/
    printf("\nEnter the name of the student to search for: ");
    scanf("%s", searchName);

    /*** Loop through the array to find the student ***/
    for (i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, searchName) == 0)
        {
            printf("Marks of %s: %.2f\n", searchName, students[i].marks);
            break;
        }
    }

    if (i == n)
        printf("Student with name '%s' not found.\n", searchName);

    return 0;
}