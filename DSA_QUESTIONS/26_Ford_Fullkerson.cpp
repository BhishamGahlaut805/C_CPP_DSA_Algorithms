#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;


// A BFS based function to check if there is a path from source to sink in residual graph.
// Also fills parent[] to store the path.
bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent)
{
    int V = rGraph.size();
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>> &graph, int s, int t)
{
    int u, v;
    int V = graph.size();
    // Create a residual graph and fill it with initial capacities
    vector<vector<int>> rGraph(V, vector<int>(V, -1));
    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(V, -1); // Store the augmenting path

    int max_flow = 0; // Initial flow is 0

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity along the path filled by BFS
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;

            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    // Example graph: capacity matrix
    vector<vector<int>> graph = {
        {0, 4, 18, 5, 0, 0, 0, 0},   // Node 1
        {0, 0, 0, 0, 2, 4, 0, 0}, // Node 2
        {0, 0, 0, 0, 10, 3, 2, 0},  // Node 3
        {0, 0, 8, 0, 0,0, 3, 0},  // Node 4
        {0, 0, 0, 0, 0, 0, 0, 9},   // Node 5
        {0, 0, 0, 0, 0, 0, 0, 7},   // Node 6
        {0, 0, 0, 7, 0, 4, 0, 10},   // Node 7
        {0, 0, 0, 0, 0, 0, 0, 0}    // Node 8
    };

    int source = 0;
    int sink = 7;

    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink) << endl;
    // Output: The maximum possible flow is 23
    return 0;
}

//Time Complexity: O(V^2 * E) where V is the number of vertices and E is the number of edges in the graph. This is because in the worst case, we may have to do O(E) iterations of BFS for each edge in the graph.
//Space Complexity: O(V^2) for the residual graph and O(V) for the parent array and visited array.
// The space complexity is dominated by the size of the residual graph, which is O(V^2) in the worst case.
// The parent array and visited array are both O(V), but they are negligible compared to the residual graph size.
// The overall space complexity is O(V^2).
