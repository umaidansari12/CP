class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> graph[n];
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == end)
            {
                return true;
            }
            for (auto neighbour : graph[node])
            {
                if (!vis[neighbour])
                {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;


    }
};

class Solution {
public:
    bool dfs(int node, vector<int> graph[], vector<bool>&vis, int &end)
    {
        if (node == end)
            return true;
        vis[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                if (dfs(neighbour, graph, vis, end))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> graph[n];
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        return dfs(start, graph, vis, end);


    }
};

class Solution {
public:
    bool dfs(int node, vector<int> graph[], vector<bool>&vis, int &end)
    {
        vis[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                if (neighbour == end)
                    return true;
                if (dfs(neighbour, graph, vis, end))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> graph[n];
        if (start == end)
            return true;
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        return dfs(start, graph, vis, end);


    }
};
//disjoint set
class Solution {
public:
    vector<int> parent;
    int findParent(int node) {
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }
    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ;
        int pv = findParent(v);
        parent[pu] = pv;
    }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto e : edges) {
            makeSameGroup(e[0] , e[1]);
        }
        return findParent(start) == findParent(end);
    }
};