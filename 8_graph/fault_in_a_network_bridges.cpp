#include<bits/stdc++.h>
using namespace std;

void dfs(int cur, int par, vector<int>&vis, vector<int> adj[], vector<int>&low, vector<int>&disc, int &_time, vector<vector<int>> &bridges)
{
    vis[cur] = 1;
    disc[cur] = low[cur] = _time++;
    for (auto neighbour : adj[cur])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, cur, vis, adj, low, disc, _time, bridges);
            low[cur] = min(low[cur], low[neighbour]);

            if (low[neighbour] > disc[cur])
            {
                bridges.push_back({cur, neighbour});
            }
        }
        else if (neighbour != par)
        {
            low[cur] = min(low[cur], disc[neighbour]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
    vector<int> adj[n];
    for (auto edge : connections)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> bridges;
    vector<int> vis(n, 0);
    vector<int> disc(n, 0);
    vector<int> low(n, 0);
    int _time = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, adj, low, disc, _time, bridges);
        }
    }
    return bridges;
}