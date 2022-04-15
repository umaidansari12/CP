#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    //Function to find if the given edge is a bridge in graph.b
    /*
    Approach :
    1. Count total no of components in the graph(comp1)
    2. Remove edge (c,d) & (d,c) from the graph .[From adjacency list]
    3. Count total no of components in the graph(comp2)
    4. if(comp1==comp2) return false otherwise return true
    */
    void dfs(int node, list<int> adj[], vector<bool>&vis)
    {
        vis[node] = true;
        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour])
                dfs(neighbour, adj, vis);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        list<int> graph[V];
        for (int i = 0; i < V; i++)
        {
            for (auto neighbour : adj[i])
            {
                graph[i].push_back(neighbour);
            }
        }
        int components = 0;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited);
                components++;
            }
        }
        fill(visited.begin(), visited.end(), false);
        int cnt = 0;
        int u = c;
        int v = d;
        graph[u].remove(v);
        graph[v].remove(u);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited);
                cnt++;
            }
        }
        if (cnt > components)
            return true;


        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends

//remove the start and end edge and then start dfs from start point and see if end is visited is not visited then it is a bridge otherwise not

/*
1) Remove the edge s-e
2)do dfs from s and see if you can reach e
3) if yes return true else false
this solution fails for the disconnected components in the graph
*/

void dfs(int s, list<int>adj[], bool visit[])
{
    visit[s] = true;
    for (auto it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if (!visit[*it])
            dfs(*it, adj, visit);
    }
}
bool Graph::isBridge(int u, int v) {

    bool visit[V] = {0};
    adj[u].remove(v);
    adj[v].remove(u);
    dfs(v, adj, visit);
    if (!visit[u])
        return true;
    return false;
}