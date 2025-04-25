#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void BellmanFord(int V, vector<vector<int>> &edges, int S)
    {
        int E = edges.size();
        vector<int> dist(V, INT_MAX); // Fix 1: Using 0-based indexing
        dist[S] = 0;

        // Step 1: Relax all edges V-1 times
        for (int i = 1; i < V; i++)
        { // Fix 2: Should be V-1 iterations
            for (int j = 0; j < E; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];

                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Check for negative-weight cycles
        bool negativeCycle = false;
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                negativeCycle = true;
                break;
            }
        }

        // Step 3: Print the result
        if (negativeCycle)
        {
            cout << "Negative Cycle Present. Shortest Path not possible\n";
        }
        else
        {
            cout << "Shortest Distances from source " << S << ":\n";
            for (int i = 0; i < V; i++)
            {
                if (dist[i] == INT_MAX)
                    cout << "INF ";
                else
                    cout << dist[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> edges2 = {
        {0, 1, 6}, {0, 2, 5}, {0, 3, 5}, {1, 4, -1}, {2, 1, -2}, {2, 4, 1}, {3, 2, 2}, {4, 3, 3}};
    sol.BellmanFord(5, edges2, 0);

    cout << "\nTest Case 3: Graph With a Negative Cycle\n";
    vector<vector<int>> edges3 = {
        {0, 1, 3}, {1, 2, 4}, {2, 3, -6}, {3, 1, 1}};
    sol.BellmanFord(4, edges3, 0);

    cout << "\nTest Case 4: Disconnected Graph\n";
    vector<vector<int>> edges4 = {
        {0, 1, 2}, {1, 2, 3}};
    sol.BellmanFord(5, edges4, 0);

    cout << "\nTest Case 5: Single Node Graph\n";
    vector<vector<int>> edges5 = {};
    sol.BellmanFord(1, edges5, 0);

    return 0;
}

//T.C.=> O(E*V);
