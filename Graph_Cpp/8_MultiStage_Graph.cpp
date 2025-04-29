#include <iostream>
#include <vector>
#include <algorithm> // For min()
#include <climits>   // For INT_MAX
using namespace std;

// Function to find the minimum cost path in a multi-stage graph
int minCostPath(vector<vector<int>> &cost, int n)
{
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0; // Destination node, no cost to reach itself

    // Iterate backwards from second last node to the start
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (cost[i][j] != 0)
            { // If there is a direct edge from i to j
                dp[i] = min(dp[i], cost[i][j] + dp[j]);
            }
        }
    }

    return dp[0]; // Minimum cost from node 0 to node n-1
}

int main()
{
    // Example cost matrix for a multi-stage graph
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {0, 0, 35, 25},
        {0, 0, 0, 30},
        {0, 0, 0, 0}};

    int n = cost.size();

    int result = minCostPath(cost, n);

    cout << "Minimum cost to reach the last stage: " << result << endl;

    return 0;
}
