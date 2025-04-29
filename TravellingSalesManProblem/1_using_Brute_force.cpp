#include<iostream>
#include<algorithm> // For min()
#include<vector>
#include<climits> // For INT_MAX
using namespace std;

/*
 * Problem: Travelling Salesman Problem (TSP)
 * Given a set of cities and the distances between each pair of cities,
 * the problem is to find the shortest possible route that visits each city exactly once
 * and returns to the origin city.
 */

/*
 * Approach: Brute Force (Recursive Backtracking)
 * Explores all possible permutations of visiting the cities starting from a fixed city (city 0).
 * Calculates the cost of each permutation and keeps track of the minimum cost found.
 *
 * Time Complexity: O(N!) - In the worst case, we explore all (N-1)! permutations of cities
 * starting from city 0. For each permutation, we calculate the cost, which takes O(N) time.
 * However, the dominant factor is the factorial complexity of generating permutations.
 * A more precise analysis might be O(N!), as the cost calculation is part of the recursive step.
 *
 * Space Complexity: O(N) - Primarily due to the recursion depth (which can go up to N)
 * and the `visited` array of size N.
 *
 * Note: This brute-force approach is computationally expensive and becomes infeasible
 * for even a moderate number of cities (e.g., N > 15).
 */

/**
 * @brief Recursive helper function to explore TSP paths.
 *
 * @param cost The adjacency matrix representing the cost between cities. cost[i][j] is the cost from city i to city j.
 * @param visited A boolean vector to keep track of visited cities in the current path.
 * @param pos The current city the salesman is at.
 * @param n The total number of cities.
 * @param count The number of cities visited so far in the current path.
 * @param costSoFar The accumulated cost of the path traveled so far.
 * @param ans The minimum cost found so far across all explored paths (passed by value, updated recursively).
 * @return The minimum cost found starting from the current state.
 */
int tspUtil(vector<vector<int>> &cost, vector<bool> &visited, int pos, int n, int count, int costSoFar, int ans) {
    // Base Case: If all cities have been visited
    if (count == n) {
        // Check if there's a path back to the starting city (city 0)
        if (cost[pos][0] != 0) { // Assuming 0 cost means no direct path, adjust if needed
            // Update the overall minimum cost if the current path + return cost is smaller
            return min(ans, costSoFar + cost[pos][0]);
        } else {
            // Cannot return to the start city from the last city in this path
            return ans; // Return the current minimum without updating
        }
    }

    // Recursive Step: Explore paths to unvisited neighboring cities
    for (int i = 0; i < n; i++) {
        // Check if city 'i' is not visited and there is a path from the current city 'pos' to 'i'
        if (!visited[i] && cost[pos][i] != 0) { // Assuming 0 cost means no direct path
            // Mark city 'i' as visited (Choose)
            visited[i] = true;

            // Recursively explore paths starting from city 'i'
            ans = tspUtil(cost, visited, i, n, count + 1, costSoFar + cost[pos][i], ans);

            // Backtrack: Unmark city 'i' as visited to explore other possibilities
            visited[i] = false; // (Unchoose)
        }
    }
    // Return the minimum cost found from this state 'pos'
    return ans;
}

/**
 * @brief Initializes the TSP calculation.
 *
 * @param cost The adjacency matrix representing the cost between cities.
 * @return The minimum cost for the TSP tour.
 */
int tsp(vector<vector<int>> &cost) {
    int n = cost.size(); // Get the number of cities
    if (n <= 1) return 0; // Handle edge case: 0 or 1 city

    vector<bool> visited(n, false); // Initialize visited array, all cities are initially unvisited

    // Start the tour from the first city (city 0)
    visited[0] = true;

    // Call the recursive utility function to find the minimum cost
    // Start at city 0, count = 1 (city 0 visited), costSoFar = 0, initial min_ans = INT_MAX
    return tspUtil(cost, visited, 0, n, 1, 0, INT_MAX);
}

int main(){
    // Example Input: Adjacency matrix representing costs between 4 cities.
    // cost[i][j] = cost to travel from city i to city j.
    vector<vector<int>> cost = {{0, 10, 15, 20},
                                {10, 0, 35, 25},
                                {15, 35, 0, 30},
                                {20, 25, 30, 0}};

    // Calculate the minimum TSP cost
    int res = tsp(cost);

    // Output the result
    if (res == INT_MAX) {
        cout << "No possible TSP tour found (or only one city)." << endl;
    } else {
        cout << "Minimum cost using Brute Force: " << res << endl;
        // Expected output for this example: 80 (Path: 0 -> 1 -> 3 -> 2 -> 0)
    }

    return 0; // Indicate successful execution
}

// The output will be the minimum cost to visit all cities exactly once
// and return to the starting city (city 0).
