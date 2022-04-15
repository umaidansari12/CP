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
		vector<int> graph[n + 1]; //1-based indexing
		//vector<pair<int, int>> graph[n + 1]; // 1-based indexing weighted graph pair(adjacent node, weight)
		//vector<pair<int, int>> graph[n]; // 0-based indexing weighted graph pair(adjacent node, weight)
		//vector<int> graph[n]; //0-based indexing

		for (int i = 0; i < e; i++)
		{
			cin >> u >> v;//cin>>wt;
			//graph[u].push_back({v,wt});//for weighted graph
			graph[u].push_back(v);
			graph[v].push_back(u);// comment this out if the graph is directed
		}
		for (int i = 1; i <= n; i++)
		{
			cout << i << " : ";
			for (auto neighbours : graph[i])
				cout << neighbours << " ";
			cout << "\n";
		}
		cout << "\n";
	}


	return 0;
}