#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
// Kahn’s Algorithm for Topological Sorting is a method used to order the vertices of a directed graph in a linear order such that for every directed edge from vertex A to vertex B, A comes before B in the order. The algorithm works by repeatedly finding vertices with no incoming edges, removing them from the graph, and updating the incoming edges of the remaining vertices. This process continues until all vertices have been ordered.
using namespace std;

// Function for topological sort
vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int v)
{
    vector<int> indegree(v, 0);

    //step1. Calculate indegree of each vertex
    for (auto &pair : adj)
    {
        for (auto neighbor : pair.second)
        {
            indegree[neighbor]++;
        }
    }

    //step2. Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        //step3. Decrease indegree of adjacent vertices
        for (auto neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // If all vertices are not included, a cycle exists
    if (result.size() != v)
    {
        cout << "Graph contains a cycle" << endl;
        return {};
    }
    return result;
}

int main()
{
    int n = 6; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}, {5, 1}, {5, 2}};

    unordered_map<int, vector<int>> adj;
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    cout << "Topological sorting of the graph: ";
    vector<int> result = topologicalSort(adj, n);

    // Displaying result
    if (!result.empty())
    {
        for (auto i : result)
        {
            cout << i << " ";
        }
    }
    return 0;
}
//T.C.======>O(v*E);
//S.C.======>O(v*E);
