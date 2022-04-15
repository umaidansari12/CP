#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(vector<int>g[], bool *vis, bool* rec, int node, stack<int>& s)
{
	if (!vis)
	{
		vis[node] = true;
		rec[node] = true;
		for (auto i : g[node])
		{
			if (!vis[i] && dfs(g, vis, rec, i, s))
				return true;
			else if (rec[i])
				return true;
		}
		s.push(node);
	}
	rec[node] = false;
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		stack<int> s;
		vector<int> g[n + 1];
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
		}
		bool vis[n + 1] = {false};
		bool rec[n + 1] = {false};
		bool f = false;
		for (int i = 1; i <= n; i++)
		{
			if (dfs(g, vis, rec, i, s))
			{
				f = true;
				break;
			}
		}
		if (!f)
		{
			while (!s.empty())
			{
				int t = s.top();
				cout << t << " ";
				s.pop();
			}
			cout << endl;
		}
		else
			cout << "Sandro fails.\n";

	}


	return 0;
}