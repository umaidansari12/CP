#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	void dfs(vector<int> adj[], int source, bool *visited, int n, vector<int>&r, vector<vector<int>>&res)
	{
		visited[source] = true;
		r.push_back(source);
		if (source == n - 1)
		{
			res.push_back(r);
		}
		for (auto i : adj[source])
		{
			if (!visited[i])
			{
				dfs(adj, i , visited, n, r, res);
			}
		}
		visited[source] = false;
		r.pop_back();
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> adj[n];
		for (int i = 0; i < graph.size(); i++)
		{
			for (auto j : graph[i])
				adj[i].push_back(j);
		}
		bool visited[n];
		for (int i = 0; i < n; i++)
			visited[i] = false;
		vector<int> r;
		vector<vector<int>> res;
		dfs(adj, 0, visited, n, r, res);
		return res;
	}
};

void dfs(vector<int> adj[], int source, bool *visited, int n, vector<int>&r, vector<vector<int>>&res)
{
	visited[source] = true;
	r.push_back(source);
	if (source == n - 1)
	{
		res.push_back(r);
	}
	for (auto i : adj[source])
	{
		if (!visited[i])
		{
			dfs(adj, i , visited, n, r, res);
		}
	}
	visited[source] = false;
	r.pop_back();
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, e, s, d;
		cin >> n >> e >> s >> d;
		vector<int> adj[n];
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		bool visited[n] = {false};
		vector<int> r;
		vector<vector<int>> res;
		dfs(adj, s, visited, n, r, res);
		for (auto i : res)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
	}

	return 0;
}