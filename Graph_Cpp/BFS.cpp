#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

void BFS(vector<vector<int>> &graph, int st)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[st] = true;
    q.push(st);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neigh : graph[node])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

void BFS_Matrix(vector<vector<int>> &matrix, int st)
{
    int n = matrix.size();
    unordered_map<int, set<int>> adjList;   //set stores in sorted order

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                adjList[i].insert(j);
            }
        }
    }

    // Convert unordered_map to vector adjacency list for BFS function
    vector<vector<int>> adjListVec(n);
    for (auto &pair : adjList)
    {
        adjListVec[pair.first] = vector<int>(pair.second.begin(), pair.second.end());
    }

    BFS(adjListVec, st);
}

int main()
{
    int vertices = 6;
    vector<vector<int>> graph(vertices);

    // Example graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int startNode = 0;
    cout << "BFS using adjacency list starting from node " << startNode << ": ";
    BFS(graph, startNode);

    // Adjacency matrix representation
    vector<vector<int>> graph1 = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    cout << "BFS using adjacency matrix starting from node " << startNode << ": ";
    BFS_Matrix(graph1, startNode);

    return 0;
}
