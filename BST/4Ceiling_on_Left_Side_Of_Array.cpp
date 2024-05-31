#include <bits/stdc++.h>
using namespace std;
// Naive APproach
void bruteCeiling(vector<int> v, int n)
{
    cout << "-1"
         << " ";
    for (int i = 1; i < n; i++)
    {
        int diff = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (v[j] >= v[i])
            {
                diff = min(diff, v[j] - v[i]);
            }
        }
        if (diff = INT_MAX)
        {
            cout << -1 << " ";
        }

        else
        {
            cout << diff << " ";
        }
    }
}
void printCeiling(vector<int> v, int n)
{
    cout << -1 << " "; // left most element will not have any ceiling
    set<int> s;
    s.insert(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.lower_bound(v[i]) != s.end())
        {
            cout << *(s.lower_bound(v[i])) << " ";
        }
        else
        {
            cout << " -1 ";
        }
        s.insert(v[i]);
    }
}
int main()
{
    vector<int> v{2, 8, 30, 15, 25, 12};
    printCeiling(v, v.size());
    return 0;
}