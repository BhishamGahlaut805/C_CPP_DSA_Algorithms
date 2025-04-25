#include<bits/stdc++.h>
using namespace std;

//Conventional->O(n)
pair<int, int> maximini(vector<int>& arr)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i : arr)
    {
        if (i > maxi)
        {
            maxi = i;
        }
        else
        {
            mini = i;
        }
    }
    return {maxi, mini};
}

//Using DAC-O(log n)
pair<int,int>MINIMAXI(vector<int>&arr,int low,int high){
    pair<int, int> ans;
    if(low==high){
        return {arr[low], arr[high]};
    }
    if(high==low+1){
        if(arr[high]>arr[low]){
            return {arr[low], arr[high]};
        }
        else{
            return {arr[high], arr[low]};
        }

    }
    int mid = low + (high - low) / 2;
    pair<int, int> left = MINIMAXI(arr, low, mid);
    pair<int, int> right = MINIMAXI(arr, mid + 1, high);
    ans = {min(left.first, right.first), max(left.second, right.second)};
    return ans;
}
int main()
{

    vector<int> arr = {1, 4, 2, 42, 211};
    // pair<int, int> ans = maximini(arr);
    pair<int, int> ans = MINIMAXI(arr, 0, 4);
    cout << "Max " << ans.first << " Min " << ans.second;

}
