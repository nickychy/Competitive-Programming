// Fibonacci series for Nth term 0 1 1 2 3 5 8....
#include <bits/stdc++.h>
using namespace std;
int fibonacci(int N)
{
    if (N == 0 || N == 1)
        return N;
    return fibonacci(N - 1) + fibonacci(N - 2);
}
/*T.C O(2^N)
S.C O(N)*/
int main()
{
    int N = 10;
    cout << fibonacci(10);
    return 0;
}