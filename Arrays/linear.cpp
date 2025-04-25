#include <iostream>
#include<vector>
using namespace std;
int linear_search(vector<int>&arr, int val)
{
    for (int i = 0; i < arr.size();i++)
    {
        if (arr[i] == val){
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int>arr = {2, 5, 22, 89, 42, 14, 90, 2, 76, 89};
    cout << "Searching for 76 in array : " << linear_search(arr, 76) << endl;
    cout << "Searching for 7 in array : " << linear_search(arr, 7);
}