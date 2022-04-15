class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        list<int> adj[n];
        for (auto edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {
                unordered_set<int> a;
                for (auto neighbour : adj[i])
                    a.insert(neighbour);
                for (auto neighbour : adj[j])
                    a.insert(neighbour);
                ans = max(ans, (int)a.size());
            }
        }
        return ans;
    }
};

// above is wrong solution

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> connected(n, vector<bool>(n, false)); //we use a 2-D representation of the graph to check if 2 vertices are connected with a direct road or not
        vector<int> degree(n, 0); //we are calculating degree of every node
        for (auto road : roads)
        {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, degree[i] + degree[j] - (connected[i][j] ? 1 : 0)); //taking sum of degree and if they are connected subtracting 1 from it else 0
            }
        }
        return ans;
    }
};

