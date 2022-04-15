class Solution {
public:
    void dfs(vector<int> graph[], int node, vector<bool> &visited) {
        visited[node] = true;
        for (auto neighbour : graph[node]) {
            if (!visited[neighbour])
                dfs(graph, neighbour, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> graph[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j])
                    graph[i].push_back(j);
            }
        }
        int count = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(graph, i, visited);
            }
        }
        return count;

    }
};

class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int node, vector<bool> &visited) {
        visited[node] = true;
        for (int to = 0; to < isConnected[node].size(); to++) {
            if (isConnected[node][to] == 1 and !visited[to])
                dfs(isConnected, to, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};

//DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < visited.size(); i++) {
            groups += !visited[i] ? dfs(i, M, visited), 1 : 0;
        }
        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && M[i][j] && !visited[j]) {
                dfs(j, M, visited);
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};