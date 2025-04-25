#include <bits/stdc++.h>
using namespace std;

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

void solve(int row, int n, vector<int> &solution, vector<vector<int>> &allSolutions)
{
    if (row > n)
    {
        allSolutions.push_back(solution);
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        if (isSafe(row, col, solution))
        {
            solution[row] = col;
            solve(row + 1, n, solution, allSolutions);

        }
    }
}

int main()
{
    int n = 4;
    vector<int> solution(n + 1, 0); // 1-based indexing
    vector<vector<int>> allSolutions;

    solve(1, n, solution, allSolutions);

    cout << "Total Solutions: " << allSolutions.size() << "\n";
    for (const auto &sol : allSolutions)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
