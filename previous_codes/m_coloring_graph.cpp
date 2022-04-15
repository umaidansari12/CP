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

bool m_coloring_graph(vector<vector<int>>&res, vector<vector<int>>&graph, int ver, int n, int m, vector<int>&color)
{
	if (ver == n)
	{
		res.push_back(color);
		return true;
	}
	bool r = false;
	for (int c = 1; c <= m; c++)
	{
		if (isSafe(c, graph, ver, color, n))
		{
			color[ver] = c;
			r = m_coloring_graph(res, graph, ver + 1, n, m, color) || r;
			color[ver] = 0;
		}
	}
	return r;
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
		/*int n, m, e;
		cin >> n >> m >> e;*/
		int n, m;
		cin >> n;
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];
		}
		cin >> m;
		vector<int> color(n);
		vector<vector<int>>res;
		if (m_coloring_graph(res, graph, 0, n, m, color))
		{
			for (vector<int> r : res)
			{
				for (int i : r)
					cout << i << " ";
				cout << endl;
			}


		}
		else
		{
			cout << "No Solution!\n";
		}


	}


	return 0;
}