#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin	>> t;
	while (t--)
	{
		int n, e, u, v;
		cin >> n >> e;
		int graph[n + 1][n + 1] = {0}; //1-based indexing
		//int graph[n][n] = {0}; //0-based indexing

		for (int i = 0; i < e; i++)
		{
			cin >> u >> v;//cin>>wt;
			//graph[u][v] = wt;//for weighted graph
			graph[u][v] = 1;
			graph[v][u] = 1; // comment this out if the graph is directed
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << " : ";
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][j] == 1)
					cout << j << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}


	return 0;
}