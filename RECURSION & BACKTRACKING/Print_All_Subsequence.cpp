#include <bits/stdc++.h>
using namespace std;
void printAllSubSequence(vector<int> v, int i, vector<int> subseq)
{
    int n = v.size();
    if (i >= n)
    {
        for (auto x : subseq)
            cout << x << " ";
        cout << endl;
        return;
    }
    // Include current element in the sequence and recur for remaining elements

    subseq.push_back(v[i]);
    printAllSubSequence(v, i + 1, subseq);

    subseq.pop_back();
    //  Exclude current element from the sequence and recur for remaining elements
    printAllSubSequence(v, i + 1, subseq);
}

/*T.C O(2^N)
S.C O(n)*/

int main()
{
    vector<int> v{1, 2, 3};
    vector<int> subseq;
    printAllSubSequence(v, 0, subseq);
    return 0;
}