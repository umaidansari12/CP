class Solution {
public:
    bool bfs(vector<int> a[], vector<int>&color, int node)
    {
        color[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int child : a[curr])
            {
                if (color[child] == color[curr])
                    return false;
                if (color[child] == -1)
                {
                    color[child] = 1 - color[curr];
                    q.push(child);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> a[n];
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                a[i].push_back(graph[i][j]);
                a[graph[i][j]].push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(a, color, i))
                    return false;
            }
        }
        return true;
    }
};