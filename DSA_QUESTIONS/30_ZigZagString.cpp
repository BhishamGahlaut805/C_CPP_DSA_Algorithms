#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length()) {
            return s; // No zigzag conversion needed
        }

        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c; // Place character in the current row
            if (curRow == 0) {
                goingDown = true; // Start going down
            } else if (curRow == numRows - 1) {
                goingDown = false; // Start going up
            }
            curRow += goingDown ? 1 : -1; // Move to the next row
        }

        string result;
        for (const string& row : rows) {
            result += row; // Concatenate all rows
        }
        return result;
    }
};
int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = sol.convert(s, numRows);
    cout << "Zigzag conversion: " << result << endl;
    // Output: Zigzag conversion: PAHNAPLSIIGYIR
    return 0;
}

//The logic is dry run as follows:
// 1. Initialize a vector of strings to hold each row.
// 2. Iterate through each character in the input string.
// 3. Place each character in the appropriate row based on the current direction (down or up).
// 4. Change direction when reaching the top or bottom row.
// 5. Concatenate all rows to form the final zigzag string.
// The time complexity is O(n) where n is the length of the input string, and the space complexity is O(n) for storing the rows.
// The code is designed to convert a string into a zigzag pattern based on the specified number of rows.
