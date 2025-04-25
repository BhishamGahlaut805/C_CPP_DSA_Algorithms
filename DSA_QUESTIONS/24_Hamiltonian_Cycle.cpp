#include<bits/stdc++.h>
using namespace std;

// Function to check if a vertex can be added to the Hamiltonian cycle
bool isValid(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Function to solve the Hamiltonian cycle problem using backtracking
bool cyclefound(vector<vector<int>> &graph, vector<int> &path, int pos) {
    // Base case: If all vertices are included in the path
    if (pos == graph.size()) {
        // And if there is a path from the last included vertex to the first vertex
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    // Try different vertices as the next candidate in the Hamiltonian cycle
    for (int v = 1; v < graph.size(); v++) {
        if (isValid(v, graph, path, pos)) {
            path[pos] = v; // Add v to the path

            // Recur to construct the rest of the path
            if (cyclefound(graph, path, pos + 1)) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}
// Function to solve the Hamiltonian cycle problem
bool hamiltonian(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> path(V, -1); // Initialize the path as -1

    // Let the first vertex in the path be 0
    path[0] = 0;

    // Start from the first vertex and try to find a Hamiltonian cycle
    if (!cyclefound(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists" << endl;
        return false;
    }

    // Print the Hamiltonian cycle
    cout << "Hamiltonian Cycle exists: ";
    for (int i = 0; i < V; i++) {
        cout << path[i] << " ";
    }
    cout << path[0] << endl; // To complete the cycle

    return true;
}
int main(){
        vector<vector<int>> graph = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0}};

        hamiltonian(graph);
}

//Time Complexity:O(n!)
//Space Complexity:O(n)
// where n is the number of vertices in the graph.
// The time complexity is factorial because we are trying all possible permutations of vertices to find a Hamiltonian cycle. The space complexity is linear due to the path array used to store the current path.

