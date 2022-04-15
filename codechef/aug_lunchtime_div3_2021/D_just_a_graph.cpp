#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<int> adj[], int node, vector<int>&vis)
{
	vis[node] = true;
	for (auto neighbour : adj[node])
	{
		if (!vis[neighbour])
			dfs(adj, neighbour, vis);
	}
}

void solve()
{
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; i++)
	{
		int wi;
		cin >> wi;
		s.insert(wi - i);
	}
	if (s.size() == 1)
		cout << n << '\n';
	else
		cout << 1 << '\n';
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		vector<int> adj[n + 1];
		vector<int>weight(n + 1, 0), vis(n + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> weight[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
			{
				if ((j - i) != (weight[j] - weight[i]))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				cnt++;
				dfs(adj, i, vis);
			}
		}
		cout << cnt << endl;
	}


	return 0;
}