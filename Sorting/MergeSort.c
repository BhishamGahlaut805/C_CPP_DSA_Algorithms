#include <stdio.h>
#include <stdlib.h>
#define infinite 100000

int min(int a, int b)
{
    return (a < b) ? a : b;
}
void merge(int A[], int p, int q, int r)
{
    int n1 = (q - p + 1);
    int n2 = (r - q);
    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = A[q + i + 1];
    }
    L[n1] = infinite;
    R[n2] = infinite;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergesort(int arr[], int n)
{
    for (int i = 1; i < n; i *= 2)
    {
        for (int j = 0; j < n; j += 2 * i)
        {
            int mid = min(i + j - 1, n - 1);
            int r = min(j + 2 * i - 1, n - 1);

            merge(arr, j, mid, r);

            printf("Inner loop iteration %d : ", j);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        printf("\nArray after %d iteration : ", i);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, n);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
