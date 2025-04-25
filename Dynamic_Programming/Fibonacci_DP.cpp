#include<bits/stdc++.h>
using namespace std;

/*
 * Problem: Calculate the nth Fibonacci number.
 * The Fibonacci sequence is defined as:
 * F(0) = 0
 * F(1) = 1
 * F(n) = F(n-1) + F(n-2) for n > 1
 */

/*
 * Approach 1: Simple Recursion
 * Directly implements the recursive definition.
 * Time Complexity: O(2^N) - Exponential, due to overlapping subproblems being recalculated multiple times.
 * Space Complexity: O(N) - Due to the depth of the recursion stack.
 */
int fibonacci(int n){
    // Base case: F(0) = 0, F(1) = 1
    if(n<=1){
        return n;
    }
    // Recursive step: F(n) = F(n-1) + F(n-2)
    return fibonacci(n-1)+fibonacci(n-2);
}

/*
 * Approach 2: Recursion + Memoization (Top-Down Dynamic Programming)
 * Stores the results of expensive function calls (subproblems) and returns the cached result
 * when the same inputs occur again.
 * Time Complexity: O(N) - Each Fibonacci number from 0 to n is computed only once.
 * Space Complexity: O(N) + O(N) = O(N) - O(N) for the dp array and O(N) for the recursion stack depth.
 * dp: A vector used for memoization, initialized with -1 (or another indicator for 'not computed yet').
 */
int fibonacci_Mem(int n,vector<int>&dp){
    // Base case
    if(n<=1){
        return n;
    }
    // If the result for n is already computed, return it from the dp table
    if(dp[n]!=-1){
        return dp[n];
    }
    // Compute the result, store it in the dp table, and then return it
    dp[n]=fibonacci_Mem(n-1,dp)+fibonacci_Mem(n-2,dp);
    return dp[n];
}

/*
 * Approach 3: Tabulation (Bottom-Up Dynamic Programming)
 * Builds the solution iteratively from the base cases up to the desired value n.
 * Time Complexity: O(N) - A single loop runs from 2 to n.
 * Space Complexity: O(N) - To store the Fibonacci numbers up to n in the dp array.
 */
int fibonaaci_Tab(int n){
    // Base case check
    if(n<=1){
        return n;
    }
    // dp[i] will store the ith Fibonacci number
    vector<int>dp(n+1);
    // Initialize base cases
    dp[0]=0;
    dp[1]=1;
    // Build the dp table iteratively
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    // Optional: Print the sequence stored in dp table
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout << endl; // Add a newline after printing the sequence
    // The nth Fibonacci number is stored at dp[n]
    return dp[n];
}

/*
 * Approach 4: Space Optimized Bottom-Up Dynamic Programming
 * Observes that to calculate F(n), we only need F(n-1) and F(n-2).
 * We can avoid using a full dp array by just keeping track of the previous two Fibonacci numbers.
 * Time Complexity: O(N) - A single loop runs from 2 to n.
 * Space Complexity: O(1) - Only uses a few variables to store the previous two values.
 */
int fibonacci_Space(int n){
    // Base case check
    if (n <= 1)
    {
        return n;
    }
    // Initialize variables to store the last two Fibonacci numbers
    int prev2=0; // Corresponds to F(i-2)
    int prev1=1; // Corresponds to F(i-1)
    int curr=0;  // Corresponds to F(i)

    // Iterate from 2 to n to calculate F(n)
    for(int i=2;i<=n;i++){
        // Calculate the current Fibonacci number
        curr=prev1+prev2;
        // Update the previous two values for the next iteration
        prev2=prev1;
        prev1=curr;
    }
    // The final result is stored in 'curr' (or 'prev1' after the loop)
    return prev1; // or return curr;
}

int main(){
    int n=6; // Example: Calculate the 6th Fibonacci number (0, 1, 1, 2, 3, 5, 8) -> F(6)=8

    // Call Simple Recursion
    cout << "Simple Recursion: F(" << n << ") = " << fibonacci(n) << endl;

    // Call Memoization
    vector<int>dp(n+1,-1); // Initialize dp table for memoization
    cout << "Memoization: F(" << n << ") = " << fibonacci_Mem(n,dp) << endl;

    // Call Tabulation
    cout << "Tabulation Sequence: ";
    int tab_result = fibonaaci_Tab(n);
    cout << "Tabulation: F(" << n << ") = " << tab_result << endl;

    // Call Space Optimized
    cout << "Space Optimized: F(" << n << ") = " << fibonacci_Space(n) << endl;

    return 0; // Indicate successful execution
}

