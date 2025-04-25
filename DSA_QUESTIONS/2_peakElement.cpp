//2.Given an integer array nums.WAP to find the peak element and return its index.A peak element is one which is strictly greater than its neighbours.If there are multiple peaks ,return any one.
#include <bits/stdc++.h>
using namespace std;

// Binary Search Approach :
// Compare the middle element with its neighbors.
// If the middle element is greater than both its neighbors,it is a peak.
// If the middle element is smaller than its right neighbor,there must be a peak in the right half.
// If the middle element is smaller than its left neighbor,
// there must be a peak in the left half.

int findPeak(int arr[], int n)
{
    int st = 0;
    int en = n - 1;

    while(st<en){
        int mid=st+(en-st)/2;
        if(arr[mid]>arr[mid+1] ){
            en = mid; // Peak will be left half
        }
        else{
            st = mid + 1;   //Peak will be in right half
        }
    }
    //When st==en,the loop breaks and we get the peak (any)
    return st;
}
int findPeak1(int arr[], int n)
{
    int st = 0, en = n - 1;

    while (st < en)
    {
        int mid = st + (en - st) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] > arr[mid + 1]))
        {
            return mid; // Peak found
        }
        // If left neighbor is greater, move left
        else if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            en = mid - 1;
        }
        // Otherwise, move right
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[8] = {10, 2, 4, 5, 3, 12, 11, 3};
    int n = findPeak(arr, 8);
    int k = findPeak1(arr, 8);
    cout << "Peak is at index : " << k << " and Peak element is : " << arr[k] << endl;
}
