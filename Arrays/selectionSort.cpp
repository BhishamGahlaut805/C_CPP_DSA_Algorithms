// Selection Sort
#include <iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int>&arr){
    int n = arr.size();
    int minidx;
    for (int i = 0; i < n - 1; i++){
        minidx = i;
        for (int j = minidx + 1; j < n; j++){
            if (arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }}}
int main(){
    vector<int> arr = {4, 6, 1, 2, 10, 3, 8, 7, 9, 5};
    selection_sort(arr);
    cout << "Sorted Array : ";
    for(auto i:arr){
        cout << i << " ";
    }
}