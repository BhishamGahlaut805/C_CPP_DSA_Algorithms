#include<iostream>
#include<vector>
#include<algorithm> // For min()
#include<climits> // For INT_MAX
using namespace std;

int LCS_Recursive(string s1, string s2, int i, int j){
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1 + LCS_Recursive(s1, s2, i+1, j+1);
    }else{
        return max(LCS_Recursive(s1, s2, i+1, j), LCS_Recursive(s1, s2, i, j+1));
    }
}

int LCS_DP(string s1, string s2, vector<vector<int>>& dp, int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s1[i-1] == s2[j-1]){
        return dp[i][j] = 1 + LCS_DP(s1, s2, dp, i-1, j-1);
    }else{
        return dp[i][j] = max(LCS_DP(s1, s2, dp, i-1, j), LCS_DP(s1, s2, dp, i, j-1));
    }
}
int main(){
    string s1 = "abcde";
    string s2 = "ace";
   int ans= LCS_Recursive(s1,s2,0,0);
   cout << "Length of Longest Common Subsequence: " << ans << endl;

    // Output: Length of Longest Common Subsequence: 3
    // Explanation: The longest common subsequence is "ace" with length 3.

    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
   int ans1 = LCS_DP(s1, s2, dp, s1.length(), s2.length());
    cout << "Length of Longest Common Subsequence using DP: " << ans1 << endl;
    return 0;

}