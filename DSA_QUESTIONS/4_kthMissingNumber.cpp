// Given a array nums of positive integers sorted in a strictly increasing order and an integer k.Return the kth positive integer mising from the array. Binary search
#include <bits/stdc++.h>
using namespace std;

//Binary Search Appraoch
/*Given a strictly increasing sorted array nums and an integer k, we need to find the kth positive integer that is missing from the array.
For example,
if nums = [ 2, 3, 4, 7, 11 ] and k = 5, the missing positive integers are[1,5, 6, 8, 9, 10, 12, ...].The 5th missing positive integer is 9.*/

// For any index i in the array, the number of missing positive integers before nums[i] is given by:
//missing_count = nums[i] - (i + 1)->0 based indexing

int kthMissing(int arr[],int n,int k){
    int st = 0;
    int en = n - 1;
    while(st<en){
        int mid=st+(en-st)/2;
        if(arr[mid]-(mid+1)<k){
            st = mid + 1;   //Searching in rigtht half
        }
        else{
            en = mid - 1;   //Left half
        }
    }
    return k + st;
    // After the binary search, left will point to the smallest index where nums[i] - (i + 1) >= k.


}
int main(){
    int nums[5] = {2, 3, 4, 7, 11}; // Example array
    int k = 5;                           // Find the 5th missing positive integer

    int result = kthMissing(nums,5, k);
    cout << "The " << k << "th missing positive integer is: " << result << endl;
}
