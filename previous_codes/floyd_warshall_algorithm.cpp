#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void floydWarshallAlgorithm(vector<vector<int>>&graph, int v)
{
	vector<vector<int>>dist(v, vector<int>(v, 0));
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			dist[i][j] = graph[i][j];
	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
			{
				if (dist[i][k] == 10000000 || dist[k][j] == 10000000)
					continue;
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
	for (int i = 0; i < v; i++)
	{
		if (dist[i][i] < 0)
			return ;
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (dist[i][j] == 10000000)
				cout << "INF ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}

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
		int v;
		cin >> v;
		vector<vector<int>> graph(v, vector<int>(v, 0));
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				cin >> graph[i][j];
		floydWarshallAlgorithm(graph, v);

	}


	return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define V 6		//No of vertices

void floyd_warshall(int graph[V][V])
{
	int dist[V][V];

	//Assign all values of graph to allPairs_SP
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			dist[i][j] = graph[i][j];

	//Find all pairs shortest path by trying all possible paths
	for (int k = 0; k < V; ++k)	//Try all intermediate nodes
		for (int i = 0; i < V; ++i)	//Try for all possible starting position
			for (int j = 0; j < V; ++j)	//Try for all possible ending position
			{
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)	//SKIP if K is unreachable from i or j is unreachable from k
					continue;
				else if (dist[i][k] + dist[k][j] < dist[i][j])		//Check if new distance is shorter via vertex K
					dist[i][j] = dist[i][k] + dist[k][j];
			}

	//Check for negative edge weight cycle
	for (int i = 0; i < V; ++i)
		if (dist[i][i] < 0)
		{
			cout << "Negative edge weight cycle is present\n";
			return;
		}

	//Print Shortest Path Graph
	//(Values printed as INT_MAX defines there is no path)
	for (int i = 1; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
			cout << i << " to " << j << " distance is " << dist[i][j] << "\n";
		cout << "=================================\n";
	}
}

int main()
{
	int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
		{INT_MAX, 0, 4, 2, 7, INT_MAX},
		{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
		{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}
	};

	floyd_warshall(graph);
	return 0;
}

//TIME COMPLEXITY: O(V^3)