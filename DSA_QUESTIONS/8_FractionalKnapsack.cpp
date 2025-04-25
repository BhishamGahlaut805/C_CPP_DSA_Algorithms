//Fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

double knapsack(vector<int> &values, vector<int> &weights, int maxW)
{
    int n = values.size();
    vector<pair<double, int>> itemProfit(n);

    // Calculate profit/weight ratio and store index
    for (int i = 0; i < n; i++)
    {
        itemProfit[i] = {(double)values[i] / weights[i], i};
    }

    // Sort items by highest profit/weight ratio
    sort(itemProfit.rbegin(), itemProfit.rend());

    int i = 0;
    double ans = 0.0;

    while (maxW > 0 && i < n)
    {
        int idx = itemProfit[i].second;
        if (maxW >= weights[idx])
        {
            maxW -= weights[idx];
            ans += values[idx];
        }
        else
        {
            ans += (maxW * values[idx]) / (double)weights[idx];
            break; // No more space left
        }
        i++;
    }

    return ans;
}

int main()
{
    vector<int> values = {5, 7, 15, 12, 2, 16, 8}; // Profit array
    vector<int> weights = {2, 3, 5, 1, 10, 3, 4};  // Weight array

    cout << "Maximum Profit is : " << knapsack(values, weights, 20) << endl;
}
