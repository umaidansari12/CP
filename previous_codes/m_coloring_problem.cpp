#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(int c, vector<vector<int>>&graph, int ver, vector<int>&color, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (graph[ver][i] && c == color[i])
			return false;
	}
	return true;
}

bool m_coloring_graph(vector<vector<int>>&graph, int ver, int n, int m, vector<int>&color)
{
	if (ver == n)
	{
		return true;
	}
	for (int c = 1; c <= m; c++)
	{
		if (isSafe(c, graph, ver, color, n))
		{
			color[ver] = c;
			if (m_coloring_graph(graph, ver + 1, n, m, color))
				return true;
			color[ver] = 0;
		}
	}
	return false;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, e;
		cin >> n >> m >> e;
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x - 1][y - 1] = graph[y - 1][x - 1] = 1;
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << graph[i][j] << " ";
			cout << endl;
		}*/

		vector<int> color(n);
		if (m_coloring_graph(graph, 0, n, m, color))
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}


	}


	return 0;
}