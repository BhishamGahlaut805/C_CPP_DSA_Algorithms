#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to implement BFS using Graph coloring and return shortest distances
vector<int> BFS(vector<vector<int>> &graphAdj, int start)
{
    int n = graphAdj.size();
    vector<int> dist(n, -1);        // Distance from start to each node
    vector<bool> visited(n, false); // Visited array

    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto &ele:graphAdj[node]){
            if (!visited[ele])
            {
                visited[ele] = true;
                dist[ele] = dist[node] + 1;
                q.push(ele);
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> adjGraph(5);
    adjGraph[0] = {1, 2};
    adjGraph[1] = {0, 3, 4};
    adjGraph[2] = {0, 3};
    adjGraph[3] = {1, 2, 4};
    adjGraph[4] = {1, 3};

    int source = 0;
    vector<int> distances = BFS(adjGraph, source);

    cout << "Shortest distances from node " << source <<endl;
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] != -1)
            cout << distances[i]<< " ";
        else
            cout << "unreachable" << endl;
    }

    return 0;
}
