#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void BFS_traverse(vector<int> adj[], int source, vector<bool> &visited)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void BFS(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS_traverse(adj, i, visited);
        }
    }
}
int main()
{
    int n = 7;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    BFS(adj, n);
    return 0;
    return 0;
}