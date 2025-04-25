#include <stdio.h>
#include <stdbool.h>

// Function for Depth-First Traversal (Recursive)
void DFT(int graph[][7], int node, int visited[], int numberOfNodes)
{
    // Mark the current node as visited
    visited[node] = 1;
    printf("%d ", node);

    // Recursively visit all unvisited neighbors
    for (int j = 0; j < numberOfNodes; j++)
    {
        if (graph[node][j] == 1 && visited[j] == 0)
        {
            DFT(graph, j, visited, numberOfNodes);
        }
    }
}

int main()
{
    // Graph adjacency matrix
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    int numberOfNodes = 7;
    int visited[7] = {0}; // Initialize all nodes as unvisited

    int startNode = 0; // Starting node for DFT
    printf("Depth-First Traversal starting from node %d:\n", startNode);

    // Perform Depth-First Traversal
    DFT(graph, startNode, visited, numberOfNodes);

    return 0;
}
