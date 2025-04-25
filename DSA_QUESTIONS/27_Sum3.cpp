#include<bits/stdc++.h>
using namespace std;

//3-Sum Problem using 2 pointers
//Approach->Sort the array ,fix 1 pointer and move 2 pointers to get the solution in O(n^2)
//Similarly for 4 sum apprach->fix 2 pointers and move 2 and get the solution in O(n^3)
class Solution_4Sum
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int p = 0; p < n; ++p)
        {
            if (p > 0 && nums[p] == nums[p - 1])
            {
                continue;
            }
            for (int i = p + 1; i < n; ++i)
            {
                if (i > p + 1 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = n - 1;

                while (left < right)
                {
                    long long sum = (long long)nums[p] + nums[i] + nums[left] + nums[right];

                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        ans.push_back({nums[p], nums[i], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] && (j < k))
                    {
                        j++; // For Not getting same ans because of equal elements
                    }
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = { -1, 0, 1, 2, -1, -4};
     vector<vector<int>> ans = sol.threeSum(nums);
     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
     }
    }

//Time Complexity:O(n^2)->3SUM
//O(n^3)->4SUM



