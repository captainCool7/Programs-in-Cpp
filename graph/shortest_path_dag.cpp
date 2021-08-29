#include "bits/stdc++.h"
using namespace std;

void topoSort(int node, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto &p : adj[node])
    {
        if (!vis[p.first])
            topoSort(p.first, vis, adj, st);
    }
    st.push(node);
}

void shortestPath(int src, int n, vector<pair<int, int>> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            topoSort(i, vis, adj, st);

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX)
        {
            for (auto &p : adj[node])
            {
                if (dist[node] + p.second < dist[p.first])
                    dist[p.first] = dist[node] + p.second;
            }
        }
    }

    for (int i = 0; i < n; i++)
        dist[i] == INT_MAX ? cout << "INF" : cout << dist[i] << " ";
}

int main()
{
#ifndef JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    // BFS(adj,n,0);

    shortestPath(0, n, adj);
    return 0;
}