#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int area = INT_MIN;
        while (left < right)
        {
            int w = right - left;
            area = max(area, w * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return area;
    }
};
int main()
{
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(height) << endl; // Output: 49
}
