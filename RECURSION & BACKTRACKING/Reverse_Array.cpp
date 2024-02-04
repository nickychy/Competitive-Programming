#include <bits/stdc++.h>
using namespace std;

// using two pointers
void reverseArr(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        return;
    }
    swap(v[s], v[e]);
    reverseArr(v, s + 1, e - 1);
}

// using 1 variable
void reverseArray(vector<int> &v, int i)
{
    int n = v.size();
    if (i >= n / 2)
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        return;
    }
    swap(v[i], v[n - i - 1]);
    reverseArray(v, i + 1);
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    int n = v.size();
    reverseArr(v, 0, n - 1);
    cout << endl;
    reverseArray(v, 0);

    return 0;
}