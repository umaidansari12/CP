class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = -1, count = 0, n = edges.size();
        map<int, int> m;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            m[u]++;
            m[v]++;
            if (m[u] > count)
            {
                count = m[u];
                center = u;
            }
            if (m[v] > count)
            {
                count = m[v];
                center = v;
            }
        }
        return center;

    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = -1, count = 0;
        map<int, vector<int>> m;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            m[u].push_back(v);
            m[v].push_back(u);
            if (m[u].size() > count)
            {
                count = m[u].size();
                center = u;
            }
            if (m[v].size() > count)
            {
                count = m[v].size();
                center = v;
            }
        }
        return center;

    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //finding indegree of nodes
        vector<int> inDegree(edges.size() + 2, 0);
        for (auto edge : edges)
        {
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        int count = 0, center = 0;
        for (int degree = 0; degree < inDegree.size(); degree++)
        {
            if (count < inDegree[degree])
            {
                count = inDegree[degree];
                center = degree;
            }
        }
        return center;
    }
};


// i have did this problem by finding the indegree of nodes and return ans which has n - 1 indegree

// update : got it
// center node must appear in every node, means the common node of any two edges will be our answer

class Solution {
public:
    int findCenter(vector<vector<int>>& edge) {
        //the center node in a star graph will be common in every edge
        // O(1) solution
        return (edge[0][0] == edge[1][0] or edge[0][0] == edge[1][1]) ? edge[0][0] : edge[0][1];
    }
};