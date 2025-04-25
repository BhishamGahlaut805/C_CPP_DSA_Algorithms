#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &ans, int row, int col, int n)
{
    // 1. Check column (No queen should be in the same column)
    for (int i = 0; i < row; i++)
    {
        if (ans[i][col] == 1)
            return false;
    }

    // 2. Check left diagonal (↖)
    int i = row, j = col;
    while (i >= 0 && j >= 0)
    {
        if (ans[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // 3. Check right diagonal (↗)
    i = row;
    j = col;
    while (i >= 0 && j < n) 
    {
        if (ans[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true;
}

bool solve(int n, int x, vector<vector<int>> &ans)
{
    // Base Case: All queens are placed
    if (x >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(ans, x, i, n))
        {
            ans[x][i] = 1;
            if (solve(n, x + 1, ans))
                return true;
            ans[x][i] = 0; // Backtracking
        }
        for (auto row : ans)
        {
            for (auto ele : row)
            {
                cout << ele << " ";
            }
            cout <<"\n";
        }
        cout<<endl;
        }
    return false;
}

vector<vector<int>> NQueen(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));

    // If no solution exists, return an empty board
    if (!solve(n, 0, ans))
        return {};

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = NQueen(n);

    if (ans.empty())
    {
        cout << "No solution exists!" << endl;
    }
    else
    {
        for (auto row : ans)
        {
            for (auto ele : row)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
