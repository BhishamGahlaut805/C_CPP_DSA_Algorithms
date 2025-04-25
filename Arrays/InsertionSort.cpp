#include <iostream>
#include <vector>
using namespace std;
void insertion_sort(vector<int>&arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int current_value = arr[i];
        int j = i - 1;
        while (arr[j] > current_value && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current_value;
    }
}
int main()
{
    vector<int> arr = {4, 6, 1, 2, 10, 3, 8, 7, 9, 5};
    insertion_sort(arr);
    cout << "Sorted Array : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
}