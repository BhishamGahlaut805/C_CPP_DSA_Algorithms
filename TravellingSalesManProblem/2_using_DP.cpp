#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

// Memoization map to store already computed results
map<pair<int, set<int>>, int> dp;

/**
 * @brief Recursive function to solve TSP using DP.
 * @param i Current city.
 * @param S Set of remaining cities to visit.
 * @param cost Adjacency matrix of travel costs.
 * @return Minimum cost to complete the tour starting from city i and visiting all cities in S.
 */
int tsp(int i, set<int> S, vector<vector<int>> &cost)
{
    // Base case: If no cities are left to visit, return cost to return to starting city 0
    if (S.empty())
    {
        return cost[i][0];
    }

    // If the result for this state is already computed, return it
    if (dp.count({i, S}))
    {
        return dp[{i, S}];
    }

    int ans = INT_MAX;

    // Try going to every next city k in the set S
    for (int k : S)
    {
        set<int> remaining = S;
        remaining.erase(k); // Remove k from the remaining cities
        int temp = cost[i][k] + tsp(k, remaining, cost);
        ans = min(ans, temp);
    }

    // Memoize and return the result
    dp[{i, S}] = ans;
    return ans;
}

int main()
{
    // Example cost matrix (4 cities)
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int n = cost.size();

    // Initially, we start from city 0, and all other cities are left to visit
    set<int> S;
    for (int i = 1; i < n; ++i)
    {
        S.insert(i);
    }

    int min_cost = tsp(0, S, cost);

    cout << "Minimum cost to complete TSP: " << min_cost << endl;

    return 0;
}

//The Pseudo code for the above C++ code is as follows:
// 1. Initialize a memoization map `dp` to store computed results.
// 2. Define a recursive function `tsp(i, S, cost)` where `i` is the current city and `S` is the set of remaining cities to visit.
// 3. If `S` is empty, return the cost to return to the starting city (0).
// 4. If the result for the current state `(i, S)` is already computed, return it from `dp`.
// 5. Initialize `ans` to a large value (infinity).
// 6. For each city `k` in the set `S`:
//    a. Create a new set `remaining` by removing `k` from `S`.
//    b. Calculate the cost to go from city `i` to city `k` and add the result of `tsp(k, remaining, cost)`.
//    c. Update `ans` with the minimum of `ans` and the computed cost.
// 7. Store the computed result in `dp` for the state `(i, S)`.
// 8. Return `ans` as the minimum cost to complete the tour starting from city `i` and visiting all cities in `S`.
// 9. In the `main` function, define the cost matrix for the cities.
// 10. Initialize the set `S` with all cities except the starting city (0).
// 11. Call the `tsp` function with the starting city (0) and the set `S` to get the minimum cost.
// 12. Print the minimum cost to complete the TSP tour.
// 13. End of the program.
// 14. The expected output for the example cost matrix is the minimum cost to visit all cities exactly once and return to the starting city.

//The Time complexity of the above code is O(n^2 * 2^n) and the Space complexity is O(n * 2^n) where n is the number of cities. The reason for this is that we are using a set to represent the remaining cities, which can have up to 2^n subsets. For each subset, we are storing the result in the memoization map `dp`, leading to the exponential growth in space complexity.
