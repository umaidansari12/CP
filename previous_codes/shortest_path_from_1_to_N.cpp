#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int minimumStep(int n) {
	//complete the function here
	int cnt = 0;
	while (n > 0)
	{
		if (n % 3 == 0)
			n /= 3;
		else
			n--;
		cnt++;
	}
	return cnt - 1;
}


int selectMin(vector<int>&dist, bool* vis, int v)
{
	int vertex = -1, d = INT_MAX;
	for (int i = 0; i < v; i++)
	{
		if (!vis[i] && (dist[i] < d))
		{
			vertex = i;
			d = dist[i];
		}

	}
	return vertex;
}
void dijkstra(vector<vector<int>> graph, int v)
{
	bool vis[v] = {false};//Stores Shortest Path Structure
	vector<int> dist(v, INT_MAX);//Keeps shortest path values to each vertex from source
	vector<int> parent(v, -1);//TRUE->Vertex is processed

	parent[0] = -1; //Start node has no parent
	dist[1] = 0;//start node has value=0 to get picked 1st

//Assuming start point as Node-0
	for (int i = 1; i < v - 1 ; i++)
	{
		//Select best Vertex by applying greedy method
		int u = selectMin(dist, vis, v);
		vis[u] = true; //Include new Vertex in shortest Path Graph
		//Relax adjacent vertices (not yet included in shortest path graph)
		for (int j = 1; j < v; j++)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			if (graph[u][j] != 0 && !vis[j] && dist[u] != INT_MAX && (dist[u] + graph[u][j] < dist[j]))
			{
				dist[j] = dist[u] + graph[u][j];
				parent[j] = u;
			}
		}
	}
	for (int i = 2; i < v; ++i)
		cout << "U->V: " << parent[i] << "->" << i << "  wt = " << graph[parent[i]][i] << "\n";
	cout << dist[v - 1] << endl;
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
			cout << graph[0][i] << " ";
		cout << endl;
		for (int i = 1; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if ((j == i + 1) || (j == 3 *
				                     i))
					graph[i][j] = 1;
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		dijkstra(graph, v);
	}



	return 0;
}