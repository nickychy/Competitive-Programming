
#include <bits/stdc++.h>
using namespace std;

void subset2(vector<int> v, int i, int n, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    for (int idx = i; idx < n; idx++)
    {
        if (idx != i && v[idx] == v[idx - 1])
            continue;
        ds.push_back(v[idx]);
        subset2(v, idx + 1, n, ans, ds);
        ds.pop_back();
    }
}
int main()
{
    vector<int> v{1, 2, 2, 2, 3, 3};
    vector<vector<int>> ans;
    vector<int> ds;
    int i = 0, n = v.size();
    sort(v.begin(), v.end()); // to get duplicates adjacent
    subset2(v, i, n, ans, ds);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}