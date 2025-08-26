#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        vector<pair<int, int>> pointspair;
        for (int i = 0; i < points.size(); i++)
        {
            pointspair.push_back({points[i][1], points[i][0]});
        }

        sort(pointspair.begin(), pointspair.end());
        int start = pointspair[0].first;
        int cnt = 1;
        for (int i = 0; i < points.size(); i++)
        {
            if (pointspair[i].second <= start)
            {
                // These points could be shot with some arrow
                continue;
            }
            else
            {
                // we will increase the count
                cnt++;
                // and update the new start
                start = pointspair[i].first;
            }
        }
        return cnt;
    }
};

int main(){

    vector<vector<int>>points={{1,4},{4,8},{10,14},{5,8},{11,77}};
    Solution sol;
    int ans=sol.findMinArrowShots(points);
    cout<<ans<<endl;
}

