void dfs(vector<int> adj[], bool* vis, int node, stack<int>&s)
{
    vis[node] = true;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    bool vis[V] = {false};
    vector<int> r;
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, s);
        }
    }
    while (!s.empty())
    {
        r.push_back(s.top());
        s.pop();
    }
    return r;
}