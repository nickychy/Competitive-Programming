#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i)
{
    int n = s.size();
    if (i >= n / 2)
    {
        return true;
    }
    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    return checkPalindrome(s, i + 1);
}
int main()
{
    string s = "120321";
    cout << checkPalindrome(s, 0);
    return 0;
}