#include <bits/stdc++.h>
using namespace std;
//All pair shortest path algorithm using dynamic programming
// The Floyd-Warshall algorithm is a classic algorithm for finding the shortest paths between all pairs of vertices in a weighted graph with positive or negative edge weights (but with no negative cycles). It is particularly useful for dense graphs and can be used to find the transitive closure of a graph.
class Solution
{
public:
    void Floyd_Warshall(int V, vector<vector<int>> &edges, int src)
    {
        // Initialize the distance matrix with INFINITY
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));   //Dp array

        // Set diagonal elements to 0 (distance to itself)
        for (int i = 0; i < V; i++)
            dist[i][i] = 0;

        // Fill the distance matrix with given edge weights
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w; // Assuming directed graph
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Print the shortest distance matrix
        cout << "All-Pairs Shortest Path Matrix:\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sol;
    // Example graph represented as an adjacency list
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 3}, {1, 3, 2}, {2, 3, 4}, {3, 4, 1}, {2, 4, 5}};
    sol.Floyd_Warshall(5, edges, 0);
    return 0;
}
// The output will show the shortest distance between all pairs of vertices in the graph.
// The Floyd-Warshall algorithm has a time complexity of O(V^3), where V is the number of vertices in the graph. It is suitable for dense graphs and can handle negative edge weights, but it is not efficient for sparse graphs compared to other algorithms like Dijkstra's or Bellman-Ford.

