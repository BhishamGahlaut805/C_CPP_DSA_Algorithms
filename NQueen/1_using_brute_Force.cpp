#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing queen at board[row][col] is safe
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to brute-force all possible queen placements
bool solveNQueens(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    { // Base case: All queens placed successfully
        // Print solution
        cout << "Solution:\n";
        for (auto &r : board)
        {
            for (int cell : r)
                cout << (cell ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return true; // To find only one solution, return true
    }

    bool foundSolution = false; // To find all solutions
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {                                                     // Check if placement is valid
            board[row][col] = 1;                              // Place queen
            foundSolution |= solveNQueens(board, row + 1, N); // Recursive call
            board[row][col] = 0;                              // Backtrack
        }
    }

    return foundSolution;
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueens(board, 0, N)) // Start solving from row 0
        cout << "No solution exists for N = " << N << endl;

    return 0;
}
// The time complexity of this brute-force approach is O(N!), as we are
// trying to place N queens in N rows and each row has N columns. The space complexity is O(N^2) for the board.
// This implementation finds all possible solutions for the N-Queens problem and prints them.   