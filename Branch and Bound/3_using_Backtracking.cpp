#include <iostream>
#include <vector>
using namespace std;

// Function to solve knapsack using backtracking
void knapsackBacktrack(vector<int> &weights, vector<int> &values, int capacity, int index, int currentWeight, int currentValue, int &maxValue)
{
    if (index == weights.size())
    { // Base case: all items are considered
        maxValue = max(maxValue, currentValue);
        return;
    }

    // Exclude current item and move to the next
    knapsackBacktrack(weights, values, capacity, index + 1, currentWeight, currentValue, maxValue);

    // Include current item if it doesn't exceed capacity
    if (currentWeight + weights[index] <= capacity)
    {
        knapsackBacktrack(weights, values, capacity, index + 1, currentWeight + weights[index], currentValue + values[index], maxValue);
    }
}

int main()
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int maxValue = 0;
    knapsackBacktrack(weights, values, capacity, 0, 0, 0, maxValue);

    cout << "Maximum Value in Knapsack: " << maxValue << endl;
    return 0;
}
