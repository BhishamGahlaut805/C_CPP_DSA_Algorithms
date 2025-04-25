#include<bits/stdc++.h>
using namespace std;
int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] < x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
void quicksort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
int main()
{
    int arr[10] = {4, 6, 1, 2, 10, 3, 8, 7, 9, 5};
    quicksort(arr, 0, 9);
    cout << "Sorted Array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}
