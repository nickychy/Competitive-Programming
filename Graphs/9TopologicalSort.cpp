#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v, vector<int> indegree)
{
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
        indegree[v]++;
    }
}

void topoSort(vector<int> adj[], int n, vector<int> indegree)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto v : adj[node])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
int main()
{

    int n = 8;
    vector<int> adj[n];
    vector<int> indegrre(n, 0);
    addEdge(adj, 0, 2, indegrre);
    addEdge(adj, 0, 3, indegrre);
    addEdge(adj, 1, 3, indegrre);
    addEdge(adj, 1, 5, indegrre);
    addEdge(adj, 6, 7, indegrre);
    addEdge(adj, 6, 2, indegrre);

    topoSort(adj, n, indegrre);
    return 0;
}