#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute the optimized knapsack solution
int knapsackOptimized(vector<int> &weights, vector<int> &values, int n, int W)
{
    int scaledW = W / 10; // Scale down W to reduce state space
    vector<int> dp(scaledW + 1, 0);

    // Iterate through items
    for (int i = 0; i < n; i++)
    {
        int scaledWeight = weights[i] / 10; // Scale each item's weight
        for (int w = scaledW; w >= scaledWeight; w--)
        {
            dp[w] = max(dp[w], dp[w - scaledWeight] + values[i]);
        }
    }

    return dp[scaledW]; // Return max value within scaled weight range
}

int main()
{
    vector<int> weights = {30, 40, 60, 80};    // Original weights
    vector<int> values = {100, 200, 300, 400}; // Corresponding values
    int W = 160;                               // Maximum weight capacity
    int n = weights.size();

    cout << "Maximized Knapsack Value: " << knapsackOptimized(weights, values, n, W) << endl;
    return 0;
}
//