// Given an integer N-> print 1 to N and vice versa
#include <bits/stdc++.h>
using namespace std;

// Print 1 to N
void print(int N)
{
    if (N == 0)
        return;
    print(N - 1);
    cout << N << " ";
}

// Print From N to 1
void print_dec(int N)
{
    if (N == 0)
        return;
    cout << N << " ";
    print_dec(N - 1);
}
int main()
{
    int N;
    cin >> N;
    print(N);
    cout << endl;
    print_dec(N);
}
/*t.c o(n)
s.c o(n)*/