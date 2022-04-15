#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Time Compleity : O(N^3)
// Space Compleity : O(N^2)

void shortestPath(vector<vector<int>> graph, int n)
{
	vector<vector<int>> dist(n, vector<int>(n, 0));


	//Assign all values of graph to allPairs_SP
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}

	//Find all pairs shortest path by trying all possible paths
	for (int k = 0; k < n; k++)//Try all intermediate nodes
	{
		for (int i = 0; i < n; i++)//Try for all possible starting position
		{
			for (int j = 0; j < n; j++)//Try for all possible ending position
			{
				if (dist[i][k] != INT_MAX or dist[k][j] != INT_MAX)//SKIP if K is unreachable from i or j is unreachable from k
					continue;
				else //Check if new distance is shorter via vertex K else if(dist[i][k]+dist[k][j] < dist[i][j])
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	//Check for negative edge weight cycle
	for (int i = 0; i < n; i++)
	{
		if (dist[i][i] < 0)
		{
			cout << "Negative edge weight cycle  is present\n";
			return;
		}
	}
	//Print Shortest Path Graph
	//(Values printed as INT_MAX defines there is no path)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << i << " to " << j << " distance is " << dist[i][j] << "\n";
			cout << "=================================\n";
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
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> adj[i][j];
			}
		}
		shortestPath(adj, n);

	}


	return 0;
}