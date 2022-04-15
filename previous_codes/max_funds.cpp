#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dfs(vector<int>adj[], bool *vis, int node, vector<int>funds)
{
	vis[node] = true;
	int sum = funds[node - 1];
	for (auto i : adj[node])
	{
		if (!vis[i])
			sum += dfs(adj, vis, i, funds);
	}
	return sum;
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
		int n, edges, x, y;
		cin >> n;
		vector<int> funds(n, 0);
		vector<int> adj[n + 1];
		for (int i = 0; i < n; i++)
			cin >> funds[i];
		cin >> edges;

		for (int i = 0; i < edges; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int ans = 0;

		bool vis[n + 1] = {false};
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
				ans = max(ans, dfs(adj, vis, i, funds));
		}
		cout << ans << endl;
	}


	return 0;
}