#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// Function to Find Minimum Spanning Tree using Prim's algorithm
vector<pair<pair<int, int>, int>> PrimsMst(int n, int m, vector<pair<pair<int, int>, int>> &edges, int &minWt)
{
    // Create Adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    // accessing u,v,weight values
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    //Initialzing the Priority Queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // initializing key, mst, parent
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }
    // Main algorithm for Prim's Algo
    key[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().second;    //1.Get the Minimum Weight
        pq.pop();
        if(mst[u]==true){   //Already Present in MST
            continue;
        }
        mst[u] = true;          //2.Mark the Minimum Weight as True
        for(auto it:adj[u]){    //3.Check for adjacents
            int v = it.first;
            int w = it.second;
            if(!mst[v] and w<key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
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

// Main function to test Prim's Algorithm
int main()
{
    int n = 4; // Number of vertices
    int m = 4; // Number of edges

    // List of edges { {u, v}, weight }
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 1}, {{2, 3}, 2}, {{3, 4}, 4}, {{4, 1}, 5}};

    // Run Prim's Algorithm and print the results
    printMST(n, m, edges);

    return 0;
}