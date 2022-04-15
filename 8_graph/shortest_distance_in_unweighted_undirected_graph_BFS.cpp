#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y, src;
		cin >> n >> m;
		vector<int> graph[n], dist(n, INT_MAX);
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cin >> src;
		dist[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto neighbour : graph[node])
			{
				if (dist[node] + 1 < dist[neighbour]) {
					dist[neighbour] = dist[node] + 1;
					q.push(neighbour);
				}

			}
		}
		for (auto distance : dist)
			cout << distance << " ";
		cout << endl;
	}


	return 0;
}