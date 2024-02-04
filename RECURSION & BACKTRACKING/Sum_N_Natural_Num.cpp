#include <bits/stdc++.h>
using namespace std;
// Paramaterized way
void solve(int N, int sum)
{
    if (N < 1)
    {
        cout << sum << endl;
        return;
    }
    solve(N - 1, sum + N);
}

// FUNCTIONAL WAY
int sum_N_num(int N)
{

    if (N == 0)
        return 0;
    return N + sum_N_num(N - 1);
}
int main()
{
    int N;
    cin >> N;
    solve(N, 0);
    cout << sum_N_num(N);
}
/*t.c o(n)
s.c o(n)*/