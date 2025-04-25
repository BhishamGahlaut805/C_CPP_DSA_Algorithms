// kth missing element
#include <iostream>
using namespace std;

int kthmissing(int arr[], int n, int k)
{
    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid] - (mid + 1) < k)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return k + st;
}

int main()
{
    // Write C++ code here
    int arr[5] = {2, 4, 6, 8, 10};
    for (auto n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << "First Missing : " << kthmissing(arr, 5, 1) << endl;
    cout << "Second Missing : " << kthmissing(arr, 5, 2) << endl;
    cout << "Third Missing : " << kthmissing(arr, 5, 3) << endl;
    cout << "Fourth Missing : " << kthmissing(arr, 5, 4) << endl;
    cout << "Fifth Missing : " << kthmissing(arr, 5, 5) << endl;

    return 0;
}

// 2.kth largest

// Online C++ compiler to run C++ program online
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
    cout << "1st largest number is : " << kthlargest(arr, 5, 1) << endl;
    cout << "2nd largest number is : " << kthlargest(arr, 5, 2) << endl;
    cout << "3rd largest number is : " << kthlargest(arr, 5, 3) << endl;
    cout << "4th largest number is : " << kthlargest(arr, 5, 4) << endl;
    cout << "5th largest number is : " << kthlargest(arr, 5, 5) << endl;

    return 0;
}

// 3.duplicates in sorted array

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int bound(int arr[], int n, int target, bool islowerb)
{
    int st = 0;
    int en = n - 1;
    int res = -1;
    while (st < en)
    {
        int mid = st + (en - st) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            if (islowerb)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else if (arr[mid] < target)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }
    return res;
}
int duplicate(int arr[], int n, int target)
{
    return bound(arr, n, target, false) - bound(arr, n, target, true) + 1;
}
int main()
{
    int arr[10] = {1, 2, 3, 3, 3, 3, 7, 8, 9, 10};
    cout << duplicate(arr, 10, 3) << endl;

    return 0;
}