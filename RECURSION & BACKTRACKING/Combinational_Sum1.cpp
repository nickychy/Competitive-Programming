/* Given an array of int and a target, return a list of all unique combinations of candidates where the chosen numbers sum to target.The same number may be
 chosen from candidates an unlimited number of times. */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &v, int i, int n, vector<vector<int>> &ans, vector<int> &arr, int target)
{
    // base case
    if (i == n)
    {
        if (target == 0)
        {
            ans.push_back(arr);
        }
        return ans;
    }
    // pick element
    if (target >= v[i])
    {
        arr.push_back(v[i]);
        // WE DO NOT INCREMENT INDEX AS WE CAN TAKE 1 ELEMENT MANY TIMES
        solve(v, n, i, ans, arr, target - v[i]);
        arr.pop_back();
    }

    // When element not picked
    solve(v, n, i + 1, ans, arr, target);
    return ans;
}
// T.C O(2 ^ t * K)
int main()
{
    vector<int> v{2, 3, 6, 7};
    int target = 7, i = 0;
    vector<int> arr;
    vector<vector<int>> ans;
    int n = v.size();
    solve(v, i, n, ans, arr, target);
    return 0;
}