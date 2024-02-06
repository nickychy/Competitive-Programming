#include <bits/stdc++.h>
using namespace std;
/*-----------technique to print only one answer
Base case Condition --> return true
else return false
At function call , if (f()==true) return true else false  means if function call return true then reurn true
*/

// PRINT ALL SUBSEQUENCE WHOSE SUM IS K
void subSeqSum(vector<int> &v, int i, int k, vector<int> &arr, int sum)
{
    int n = v.size();
    if (i == n)
    {
        if (sum == k)
        {
            for (auto x : arr)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    // take that element
    arr.push_back(v[i]);
    sum += v[i];
    subSeqSum(v, i + 1, k, arr, sum);
    // not take that element
    sum -= v[i];
    arr.pop_back();
    subSeqSum(v, i + 1, k, arr, sum);
}

// PRINT ANY ONE SUBSEQUENCE WHOSE SUM IS K
bool print_1_Subsequence(vector<int> &v, int i, int k, vector<int> &arr, int sum)
{
    int n = v.size();
    if (i == n)
    {
        // if condition satisfied
        if (sum == k)
        {
            for (auto x : arr)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        // if condition not satisfied
        return false;
    }
    arr.push_back(v[i]);
    sum += v[i];
    if (print_1_Subsequence(v, i + 1, k, arr, sum))
        return true;
    sum -= v[i];
    arr.pop_back();
    if (print_1_Subsequence(v, i + 1, k, arr, sum))
        return true;
}

// Count No of subsequnce Whose SUM IS K
int countSubsequence(vector<int> &v, int i, int k, int sum)
{
    int n = v.size();
    if (i == n)
    {
        // if condition satisfied
        if (sum == k)
            return 1;
        // if condition not satisfied
        else
            return 0;
    }
    sum += v[i];
    int left = countSubsequence(v, i + 1, k, sum);
    sum -= v[i];
    int right = countSubsequence(v, i + 1, k, sum);
    return (left + right);
}

int main()
{
    vector<int> v{1, 2, 1, 5};
    int i = 0, sum = 0, k = 7;
    vector<int> arr;
    // subSeqSum(v, i, k, arr, sum);
    // print_1_Subsequence(v, i, k, arr, sum);
    cout << countSubsequence(v, i, k, sum);

    return 0;
}