/* Print All the possible combination of strings that can be made from a given string*/
#include <bits/stdc++.h>
using namespace std;

// using an extra visited array for keeping track of element visited
void printPermutation(vector<int> v, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &visited)
{
    if (ds.size() == v.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            ds.push_back(v[i]);
            printPermutation(v, ds, ans, visited);
            ds.pop_back();
            visited[i] = 0;
        }
    }
}

// optimized solution without extra space
// idea is to consider every element at idx by swapping values
void printPermutation2(vector<int> v, int idx, int n)
{
    if (idx == n)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(v[i], v[idx]);
        printPermutation2(v, idx + 1, n);
    }
}

int main()
{
    vector<int> v{1, 2, 3};
    int n = v.size();
    vector<bool> visited(n + 1, 0);
    vector<vector<int>> ans;
    vector<int> ds;
    printPermutation(v, ds, ans, visited);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    printPermutation2(v, 0, n);
}