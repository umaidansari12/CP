#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<int> adj[], bool* vis, int node, stack<int>&s)
{
	vis[node] = true;
	for (auto i : adj[node])
	{
		if (!vis[i])
		{
			dfs(adj, vis, i, s);
		}
	}
	s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) {
	// Your code here
	bool vis[V] = {false};
	vector<int> r;
	stack<int> s;
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			dfs(adj, vis, i, s);
		}
	}
	while (!s.empty())
	{
		r.push_back(s.top());
		s.pop();
	}
	return r;
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
		int n, e, x, y;
		cin >> n >> e;
		vector<int> adj[n];
		for (int i = 0; i < e; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
		}
		/*for (int i = 0; i < n; i++)
		{
			cout << i << "->";
			for (auto x : adj[i])
				cout << x << "->";
			cout << endl;
		}*/
		vector<int> r = topoSort(n, adj);
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}



	return 0;
}