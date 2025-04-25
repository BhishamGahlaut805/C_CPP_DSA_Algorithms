#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort jobs by profit in descending order
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second; // Sort by profit in descending order
}

int jobSequencing(vector<pair<int, int>> &jobs)
{
    // Step 1: Sort jobs based on descending order of profit
    sort(jobs.begin(), jobs.end(), cmp);

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for (auto job : jobs)
    {
        maxDeadline = max(maxDeadline, job.first); // Finding the max deadline
    }

    // Step 3: Create a schedule array to track used slots
    vector<bool> slot(maxDeadline + 1, false);
    int totalProfit = 0;

    // Step 4: Assign jobs to the latest available slot before their deadline
    for (auto job : jobs)
    {
        int deadline = job.first; // Job deadline
        int profit = job.second;  // Job profit

        // Find an available slot (starting from the deadline down to 1)
        for (int j = deadline; j > 0; j--)
        {
            if (!slot[j])
            { // If the slot is free, assign the job
                slot[j] = true;
                totalProfit += profit;
                break;
            }
        }
    }

    return totalProfit; // Return maximum profit achieved
}

int main()
{
    vector<pair<int, int>> jobs = {{4, 70}, {3, 25}, {1, 15}, {2, 80}, {6, 5}, {3, 29}, {2, 20}};

    cout << "Maximum Profit: " << jobSequencing(jobs) << endl;
}
