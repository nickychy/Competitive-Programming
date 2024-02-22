/*Given N, and K jumps, minimize the energy of frog jump*/
#include <bits/stdc++.h>
using namespace std;
int maxSum(vector<int> v, int i)
{
    if (i == 0)
    {
        return v[i];
    }
    if (i < 0)
    {
        return 0;
    }
    // If Element is picked in subsequqnce
    int pick = maxSum(v, i - 2) + v[i];

    int notpick = maxSum(v, i - 1) + 0;
    return max(pick, notpick);
}

// Top Down dp
int maxSum_BU(vector<int> v, int i, vector<int> dp)
{
    /*Base Case*/
    if (i == 0)
    {
        return dp[0] = v[0];
    }
    if (i < 0)
    {
        return -1;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int pick = maxSum_BU(v, i - 2, dp) + v[i];
    int notpick = maxSum_BU(v, i - 1, dp);
    return dp[i] = max(pick, notpick);
}
/*T.C O(N)
S.C O(N)+O(N)
*/

// TABULATION
int maxSum_TD(vector<int> v, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = v[0];
    dp[1] = max(v[1], v[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(v[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}
/*T.C O(N)
S.C O(N)*/

// Space Optimization
int maxSum_SP(vector<int> &v, int n)
{
    int prev2 = v[0];
    int prev = max(v[0], v[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(prev, prev2 + v[i]);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    vector<int> v{2, 1, 4, 9};
    int n = v.size();
    vector<int> dp(n + 1, -1);
    cout << maxSum_SP(v, n);
    return 0;
}