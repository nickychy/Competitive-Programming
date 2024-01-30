#include <bits/stdc++.h>
using namespace std;
void leaders_in_Array(vector<int> &v)
{
    int n = v.size();
    vector<int> ans(n + 1);
    int curr_max = v[n - 1];
    ans.push_back(curr_max);
    for (int i = 0; i < n; i++)
    {
        if (v[i] > curr_max)
        {
            curr_max = v[i];
            ans.psh_back(v[i]);
        }
    }
    for (auto x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    int size;
    cin >> size;
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    leaders_in_Array(v);
    return 0;
}