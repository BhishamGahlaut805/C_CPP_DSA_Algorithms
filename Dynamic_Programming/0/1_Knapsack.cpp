#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

//Steps for recursion +memoization
//1.Create a DP array and initialize it(-1)
//2.Store the ans in DP array where recursive call
//3.Check after base condition if ans is present in DP array

int solve_rec(vector<int> &cost, vector<int> &wt, int capacity,int index){
    //base condition
    if(index==0){   //as index started from n-1
        if(wt[0]<=capacity){
            return cost[0];
        }
        else{
            return 0;
        }
    }
    int include=0;
    if(wt[index]<=capacity){
        include=cost[index]+solve_rec(cost,wt,capacity-wt[index],index-1);

    }
    int exclude=0+solve_rec(cost,wt,capacity,index-1);

    int ans=max(include,exclude);
    return ans;
}

int solve_DP_Mem(vector<int> &cost, vector<int> &wt, int capacity, int index,vector<vector<int>>&dp){
    // base condition
    if (index == 0)
    { // as index started from n-1
        if (wt[0] <= capacity)
        {
            return cost[0];
        }
        else
        {
            return 0;
        }
    }
    //3.Step3.Check if solution present in DP array
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = cost[index] + solve_rec(cost, wt, capacity - wt[index], index - 1);
    }
    int exclude = 0 + solve_rec(cost, wt, capacity, index - 1);

    int ans = max(include, exclude);
    //Step2.Store ans in DP array
    dp[index][capacity]=ans;
    return dp[index][capacity];
}

int knapsack_Tab(vector<int> &cost, vector<int> &wt,int n, int capacity){
    //step1.Create a Dp array
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));

    //2.Base Case
    for(int w=wt[0];w<=capacity;w++){
        if(wt[0]<=capacity){
            dp[0][w]=cost[0];
        }
    }

    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            if(wt[index]<=w){
                include=cost[index]+dp[index-1][w-wt[index]];
            }
            int exclude=0+dp[index-1][w];
            dp[index][w]=max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

int knapsack_Tab1(vector<int> &cost, vector<int> &wt, int n, int capacity)
{
   vector<int>prev(capacity+1,0);
   vector<int>curr(capacity+1,0);

    // 2.Base Case
    for (int w = wt[0]; w <= capacity; w++)
    {
        if (wt[0] <= capacity)
        {
            prev[w] = cost[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (wt[index] <= w)
            {
                include = cost[index] + prev[w - wt[index]];
            }
            int exclude = 0 + prev[w];
            curr[w] = max(include, exclude);
        }
        prev=curr;
    }
    return prev[capacity];
}

int knapsack_Tab2(vector<int> &cost, vector<int> &wt, int n, int capacity)
{
    // vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // 2.Base Case
    for (int w = wt[0]; w <= capacity; w++)
    {
        if (wt[0] <= capacity)
        {
            curr[w] = cost[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >=0; w--)
        {
            int include = 0;
            if (wt[index] <= w)
            {
                include = cost[index] + curr[w - wt[index]];
            }
            int exclude = 0 + curr[w];
            curr[w] = max(include, exclude);
        }

    }
    return curr[capacity];
}
int Knapsack(vector<int> &cost, vector<int> &wt, int capacity)
{
    int n=cost.size();
    // return solve_rec(cost,wt,capacity,n-1);
    //1.Step1 Create a DP array
    // vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    // return solve_DP_Mem(cost,wt,capacity,n-1,dp);

    //using tabluation method->bottoms up approach
    // return knapsack_Tab(cost,wt,n,capacity);
    return knapsack_Tab2(cost, wt, n, capacity);
}

int main(){
    vector<int>cost={1,2,3,4};
    vector<int>wt={9,1,3,5};
    int maxWt=10;
    cout<<"Max profit is : "<<Knapsack(cost,wt,maxWt);

}
