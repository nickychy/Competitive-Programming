#include <bits/stdc++.h>
using namespace std;

// Recursive Approach
int rec_fib(int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return n;
    }
    // recursive call for last 2 numbers of fibonacci series
    return rec_fib(n - 1) + rec_fib(n - 2);
}
// T.C O(2^N)

// TOP DOWN DP
int dp1_fib(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    return dp[n] = dp1_fib(n - 1, dp) + dp1_fib(n - 2, dp);
}

// BOTTOM UP DP
int dp2_fib(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{

    int n;
    cin >> n;
    cout << rec_fib(n) << endl;
    vector<int> dp(n + 1, 0);
    cout << dp1_fib(n, dp) << endl;
    cout << dp2_fib(n);
}