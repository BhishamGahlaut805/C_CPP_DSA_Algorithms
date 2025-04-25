#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int i, int n)
{
    int l = 2 * i + 1; // Index of left node
    int r = 2 * i + 2; // Index of right node
    int largest = i;   // Assume the largest element is the root

    if (l < n && arr[l] > arr[largest]) // Check if left child is larger than root
    {
        largest = l; // Update largest to left child
    }

    if (r < n && arr[r] > arr[largest]) // Check if right child is larger than current largest
    {
        largest = r; // Update largest to right child
    }

    if (largest != i) // If the largest is not root
    {
        swap(&arr[i], &arr[largest]); // Swap root with the largest
        maxHeapify(arr, largest, n);  // Recursively heapify the affected subtree
    }
}
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Start from the last non-leaf node and move to root
    {
        maxHeapify(arr, i, n); // Ensure each subtree is a max heap
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, 0, i);
    }
}

int main()
{
    int arr[6] = {34, 12, 89, 21, 56, 87};
    int arr1[10] = {8, 7, 5, 6, 9, 4, 2, 1, 3, 10};
    heapSort(arr, 6);
    heapSort(arr1, 10);
    printf("Sorted arr is : ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
 
    printf("\nSorted arr1 is : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}
