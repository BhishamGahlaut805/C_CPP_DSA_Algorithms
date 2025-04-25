#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort edges by increasing weight
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2]; // Sort edges based on weight in ascending order
}

// Function to initialize Disjoint Set (Union-Find) with parent and rank arrays
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // Each node is its own parent
        rank[i] = 0;   // Rank starts at 0
    }
}

// Function to find the parent (representative) of a set with path compression
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node; // If node is its own parent, return node
    }
    return parent[node] = findParent(parent, parent[node]); // Path compression
}

// Function to perform union of two sets based on rank
void unionSet(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) // Only merge if they are in different sets
    {
        if (rank[u] < rank[v])
        {
            parent[u] = v; // Attach smaller rank tree under larger rank tree
        }
        else if (rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++; // Increase rank if both have same rank
        }
    }
}

// Function to compute Minimum Spanning Tree (MST) using Kruskal’s Algorithm
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp); // Sort edges based on weight

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n); // Initialize Disjoint Set

    int minWt = 0; // Store the total weight of MST

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];  // Node 1
        int v = edges[i][1];  // Node 2
        int wt = edges[i][2]; // Weight of the edge

        if (findParent(parent, u) != findParent(parent, v)) // Check for cycle
        {
            minWt += wt;                  // Add edge to MST
            unionSet(u, v, rank, parent); // Merge the sets
        }
    }

    return minWt; // Return total weight of the MST
}

// Main function to test Kruskal's Algorithm
int main()
{
    int V = 5; // Number of vertices

    // Graph represented as an edge list: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 3}, {0, 2, 2}, {1, 2, 1}, {1, 3, 3}, {3, 4, 4}, {2, 4, 5}};

    // Compute and print Minimum Spanning Tree (MST) weight
    cout << "Minimum Spanning Tree Weight: " << minimumSpanningTree(edges, V) << endl;

    return 0;
}

//T.C. O(E*log(V))->using union /rank And path Compression



