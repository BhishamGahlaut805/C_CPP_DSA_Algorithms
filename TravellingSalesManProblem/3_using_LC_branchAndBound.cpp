#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to calculate the lower bound (cost) of the current node
int calculateBound(const vector<vector<int>> &dist, vector<int> &path, int n, int currentCost)
{
    int bound = currentCost;

    // Add the cost of the minimal path from the current city
    for (int i = 0; i < n; ++i)
    {
        if (path[i] == -1)
        { // If city i is not visited yet
            int minEdge = INT_MAX;
            for (int j = 0; j < n; ++j)
            {
                if (path[j] == -1 && dist[i][j] < minEdge)
                {
                    minEdge = dist[i][j];
                }
            }
            bound += minEdge;
        }
    }
    return bound;
}

// Function to solve TSP using Branch and Bound
int TSPBranchAndBound(const vector<vector<int>> &dist, int n)
{
    vector<int> path(n, -1); // Path to store the visited cities
    int bestCost = INT_MAX;  // Best cost found so far

    // Priority queue: to store nodes, sorted by their bound (ascending order)
    // Node contains: level, cost, bound, path
    // We are using a simple array for simplicity; it can be implemented using a priority queue.
    vector<vector<int>> queue;

    // Start at city 0
    path[0] = 0;
    int currentCost = 0;

    // Calculate the initial bound for the root node
    int bound = calculateBound(dist, path, n, currentCost);
    queue.push_back({0, currentCost, bound});

    while (!queue.empty())
    {
        // Extract the node with the minimum bound
        auto node = queue.back();
        queue.pop_back();

        int level = node[0];
        currentCost = node[1];
        bound = node[2];

        // If bound is greater than the best cost, prune this node
        if (bound >= bestCost)
            continue;

        // If level equals n-1, we have completed a tour
        if (level == n - 1)
        {
            bestCost = min(bestCost, currentCost + dist[path[level]][0]); // Add the return to the start city
            continue;
        }

        // Branch: explore the unvisited cities
        for (int i = 0; i < n; ++i)
        {
            if (path[i] == -1)
            { // If city i has not been visited yet
                // Create a new node
                path[level + 1] = i;
                int newCost = currentCost + dist[path[level]][i];

                // Calculate the new bound
                int newBound = calculateBound(dist, path, n, newCost);

                // If the new bound is smaller than the best cost, add to the queue
                if (newBound < bestCost)
                {
                    queue.push_back({level + 1, newCost, newBound});
                }

                // Backtrack
                path[level + 1] = -1;
            }
        }
    }

    return bestCost;
}

int main()
{
    // Example distance matrix for 4 cities
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = dist.size();
    int minCost = TSPBranchAndBound(dist, n);
    cout << "The minimum cost of the TSP tour is: " << minCost << endl;

    return 0;
}
