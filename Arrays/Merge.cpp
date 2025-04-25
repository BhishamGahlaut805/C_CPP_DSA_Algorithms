#include<iostream>
using namespace std;
#define infinite 100000
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
};
void mergesort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
};
int main()
{
    int arr[10] = {4, 6, 1, 2, 10, 3, 8, 7, 9, 5};
    mergesort(arr,0,9);
    cout << "Sorted Array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
