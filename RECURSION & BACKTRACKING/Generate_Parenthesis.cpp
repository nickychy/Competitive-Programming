#include <bits/stdc++.h>
using namespace std;
void generateParenthesis(int n, int open, int close, string s)
{
    // if all parenthesis are generated
    if (open + close == 2 * n)
    {
        cout << s << endl;
    }

    // we can add open parenthesis if it is less than n
    if (open < n)
    {
        generateParenthesis(n, open + 1, close, s + "(");
    }
    // we can add a closing parenthesis if it is less than open
    if (close < open)
    {
        generateParenthesis(n, open, close + 1, s + ")");
    }
}
int main()
{
    int n;
    cin >> n;
    int openCount = 0, closeCount = 0;
    string s = "";
    generateParenthesis(n, openCount, closeCount, s);
}