#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> bfsShortestReach(int vertices, int m, vector<int> adj[], int s, vector<pair<int, int>> edges)
{
	queue<int> q;
	q.push(s);
	bool visited[vertices + 1] = {false};
	visited[s] = true;
	vector<int> dist(vertices + 1, -1);
	dist[s] = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (auto neighbour : adj[current])
		{
			if (!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour] = true;
				dist[neighbour] = dist[current] + 6;
			}

		}
	}
	vector<int> res;
	for (int i = 1; i < dist.size(); i++)
		if (dist[i] != 0)
			res.push_back(dist[i]);
	return res;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, s, x, y;
		cin >> n >> m;
		vector<pair<int, int>> edges;
		vector<int> adj[n + 1];
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			edges.push_back(make_pair(x, y));
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cin >> s;
		vector<int> res = bfsShortestReach(n, m, adj, s, edges);
		for (auto i : res)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}