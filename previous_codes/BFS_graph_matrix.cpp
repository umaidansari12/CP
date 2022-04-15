#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void BFS(vector<vector<int>> &adj, int s, int n)
{
	bool visited[n] = {false};
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		s = q.front();
		cout << s << " ";
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
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
		vector<vector<int>> adj(n, vector<int>(n, 0));
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x][y] = 1;
		}
		BFS(adj, 0, n);

	}


	return 0;
}