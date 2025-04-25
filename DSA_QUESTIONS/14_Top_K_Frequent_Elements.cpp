#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            freq[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        for (auto i : freq)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 6, 6, 4, 2, 2, 8, 8, 2, 4, 5, 3, 1};
    vector<int> ans = sol.topKFrequent(nums, 3);
    cout << "Top 3 most frequent Elements in nums are : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
}