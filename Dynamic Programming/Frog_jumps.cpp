#include <bits/stdc++.h>
using namespace std;
// TOP DOWN DP
int minFrogJump1(int i, vector<int> v, vector<int> &dp)
{

    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (i == 1)
    {
        return abs(v[1] - v[0]);
    }

    int left = minFrogJump1(i - 1, v, dp) + abs(v[i] - v[i - 1]);
    int right = minFrogJump1(i - 2, v, dp) + abs(v[i] - v[i - 2]);
    return dp[i] = min(left, right);
}
/*T.C O(N)
    S.c O(N)*/

// BOTTOM UP DP
int minFrogJump2(vector<int> v, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i <= n; i++)
    {
        int energy1 = dp[i - 1] + abs(v[i] - v[i - 1]);
        int energy2 = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(energy1, energy2);
    }
    return dp[n];
}

// Space Optimized
int minFrogJump3(vector<int> v, int n)
{
    int prev2 = 0;
    int prev = abs(v[1] - v[0]);
    for (int i = 2; i <= n; i++)
    {
        int left = prev + abs(v[i] - v[i - 1]);
        int right = prev2 + abs(v[i] - v[i - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n = 6;
    vector<int> v{30, 10, 60, 10, 60, 50};
    vector<int> dp(n + 1, -1);
    cout << minFrogJump1(n - 1, v, dp) << endl;
    cout << minFrogJump2(v, n - 1) << endl;
    cout << minFrogJump3(v, n - 1);
    return 0;
}