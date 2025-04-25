#include <stdio.h>
#include <string.h>
struct student
{
    char name[100];
    int roll_no;
    int sem;
    char branch[20];
};

int main()
{
    struct student students[50]; // Array of structure
    char search[100];
    int n;
    printf("Enter No. of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Details for student %d :\n", i + 1);
        printf("Name : ");
        scanf("%s", &students[i].name);
        printf("Roll no. : ");
        scanf("%d", &students[i].roll_no);
        printf("Semester : ");
        scanf("%d", &students[i].sem);
        printf("Branch : ");
        scanf("%s", &students[i].branch);
    }
    printf("\n Details of All Students:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Detail of Student %d :\n", i + 1);
        printf(" Name : %s ", students[i].name);
        printf("\n Roll No. : %d ", students[i].roll_no);
        printf("\n Semester : %d ", students[i].sem);
        printf("\n Branch : %s \n", students[i].branch);
    }
    printf("\n Enter name of student you want to search:\n");
    scanf("%s", search);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, search) == 0)
        {
            printf("Detail of Student %d :\n", i + 1);
            printf("\n Name : %s ", students[i].name);
            printf("\n Roll No. : %d ", students[i].roll_no);
            printf("\n Semester : %d ", students[i].sem);
            printf("\n Branch : %s ", students[i].branch);
        }
        else if (i == n)
        {
            printf("Not Found");
        }
    }
}