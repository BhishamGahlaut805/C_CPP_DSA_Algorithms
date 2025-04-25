#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

void DFS(vector<vector<int>> &graph, int st, vector<bool> &visited)
{
    if (visited[st])
        return;

    // Mark the node as visited and print it
    visited[st] = true;
    cout << st << " ";

    // Recur for all adjacent nodes
    for (int neighbor : graph[st])
    {
        if (!visited[neighbor])
        {
            DFS(graph, neighbor, visited);
        }
    }
}

void DFS_Matrix(vector<vector<int>> &matrix, int st)
{
    int n = matrix.size();
    unordered_map<int, set<int>> adjList; // set stores in sorted order

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

    // Convert unordered_map to vector adjacency list for DFS function
    vector<vector<int>> adjListVec(n);
    for (auto &pair : adjList)
    {
        adjListVec[pair.first] = vector<int>(pair.second.begin(), pair.second.end());
    }

    vector<bool> visited1(n, false);
    cout << "DFS using adjacency matrix starting from node " << st << ": ";
    DFS(adjListVec, st, visited1);
    cout << endl;
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

    vector<bool> visited(vertices, false);
    int startNode = 0;

    cout << "DFS using adjacency list starting from node " << startNode << ": ";
    DFS(graph, startNode, visited);
    cout << endl;

    // Adjacency matrix representation
    vector<vector<int>> graph1 = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    DFS_Matrix(graph1, startNode);

    return 0;
}
