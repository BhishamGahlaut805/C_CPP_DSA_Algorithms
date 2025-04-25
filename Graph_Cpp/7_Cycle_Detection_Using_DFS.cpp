#include <iostream>
#include <vector>
using namespace std;

bool dfsCycle(int node, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout<<node<<" ";
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            if (dfsCycle(neighbor, node, graph, visited)){
                return true;
            }
        }
        else if (neighbor != parent)
        {   cout<<node<<" ";
            return true; // Found a cycle
        }
    }
    return false;
}

bool hasCycle(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (dfsCycle(i, -1, graph, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 3},
        {1, 2, 4},
        {1, 3}
    };

    if (hasCycle(graph))
        cout << "\nCycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;

    return 0;
}
