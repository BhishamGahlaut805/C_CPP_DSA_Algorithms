#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void printTree(vector<vector<int>> &root, vector<int> &keys, int i, int j)
{
    if (i > j)
        return; // Base case

    // Print the left subtree
    int k = root[i][j];
    printTree(root, keys, i, k - 1);

    // Print the root key
    cout << keys[k] << " ";

    // Print the right subtree
    printTree(root, keys, k + 1, j);
}

int OBST(vector<int> &keys, vector<int> &cost)
{
    int n = keys.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> root(n, vector<int>(n, 0));
    // Fill the diagonal (single key subtrees)
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = cost[i];
    }

    // Fill the dp table for subtrees of length 2 to n
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX; // Initialize to a large value

            // Calculate the sum of costs from i to j
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += cost[k];
            }

            // Try all keys as the root and find the minimum cost
            for (int k = i; k <= j; k++)
            {
                int leftCost = (k > i) ? dp[i][k - 1] : 0;
                int rightCost = (k < j) ? dp[k + 1][j] : 0;
                int totalCost = leftCost + rightCost + sum;
                dp[i][j] = min(dp[i][j], totalCost);
                root[i][j] = k;
            }
        }
    }

    // // The result is the minimum cost for the entire tree (0 to n-1)
    // cout << "Structure of OBST (in-order traversal): ";
    // printTree(root, keys, 0, n - 1);
    // cout << endl;
    return dp[0][n - 1];
}


int main()
{
    vector<int> keys = {10, 30, 20, 40};
    vector<int> cost = {4, 2, 6, 3};
    cout <<"Minimum cost is : "<< OBST(keys, cost) << endl;
}

