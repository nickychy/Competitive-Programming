#include <bits/stdc++.h>
using namespace std;
// Paramtarized way
void fact(int N, int factorial)
{
    if (N <= 0)
    {
        cout << factorial << endl;
        return;
    }
    fact(N - 1, factorial * N);
}

// Functional Way
int fact2(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact2(n - 1);
}
int main()
{
    int n;
    cin >> n;
    fact(n, 1);
}
/*t.c o(n)
s.c o(n)*/