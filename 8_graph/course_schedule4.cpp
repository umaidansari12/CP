//BFS from each node and storing path visited in a 2d matrix and after  that querying whther reachable or not
// time complexity : O(n+e)*n;
// space  complexity : O(n2) + O(n2) + O(n+e)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> graph[numCourses];
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<vector<bool>> visited(numCourses, vector<bool>(numCourses, false));
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        queue<int> q;
        for (int node = 0; node < numCourses; node++)
        {
            q.push(node);
            while (!q.empty())
            {
                int currNode = q.front();
                q.pop();
                for (auto neighbour : graph[currNode])
                {
                    if (!visited[node][neighbour])
                    {
                        q.push(neighbour);
                        visited[node][neighbour] = true;
                        isReachable[node][neighbour] = true;
                    }
                }
            }
        }
        vector<bool> ans;
        for (auto query : queries)
        {
            ans.push_back(isReachable[query[0]][query[1]]);
        }
        return ans;
    }
};



class Solution {
public:
    bool topoSort(int node, vector<int> graph[], vector<bool>&vis, vector<bool>&rec, stack<int>&s)
    {
        vis[node] = true;
        rec[node] = true;
        for (auto neighbour : graph[node])
        {
            if (!vis[neighbour] and topoSort(neighbour, graph, vis, rec, s))
                return true;
            else if (rec[neighbour])
                return true;
        }
        s.push(node);
        rec[node] = false;
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> vis(numCourses, false), rec(numCourses, false), result(queries.size(), false);
        if (prerequisites.size() == 0)
            return result;
        vector<int> graph[numCourses];
        stack<int> s;
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
        }
        for (int node = 0; node < numCourses; node++)
        {
            if (!vis[node] and topoSort(node, graph, vis, rec, s))
            {
                return result;
            }
        }
        map<int, int> topo;
        int cnt = 0;
        while (!s.empty())
        {
            topo.insert({s.top(), cnt});
            cnt++;
            s.pop();
        }
        for (int i = 0; i < queries.size(); i++)
        {
            if (topo[queries[i][0]] < topo[queries[i][1]])
                result[i] = true;
        }
        return result;

    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> vis(numCourses, false), result(queries.size(), false);
        if (prerequisites.size() == 0)
            return result;
        vector<int> graph[numCourses];
        vector<int> inDegree(numCourses, 0);
        for (auto edge : prerequisites)
        {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        queue<int> q;
        map<int, int> topo;
        int cnt = 0;
        for (int node = 0; node < numCourses; node++)
        {
            if (inDegree[node] == 0)
            {
                q.push(node);
                topo.insert({node, cnt});
            }
        }
        cnt++;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.insert({node, cnt});
            cnt++;
            for (auto neighbour : graph[node])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            if (topo[queries[i][0]] < topo[queries[i][1]])
                result[i] = true;
        }
        return result;

    }
};