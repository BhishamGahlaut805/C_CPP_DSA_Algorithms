#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to implement BFS using Graph coloring
void BFS(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> color(n, 0);
    vector<int> parent(n, -1);
    vector<int> dist(n, 0);
    vector<bool> visited(n, 0);
    color[start] = 1;
    visited[start] = true;
    dist[start] = 0;

    queue<int> q;
    q.push(start);
    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
                color[i] = 1;
                parent[i] = node;
                dist[i] = dist[node] + 1;
            }
        }
        color[node] = 2;
    }
}
int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 0, 0},
                                 {1, 1, 0, 1, 1},
                                 {1, 0, 1, 1, 0},
                                 {0, 1, 1, 0, 1},
                                 {0, 0, 0, 1, 0}};
    BFS(graph, 0);
}

