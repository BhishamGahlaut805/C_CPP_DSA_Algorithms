#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Structure to represent a node in the branch and bound tree
struct Node
{
    int level;   // Level in the decision tree (item index)
    int profit;  // Total profit up to this node
    int weight;  // Total weight up to this node
    float bound; // Upper bound of profit for this node
};

// Comparison function for priority queue (max-heap based on bound)
struct CompareNode
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.bound < b.bound; // Higher bound has higher priority
    }
};

// Function to calculate the upper bound profit for a node
float calculateBound(Node u, int W, const vector<int> &v, const vector<int> &w, int n)
{
    if (u.weight >= W)
        return 0;

    float profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    // Greedily add items until weight limit is reached
    while (j < n && totalWeight + w[j] <= W)
    {
        totalWeight += w[j];
        profitBound += v[j];
        j++;
    }

    // If there are remaining items, take a fraction of the next item
    if (j < n)
    {
        profitBound += (W - totalWeight) * ((float)v[j] / w[j]);
    }

    return profitBound;
}

// 0/1 Knapsack using Branch and Bound
int knapsackBranchAndBound(int W, const vector<int> &v, const vector<int> &w, int n)
{
    // Sort items by value/weight ratio in descending order
    vector<pair<float, int>> ratio(n);
    for (int i = 0; i < n; i++)
    {
        ratio[i] = {(float)v[i] / w[i], i};
    }
    sort(ratio.begin(), ratio.end(), greater<pair<float, int>>());

    // Reorder items based on sorted ratios
    vector<int> sorted_v(n), sorted_w(n);
    for (int i = 0; i < n; i++)
    {
        sorted_v[i] = v[ratio[i].second];
        sorted_w[i] = w[ratio[i].second];
    }

    priority_queue<Node, vector<Node>, CompareNode> Q;
    Node u = {-1, 0, 0, 0}; // Root node
    u.bound = calculateBound(u, W, sorted_v, sorted_w, n);
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty())
    {
        u = Q.top();
        Q.pop();

        // If bound is still better than current maxProfit, explore further
        if (u.bound > maxProfit)
        {
            // Include next item
            Node v = u;
            v.level = u.level + 1;
            v.weight += sorted_w[v.level];
            v.profit += sorted_v[v.level];

            // Update maxProfit if feasible and better
            if (v.weight <= W && v.profit > maxProfit)
            {
                maxProfit = v.profit;
            }

            // Calculate bound and add to queue if promising
            v.bound = calculateBound(v, W, sorted_v, sorted_w, n);
            if (v.bound > maxProfit)
            {
                Q.push(v);
            }

            // Exclude next item
            v = u;
            v.level = u.level + 1;
            v.bound = calculateBound(v, W, sorted_v, sorted_w, n);

            if (v.bound > maxProfit)
            {
                Q.push(v);
            }
        }
    }

    return maxProfit;
}

int main()
{
    int W = 50;                     // Knapsack capacity
    vector<int> v = {60, 100, 120}; // Values
    vector<int> w = {10, 20, 30};   // Weights
    int n = v.size();

    int maxProfit = knapsackBranchAndBound(W, v, w, n);
    cout << "Maximum profit achievable: " << maxProfit << endl;

    return 0;
}