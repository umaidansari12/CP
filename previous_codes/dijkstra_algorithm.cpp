#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
	dist[0] = 0;//start node has value=0 to get picked 1st

//Assuming start point as Node-0
	for (int i = 0; i < v - 1 ; i++)
	{
		//Select best Vertex by applying greedy method
		int u = selectMin(dist, vis, v);
		vis[u] = true; //Include new Vertex in shortest Path Graph
		//Relax adjacent vertices (not yet included in shortest path graph)
		for (int j = 0; j < v; j++)
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
	for (int i = 1; i < v; ++i)
		cout << "U->V: " << parent[i] << "->" << i << "  wt = " << graph[parent[i]][i] << "\n";
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int v;
		cin >> v;
		vector<vector<int>> graph(v, vector<int>(v, 0));
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				cin >> graph[i][j];
		dijkstra(graph, v);
	}
//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)

	return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

#define INF 99999*/

// function to create an edge
void addEdge(vector<pair<int, int>> graph[], int u, int v, int w) {
	graph[u].push_back({v, w});
	graph[v].push_back({u, w});
}

void dijkstras(vector<pair<int, int>> graph[], int src, int V) {
	// use priority queue as min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// distance vector
	vector<int>dist(V, INF);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	// normal BFS traversal
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		// traverse for the neighbors of u
		for (auto x : graph[u]) {
			// x = {v, wt}
			int v = x.first;
			int wt = x.second;
			if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	cout << "Vertex   Distance from src\n";
	for (int i = 0; i < V; i++)
		cout << i << "\t" << dist[i] << endl;
}

int main() {
	int V = 9;
	vector<pair<int, int>> graph[V];
	addEdge(graph , 0, 1, 4);
	addEdge(graph , 0, 7, 8);
	addEdge(graph , 1, 2, 8);
	addEdge(graph , 1, 7, 11);
	addEdge(graph , 2, 3, 7);
	addEdge(graph , 2, 8, 2);
	addEdge(graph , 2, 5, 4);
	addEdge(graph , 3, 4, 9);
	addEdge(graph , 3, 5, 14);
	addEdge(graph , 4, 5, 10);
	addEdge(graph , 5, 6, 2);
	addEdge(graph , 6, 7, 1);
	addEdge(graph , 6, 8, 6);
	addEdge(graph , 7, 8, 7);

	dijkstras(graph, 0, 9);
}