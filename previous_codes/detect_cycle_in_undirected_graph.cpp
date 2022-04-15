#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(vector<vector<int>>&a, int node, int parent, bool visited[])
{
	visited[node] = true;
	for (auto i = a[node].begin(); i != a[node].end(); i++)
	{
		if (!visited[*i])
		{
			if (dfs(a, *i, node, visited))
				return true;
		}
		else if (*i != parent)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, e;
		cin >> n >> e;
		vector<vector<int>> a(n);
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		bool visited[n] = {false};
		bool f = false;
		if (dfs(a, 0, -1, visited))
			cout << "YES\n";
		else
			cout << "NO\n";


	}


	return 0;
}

bool dfs(vector<vector<int>> g, vector<bool> &vis, int node, int parent)
{
	vis[node] = true;
	for (int i = 0; i < g[node].size(); i++)
	{
		int t = g[node][i];
		if (!vis[t] && dfs(g, vis, t, node))
			return true;
		else if (t != parent && vis[t] )
			return true;
	}
	vis[node] = false;
	return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
	vector<bool> vis(A + 1, false);
	vector<vector<int>> adj(A + 1);
	for (int i = 0; i < B.size(); i++)
	{
		adj[B[i][0]].push_back(B[i][1]);
		adj[B[i][1]].push_back(B[i][0]);
	}
	for (int i = 1; i <= A; i++)
	{
		if (!vis[i] && dfs(adj, vis, i, -1))
			return true;
	}
	return false;
}



bool dfs(vector<int> g[], vector<int> visited, int node)
{
	if (visited[node] == 2)
		return true;
	visited[node] = 1;
	for (int i = 0; i < g[node].size(); i++)
	{
		if (visited[g[node][i]] == 1)
		{
			visited[g[node][i]] = 2;
		}
		else
		{
			if (dfs(g, visited, g[node][i]))
				return true;
		}
	}
	return false;
}
bool isCyclic(vector<int> g[], int V)
{
	// Your code here
	vector<int> visited(V, 0);
	for (int i = 0; i < V; i++)
	{
		visited[i] = 1;
		for (int j = 0; j < g[i].size(); j++)
		{
			if (dfs(g, visited, g[i][j]))
				return true;
		}
		visited[i] = 0;
	}
	return false;
}

bool bfs(vector<int> g[], bool visited[], int node, int parent)
{
	visited[node] = true;
	for (auto i = g[node].begin(); i != g[node].end(); i++)
	{
		if (!visited[*i])
		{
			if (bfs(g, visited, *i, node))
				return true;
		}
		else if (*i != parent)
		{
			return true;
		}
	}
	return false;
}
bool isCyclic(vector<int> g[], int V)
{
	// Your code here
	bool visited[V] = {false};
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			if (bfs(g, visited, i, -1))
				return true;
		}
	}
	return false;
}