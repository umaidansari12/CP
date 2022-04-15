bool dfs(vector<int>g[], bool vis[], bool rec[], int node)
{
    if (!vis[node])
    {
        vis[node] = true;
        rec[node] = true;
        for (auto i : g[node])
        {
            if (!vis[i] && dfs(g, vis, rec, i))
                return true;
            else if (rec[i] == true)
                return true;
        }
    }
    rec[node] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool vis[V] = {false};
    bool rec[V] = {false};
    for (int i = 0; i < V; i++)
    {
        if (dfs(adj, vis, rec, i))
            return true;
    }
    return false;
}

bool dfs(int u, vector<char> &colour, vector<int> adj[])
{
    if (colour[u] == 'w')       // If colour is intially 'w' change the colour to 'g'
    {
        colour[u] = 'g';

        // bool res;
        for (int v : adj[u])    // Traverse for its neighbouring vertices
        {
            if (dfs(v, colour, adj) == true)
                return true;
        }
        colour[u] = 'b';        // After successful traversal mark it as 'b'
        return false;
    }
    if (colour[u] == 'g')       // If node colour come as 'g' again it is repeated, return true.
        return true;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<char> colour(V, 'w');        // Mark the initial node as 'w'
    for (int i = 0; i < V; i++)
    {
        if (colour[i] == 'w')           // Intially the node is 'w'
        {
            if (dfs(i, colour, adj))    // If node is repeated again return true from dfs
                return true;
        }
    }
    return false;
}