#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// using DFS
bool isCyclicRec(vector<int> adj[], int s, int parent, vector<bool> &vis)
{
    vis[s] = true;

    for (auto v : adj[s])
    {
        if (!vis[v])
        {
            if (isCyclicRec(adj, v, s, vis))
                return true;
        }
        else if (v != parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int n)
{
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (isCyclicRec(adj, i, -1, vis) == true)
                return true;
        }
    }
    return false;
}

// T.C O(v+e)

// USING BFS
bool isCyclicBFS2(vector<int> adj[], int i, vector<bool> &vis)
{

    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = true;
    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                q.push({v, u});
                vis[v] = true;
            }
            else if (v != parent)
                return true;
        }
    }
    return false;
}
bool isCyclicBFS(vector<int> adj[], int n)
{
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (isCyclicBFS2(adj, i, vis) == true)
                return true;
        }
    }
    return false;
}
int main()
{
    int n = 8;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 3, 5);
    cout << isCyclicBFS(adj, n);
    return 0;
}