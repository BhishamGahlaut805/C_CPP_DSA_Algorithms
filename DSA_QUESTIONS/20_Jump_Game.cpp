#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > farthest)
            {
                return false;
            }
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << sol.canJump(nums) << endl; 
}