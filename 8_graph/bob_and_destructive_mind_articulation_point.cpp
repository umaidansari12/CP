#include<bits/stdc++.h>
using namespace std;

void dfs(int cur, int par, vector<int>&vis, vector<int> adj[], vector<int>&low, vector<int>&disc, int &_time, set<int>& articulation_point)
{
    vis[cur] = 1;
    disc[cur] = low[cur] = _time++;
    int child = 0;
    for (auto neighbour : adj[cur])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, cur, vis, adj, low, disc, _time, articulation_point);
            child++;
            low[cur] = min(low[cur], low[neighbour]);

            if (par != 0 and low[neighbour] >= disc[cur])
            {
                articulation_point.insert(cur);
            }
        }
        else if (neighbour != par)
        {
            low[cur] = min(low[cur], disc[neighbour]);
        }
    }
    if (par == 0 and child > 1)
        articulation_point.insert(cur);
}

vector<bool> destructiveBob(int n, vector<vector<int>> edges, vector<int>queries)
{
    vector<int> adj[n + 1];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> articulation_point;
    vector<int> vis(n + 1, 0);
    vector<int> disc(n + 1, 0);
    vector<int> low(n + 1, 0);
    int _time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0, vis, adj, low, disc, _time, articulation_point);
        }
    }
    vector<bool> r;
    for (auto x : queries)
    {
        if (articulation_point.find(x) != articulation_point.end())
            r.push_back(true);
        else
            r.push_back(false);
    }
    return r;
}