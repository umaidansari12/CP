class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &graph, string src, string dest, double &ans, double temp, unordered_set<string>&visited) {
        if (src == dest) {
            ans = temp;
            return;
        }
        visited.insert(src);
        for (auto neighbour : graph[src]) {
            if (visited.find(neighbour.first) == visited.end()) {
                dfs(graph, neighbour.first, dest, ans, temp * neighbour.second, visited);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        vector<double> res;
        for (auto query : queries) {
            string src = query[0];
            string dest = query[1];
            unordered_set<string> visited;
            double ans = -1.0;
            if (graph.find(src) != graph.end()) {
                dfs(graph, src, dest, ans, 1.0, visited);
            }
            res.push_back(ans);
        }
        return res;
    }
};