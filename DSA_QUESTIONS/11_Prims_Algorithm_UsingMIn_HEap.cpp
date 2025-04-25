#include <bits/stdc++.h>
using namespace std;

// Function to find Minimum Spanning Tree using Prim's Algorithm with Min-Heap
vector<pair<pair<int, int>, int>> PrimsMst(int n, int m, vector<pair<pair<int, int>, int>> &edges, int &minWt)
{
    // Create Adjacency List
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto edge : edges)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Min-Heap: Stores (weight, node, parent)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize key, MST inclusion, and parent arrays
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from node 1
    key[1] = 0;
    pq.push({0, {1, -1}}); // {weight, {node, parent}}

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int u = top.second.first;
        int v = top.second.second;
        int weight = top.first;

        // If node is already in MST, skip
        if (mst[u])
            continue;

        // Include the node in MST
        mst[u] = true;

        // Check all adjacent nodes
        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;
            if (!mst[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({w, {v, u}});
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
        minWt += key[i];
    }
    return result;
}

// Function to print the entire output including the minimum weight
void printMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    int minWt = 0;
    vector<pair<pair<int, int>, int>> mst = PrimsMst(n, m, edges, minWt);

    // Output the results
    cout << "Minimum Spanning Tree Weight: " << minWt << endl;
    cout << "Edges in MST: " << endl;

    for (auto i : mst)
    {
        cout << i.first.first << " -- " << i.first.second << " (Weight: " << i.second << ")\n";
    }
}

int main()
{
    int n = 4; // Number of vertices
    int m = 4; // Number of edges

    // List of edges { {u, v}, weight }
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 1}, {{2, 3}, 2}, {{3, 4}, 4}, {{4, 1}, 5}};

    printMST(n, m, edges);

    return 0;
}
//T.C.: O(E*log(V)) ->USing binary minheap