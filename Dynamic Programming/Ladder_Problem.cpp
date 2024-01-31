/* Given a ladder of size N and integer K,compute the No of ways to climb the ladder if you can take a jump of atmost k at every steps

*/

#include <bits/stdc++.h>
using namespace std;

// T.C O(k^n)
int rec_Njumps(int n, vector<int> v)
{
    int k = v.size();
    // Base Case: If there is only one element in the array return 1 as we can jump from that position to itself
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    // Try  every possibility from k to n jumps
    int ans = 0;
    for (int i = 1; i <= k && n - i >= 0; i++)
    {
        ans += rec_Njumps(n - i, v);
    }
    return ans;
}

// TOP DOWN DP Code O(N.K)
int TD_Njumps(int n, vector<int> v, vector<int> dp)
{

    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    // check if state is already computed
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // otherwise calculate it
    int ans = 0;
    for (int i = 1; i <= v.size() && n - i >= 0; i++)
    {
        ans += TD_Njumps(n - i, v, dp);
    }
    dp[n] = ans;
    return dp[n];
}

// Bottom Up Approach  O(N.k)
int BU_Njumps(int n, vector<int> k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= k.size(); j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n = 4;
    vector<int> v{1, 2, 3};
    int k = v.size();
    cout << rec_Njumps(n, v) << endl;
    vector<int> dp(n + 1, 0);
    cout << TD_Njumps(n, v, dp) << endl;
    cout << BU_Njumps(n, v);
}