#include<iostream>
#include<vector>
using namespace std;
// A graph G = (V, E), where V is the set of vertices and E is the set of edges, write a program to assign colors to each vertex in V such that no two adjacent vertices have the same color and in this process of assigning the color total number of used colors should be minimum.
//  Function to find the minimum number of colors required to color the graph using BackTracking


vector<vector<int>> allSolutions;

// Function to check if it's safe to color vertex v with color c
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &color, int c)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function to find all valid colorings
void graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    if (v == graph.size())
    {
        allSolutions.push_back(color);
        return;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            graphColoringUtil(graph, m, color, v + 1);
            color[v] = 0; // Backtrack
        }
    }
}

// Function to solve the graph coloring problem using backtracking
void solve(vector<vector<int>> &graph)
{
    int n = graph.size();
    int m = 1; // Start with 1 color and increase
    vector<int> color(n, 0);

    while (true)
    {
        allSolutions.clear();
        fill(color.begin(), color.end(), 0);
        graphColoringUtil(graph, m, color, 0);

        if (!allSolutions.empty())
        {
            cout << "Minimum number of colors required: " << m << endl;
            cout << "All possible colorings with " << m << " colors:\n";
            for (int i = 0; i < allSolutions.size(); i++)
            {
                cout << "Solution " << i + 1 << ": ";
                for (int c : allSolutions[i])
                {
                    cout << c << " ";
                }
                cout << endl;
            }
            break;
        }
        m++;
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
       };

    solve(graph);
}
