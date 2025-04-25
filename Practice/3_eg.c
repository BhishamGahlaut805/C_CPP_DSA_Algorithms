#include <stdio.h>

void matrixmultiply(int n1, int n2, int n3, int m1[n1][n2], int m2[n2][n3])
{
    int ans[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            ans[i][j] = 0; // MUST STEP !!!! to avoid garbage value
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            for (int k = 0; k < n3; k++)
            {
                ans[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int m11[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int m22[3][2] = {{1, 2}, {4, 5}, {3, 6}};
    matrixmultiply(2, 3, 2, m11, m22);

    int m1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int m2[3][2] = {{1, 2}, {4, 5}, {3, 6}};
    printf("\n\n");
    int ans[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][k] += m1[i][j] * m2[j][k];
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    int a[2][2] = {1, 2, 3, 4};
    int b[2][2] = {1, 2, 3, 4};

    int ans123[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans123[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans123[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", ans123[i][j]);
        }
        printf("\n");
    }
    return 0;
}