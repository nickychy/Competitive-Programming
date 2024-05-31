#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSRec(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (!visited[u])
        {
            DFSRec(adj, u, visited);
        }
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFSRec(adj, i, visited);
        }
    }
}

int main()
{
    int n = 8;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 6, 7);
    DFS(adj, 7, 0);
    return 0;
}