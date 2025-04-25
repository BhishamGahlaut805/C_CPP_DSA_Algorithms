#include <iostream>
using namespace std;
int binary_search(int arr[], int st, int en, int val)
{
    if (st <= en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            return binary_search(arr, st, mid - 1, val);
        }
        else
        {
            return binary_search(arr, mid + 1, en, val);
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {2, 5, 22, 89, 42, 14, 90, 2, 76, 89};
    cout << "Searching for 76 in array : " << binary_search(arr, 0,9,76) << endl;
    cout << "Searching for 7 in array : " << binary_search(arr, 0,9,7);
}