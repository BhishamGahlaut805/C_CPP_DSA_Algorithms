#include <bits/stdc++.h>
using namespace std;

// Function to check if the current position is safe for placing a queen

bool isSafe(int row, int col, vector<int> &solution)
{
    for (int i = 1; i < row; i++)
    {
        if (col == solution[i] || abs(row - i) == abs(col - solution[i]))
        {
            return false;
        }
    }
    return true;
}

bool solve(int row, int n, vector<int> &solution)
{
    if (row > n) // Base case: all queens are placed
    {
        return true;
    }

    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col, solution))
        {
            solution[row] = col;

            if (solve(row + 1, n, solution)) // Recursive call
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 8;
    vector<int> solution(n + 1, 0); // Fix vector size (1-based indexing)

    if (solve(1, n, solution)) // Start from row 1
    {
        for (int i = 1; i <= n; i++)
        {
            cout << solution[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No solution exists" << endl;
    }
}
