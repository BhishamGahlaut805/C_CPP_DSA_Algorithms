#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int en = m - 1;
        while (st < n && en > -1)
        {
            int current = matrix[st][en];
            if (current == target)
            {
                return true;
            }
            else if (current > target)
            {
                en--;
            }
            else
            {
                st++;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {60, 61, 62, 63}
    };
    int target = 3;
    bool result = sol.searchMatrix(matrix, target);
    cout << "Target found: " << (result ? "Yes" : "No") << endl;
    // Output: Target found: Yes
    return 0;
}
//The Time Complexity of this code is O(n + m) where n is the number of rows and m is the number of columns in the matrix. The Space Complexity is O(1) since we are using only a constant amount of extra space for variables.