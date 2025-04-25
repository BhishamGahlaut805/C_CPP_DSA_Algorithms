#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}
int main()
{
    vector<int> arr = {4, 6, 1, 2, 10, 3, 8, 7, 9, 5};
    bubble_sort(arr);
    cout << "Sorted Array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}