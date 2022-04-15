#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dfs(int src, vector<int> adj[], bool *visited, bool *black)
{
	int count = 1;
	//visited[src] = true;
	//black[src] = true;
	cout << src << endl;
	for (auto node : adj[src])
	{
		if (!visited[node] and !black[node])
		{
			black[node] = true;
			visited[node] = true;
			count += dfs(node, adj, visited, black);
			black[node] = false;
			count += dfs(node, adj, visited, black);
			visited[node] = false;
		}
	}
	//black[src] = false;
	//visited[src] = false;
	return count;
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
		int n, b, m;
		cin >> n >> b >> m;
		vector<int> adj[n + 1];
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool visited[n + 1] = {false};
		bool black[n + 1] = {false};
		black[b] = true;
		int count = dfs(b, adj, visited, black);
		cout << endl << count << endl;

	}


	return 0;
}