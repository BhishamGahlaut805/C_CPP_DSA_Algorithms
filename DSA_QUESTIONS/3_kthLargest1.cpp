#include <iostream>
using namespace std;

int pivot(int arr[], int low, int high)
{
    int x = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int kthlargest(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int x = pivot(arr, low, high);
        if (x == (n - k))
        {
            return arr[x];
        }
        else if (x > (n - k))
        {
            high = x - 1;
        }
        else
        {
            low = x + 1;
        }
    }
    return -1;
}
int main()
{
    // Write C++ code here
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "2nd largest number is : " << kthlargest(arr, 5, 2) << endl;
    cout << "3rd largest number is : " << kthlargest(arr, 5, 3) << endl;

    return 0;
}