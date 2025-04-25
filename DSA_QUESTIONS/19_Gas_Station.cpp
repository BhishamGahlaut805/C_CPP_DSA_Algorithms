#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int TotalGas = 0;
        int TotalCost = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            TotalGas += gas[i];
            TotalCost += cost[i];
        }
        if (TotalGas < TotalCost)
        {
            return -1;
        }
        int startingIdx = 0;
        int CurrentGas = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            CurrentGas += gas[i] - cost[i];
            if (CurrentGas < 0)
            {
                CurrentGas = 0;
                startingIdx = i + 1;
            }
        }
        return startingIdx;
    }
};

int main(){
    Solution sol;
   vector<int> gas = { 1, 2, 3, 4, 5 };
   vector<int> cost = { 3, 4, 5, 1, 2 };
   cout<<sol.canCompleteCircuit(gas,cost)<<endl;
}
