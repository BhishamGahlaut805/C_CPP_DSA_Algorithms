#include <stdio.h>

void patternlowerTriangle(int matrix[3][3], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i < j)
            {
                printf(" ");
            }
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void patternUpperTriangle(int matrix[3][3], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i > j)
            {
                printf(" ");
            }
            else
                printf("%d", matrix[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    patternlowerTriangle(mat, 3, 3);
    printf("\n\n");
    patternUpperTriangle(mat, 3, 3);
}