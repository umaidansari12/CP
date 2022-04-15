#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int node, list<int> adj[], vector<bool>&vis)
{
	vis[node] = true;
	for (auto neighbour : adj[node])
	{
		if (!vis[neighbour])
			dfs(neighbour, adj, vis);
	}
}

void removedfs(int node, vector<int> adj[], vector<bool>&vis, int u, int v)
{
	vis[node] = true;
	for (auto neighbour : adj[node])
	{
		if (!vis[neighbour] and ((neighbour != u and node != v) or (neighbour != v and node != u)))
			removedfs(neighbour, adj, vis, u, v);
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m;
		list<int> graph[n];
		vector<pair<int, int> > edges;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			edges.push_back({u, v});
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int components = 0;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				dfs(i, graph, visited);
				components++;
			}
		}
		//cout << components << endl;
		for (int i = 0; i < m; i++)
		{
			fill(visited.begin(), visited.end(), false);
			int u = edges[i].first;
			int v = edges[i].second;
			graph[u].remove(v);
			graph[v].remove(u);
			// for (int i = 0; i < n; i++)
			// {
			// 	cout << i << " -> ";
			// 	for (auto neighbour : graph[i])
			// 		cout << neighbour << " ";
			// 	cout << endl;
			// }
			// cout << endl;
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (!visited[j])
				{
					dfs(i, graph, visited);
					cnt++;
				}
			}
			graph[u].push_back(v);
			graph[v].push_back(u);
			// cout << cnt << endl;
			if (cnt > components)
				cout << u << " " << v << endl;

		}
		cout << endl;



	}


	return 0;
}