class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> inDegree(numCourses, 0);
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue <int> q;
        for (int node = 0; node < numCourses; node++)
        {
            if (inDegree[node] == 0)
            {
                q.push(node);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto neighbour : graph[node])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        if (cnt == numCourses)
            return true;
        return false;


    }
};

class Solution {
public:
    bool dfs(vector<vector<int>>g, vector<bool>&vis, vector<bool>&rec, int node)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto i : g[node])
        {
            if (!vis[i] && dfs(g, vis, rec, i))
                return true;
            else if (rec[i])
                return true;
        }
        rec[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> res(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] and dfs(g, vis, res, i))
            {
                return false;
            }
        }
        return true;

    }
};

class Solution {
public:
    bool dfs(vector<int>g[], vector<bool>&vis, vector<bool>&rec, int node)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto i : g[node])
        {
            if (!vis[i] && dfs(g, vis, rec, i))
                return true;
            else if (rec[i])
                return true;
        }
        rec[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> res(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] and dfs(g, vis, res, i))
            {
                return false;
            }
        }
        return true;

    }
};

class Solution {
public:
    bool dfs(vector<int>g[], vector<bool>&vis, vector<bool>&rec, int node)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto i : g[node])
        {
            if (!vis[i] && dfs(g, vis, rec, i))
                return true;
            else if (rec[i])
                return true;
        }
        rec[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> g[numCourses];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> res(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i] and dfs(g, vis, res, i))
            {
                return false;
            }
        }
        return true;

    }
};