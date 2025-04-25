// Given an integer array nums.WAP to find the kth largest element
#include <bits/stdc++.h>
using namespace std;

// Function to count the number of elements >= target
int countGreater(vector<int>&nums,int target){
    int count = 0;
    for(auto n:nums){
        if(n>target){
            count++;
        }
    }
    return count;
}

// Function to find the kth largest element
int kthLargest(vector<int>&nums,int k){
    int left=*min_element(nums.begin(),nums.end());
    int right=*max_element(nums.begin(),nums.end());

    while(left<right){
        int mid=left+(right-left)/2;
        int count = countGreater(nums,mid);
        if(count>=k){
            left = mid;
        }
        else{
            right = mid - 1;
        }

    }
    return left;
}
int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Example array
    int k = 2;                             // Find the 2nd largest element

    int result = kthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
}