#include <bits/stdc++.h>
using namespace std;

// Conventional -> O(n)
pair<int, int> maximini(vector<int> &arr)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i : arr)
    {
        if (i > maxi)
        {
            maxi = i;
        }
        if (i < mini) // Fix: Separate condition for mini
        {
            mini = i;
        }
    }
    return {mini, maxi};
}

// Using Divide and Conquer -> O(log n)
pair<int, int> MINIMAXI(vector<int> &arr, int low, int high)
{
    if (low == high)
        return {arr[low], arr[low]}; 

    if (high == low + 1)
    {
        if (arr[high] > arr[low])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    int mid = low + (high - low) / 2;
    pair<int, int> left = MINIMAXI(arr, low, mid);
    pair<int, int> right = MINIMAXI(arr, mid + 1, high);

    // Combine results from both halves
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main()
{
    vector<int> arr = {1, 4, 2, 42, 211};

    pair<int, int> ans1 = maximini(arr);
    pair<int, int> ans2 = MINIMAXI(arr, 0, arr.size() - 1);

    cout << "Conventional : Min " << ans1.first << ", Max " << ans1.second << endl;
    cout << "Using DAC    : Min " << ans2.first << ", Max " << ans2.second << endl;

}
