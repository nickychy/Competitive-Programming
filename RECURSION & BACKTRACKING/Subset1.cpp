#include <bits/stdc++.h>
using namespace std;
/* Brute force generate all sub sets using power set and cal sum
T.C 2^n*N
*/

// Recursive approach
void subsetSum(vector<int> &v, int i, int n, vector<int> &ans, int sum)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }
    // pick element
    subsetSum(v, i + 1, n, ans, sum + v[i]);
    // notpick
    subsetSum(v, i + 1, n, ans, sum);
}
// T.C O(2^N)+2^N(log(2^N))
int main()
{
    vector<int> v{3, 2, 4};
    vector<int> ans;
    int i = 0, n = v.size(), sum = 0;
    subsetSum(v, i, n, ans, sum);
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << " " << endl;
    }
    return 0;
}