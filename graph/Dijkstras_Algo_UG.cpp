#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, m, a, b, wt, src;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }
    cin >> src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        int x = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (it = g[node].begin(); it != g[node].end(); it++)
        {
            int nextNode = it->first;
            int nextDist = it->second;
            if (dist[nextNode] > dist[node] + nextDist)
            {
                dist[nextNode] = dist[node] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    cout << "The distances from source, " << src << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}