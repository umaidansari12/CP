class Solution {
public:
  vector<vector<int>> adj;
  vector<int> vis;
  long long dfs(int node, vector<int> &Values)
  {
    long long sum = Values[node - 1];
    vis[node] = 1;
    for (auto i : adj[node])
    {
      if (!vis[i])
        sum += dfs(i, Values);
    }
    return sum;
  }
  long long solve(int V, int E, vector<int> Values, vector<vector<int>> Edges) {
    long long answer = 0;
    adj = vector<vector<int>>(V + 1);
    vis = vector<int>(V + 1);
    for (auto i : Edges)
    {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }
    for (int i = 1; i <= V; i++)
    {
      if (!vis[i]) {
        long long x = dfs(i, Values);
        if (answer < x)
          answer = x;
      }
    }
    return answer;
  }
};



//Use dfs or bfs to calculate the sum of each component.

class Solution {
public:
  void dfs(int v, vector<int> graphs[], long long int &sum, vector<int>& val, bool visited[])
  {
    visited[v] = true;
    sum += val[v - 1];
    for (auto i : graphs[v])
    {
      if (!visited[i])
      {
        dfs(i, graphs, sum, val, visited);
      }
    }
  }
  long long solve(int V, int E, vector<int> Values, vector<vector<int>> Edges) {
    //code here
    vector<int> graphs[V + 1];
    long long int ans = INT_MIN;
    for (int i = 0; i < E; i++)
    {
      graphs[Edges[i][0]].push_back(Edges[i][1]);
      graphs[Edges[i][1]].push_back(Edges[i][0]);
    }
    bool visited[V + 1] = {false};
    for (int i = 1; i <= V; i++)
    {
      if (!visited[i])
      {
        long long int sum = 0;
        dfs(i, graphs, sum, Values, visited);
        ans = max(sum, ans);
      }
    }
    return ans;
  }
};