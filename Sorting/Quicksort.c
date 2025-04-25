#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] < x)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

void quicksort(int arr[],int p,int r){
    int stack[r - p + 1];
    int top = -1;

    stack[++top] = p;
    stack[++top] = r;

    while(top>=0){
        p = stack[top--];
        r = stack[top--];
        int x = partition(arr, p, r);
        if(x-1>p){
            stack[++top] = p;
            stack[++top] = x - 1;
        }
        if(x+1<r){
            stack[++top] = x + 1;
            stack[++top] = r;
        }
    }
}

int main()
{
    int arr[10] = {9, 6, 2, 4, 3, 1, 5, 7, 8, 10};
   quicksort(arr,0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
