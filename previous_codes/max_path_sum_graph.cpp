#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void DFS(int src, vector<int> graph[], vector<bool>&visited, vector<int> values, int res, int &ans)
{
	res += values[src];
	ans = max(ans, res);
	visited[src] = true;
	for (auto node : graph[src])
	{
		if (!visited[node])
			DFS(node, graph, visited, values, res, ans);
	}
	visited[src] = false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;//no of test cases
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> parent(n), values(n);
		for (int i = 0; i < n; i++)
			cin >> parent[i];
		for (int i = 0; i < n; i++)
			cin >> values[i];
		vector<int> graph[n];
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++)
		{
			if (parent[i] != -1)
			{
				graph[parent[i]].push_back(i);
				graph[i].push_back(parent[i]);
			}
		}
		int ans = INT_MIN, res = 0;
		for (int i = 0; i < n; i++)
		{
			//visited.clear();
			DFS(i, graph, visited, values, res, ans);
		}
		cout << ans << endl;

	}


	return 0;
}