void solve(vector<int> g[], int v, int N, bool visited[], vector<int>& r)
{
    r.push_back(v);
    visited[v] = true;
    for (auto i = g[v].begin(); i != g[v].end(); i++)
    {
        if (!visited[*i])
            solve(g, *i, N, visited, r);
    }
}
vector <int> dfs(vector<int> g[], int N)
{

    // Your code here
    bool visited[N] = {false};
    vector<int> res;
    solve(g, 0, N, visited, res);
    return res;
}

void DFSUtil (int i, vector <int> g[], int N, bool vis[], vector <int> &res)
{
    if (vis[i]) return;
    vis[i] = true;
    res.push_back (i);

    for (int j : g[i])
    {
        if (!vis[j]) DFSUtil (j, g, N, vis, res);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    bool vis[N];
    memset (vis, false, sizeof (vis));

    vector <int> res;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            DFSUtil (i, g, N, vis, res);
        }
    }

    return res;
}