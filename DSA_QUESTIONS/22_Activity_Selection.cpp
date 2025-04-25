#include<bits/stdc++.h>
using namespace std;

// Given n activities with their start and finish times given in array start[] and finish[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
class Solution{
    public:
    int activitySelection(vector<int> &start, vector<int> &finish){
        int n=start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({finish[i],start[i]});
        }
        sort(v.begin(),v.end());
        int count=1;
        int lastFinish=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>=lastFinish){
                count++;
                lastFinish=v[i].first;
            }
        }
        return count;
    }
};
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>finish={2,4,6,7,9,9};
    Solution sol;
   cout<<"The Maximum activities can be performed are : "<< sol.activitySelection(start,finish);
}