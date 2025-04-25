//1. Given a sorted array.Count the target element occurences in it
#include<bits/stdc++.h>
using namespace std;
/*
Approach
Find the first occurrence of the target element using binary search.
Find the last occurrence of the target element using binary search.
The number of occurrences is the difference between the indices of the last and first occurrence, plus 1.
*/
// If left and right are large integers, adding them together (left +(right) may exceed the maximum limit of the integer type, causing an overflow.

// Applying Binary Search Twice
int Occurence(int arr[],int n,int target,bool isleft){
    int st = 0;
    int en = n-1;
    int res = -1;
    while(st<en){
        int mid = st+(en-st)/2;

        if(arr[mid]==target){
            res = mid;
            if(isleft){
                en = mid - 1; // Searching in left half
            }
            else{
                st = mid + 1;
            }
        }
        else if(arr[mid]>target){
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return res;
}

int countOcc(int arr[],int n,int target){
    int first = Occurence(arr,n,target,true);
    if(first==-1){
        return -1;  //Target not found
    }
    int last =Occurence(arr, n, target,false);
    return last - first + 1;
}

int main(){
    //TestCase
    int arr[10] = {2, 4, 5, 5, 5, 5, 7, 8, 9, 10};
    cout <<"The Number of Occurences of 5 in array is : "<< countOcc(arr, 10, 5);
}