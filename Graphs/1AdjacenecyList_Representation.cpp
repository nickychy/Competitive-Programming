#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void printGraph(vector<int> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter no of vertices: ";
    cin >> n;
    vector<int> adj[n];
    cout << "Enter edges :" << endl;
    for (int i = 0; i < 100; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == -1)
            break;
        addEdge(adj, u, v);
    }
    printGraph(adj, n);
    return 0;
}