#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<int> adj[], int source, bool *visited)
{
	visited[source] = true;
	for (auto i : adj[source])
	{
		if (!visited[i])
			dfs(adj, i , visited);
	}
}

void bfs(vector<int> adj[], int source, bool *visited)
{
	visited[source] = true;
	queue<int> q;
	q.push(source);
	while (!q.empty())
	{
		int curr = q.front();
		//visited[curr] = true;
		q.pop();
		for (auto i : adj[curr])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}

		}
	}
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
		bfs(adj, s, visited);
		if (visited[d])
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}