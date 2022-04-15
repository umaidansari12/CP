#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Graph {
	int V;
	list<int> *l;
public:
	Graph(int v)
	{
		this->V = v;
		l = new list<int>[V];
	}

	void addEdge(int src, int dest, bool undir = true)
	{
		l[src].push_back(dest);
		if (undir)
		{
			l[dest].push_back(src);
		}
	}

	void printAdjList()
	{
		for (int i = 0; i < V; i++)
		{
			cout << i << "-->";
			for (auto node : l[i])
				cout << node << ",";
			cout << endl;
		}
	}
	void bfs(int src)
	{
		queue<int> q;
		q.push(src);
		bool *visited = new bool[V] {false};
		visited[src] = true;
		while (!q.empty())
		{
			int f = q.front();
			cout << f << endl;
			q.pop();
			for (auto node : l[f])
			{
				if (!visited[node])
				{
					visited[node] = true;
					q.push(node);
				}
			}
		}
	}
	void bfsSingleSourceShortestPath(int src, int dest = -1)
	{
		queue<int> q;
		bool *visited = new bool[V] {false};
		int *distance = new int[V] {0};
		int *parent = new int[V];
		for (int i = 0; i < V; i++)
			parent[i] = -1;
		q.push(src);
		visited[src] = true;
		distance[src] = 0;
		parent[src] = src;
		while (!q.empty())
		{
			int f = q.front();
			//cout << f << endl;
			q.pop();
			for (auto node : l[f])
			{
				if (!visited[node])
				{
					q.push(node);
					visited[node] = true;
					distance[node] = distance[f] + 1;
					parent[node] = f;
				}
			}
		}
		if (dest != -1)
		{
			for (int i = 0; i < V; i++)
			{
				cout << "Shortest Distance to node " << i << " is " << distance[i] << endl;
			}
			int temp = dest;
			while (temp != src)
			{
				cout << temp << "--";
				temp = parent[temp];
			}
			cout << src << endl;
		}
	}

	void dfshelper(int src, bool *visited)
	{
		visited[src] = true;
		cout << src << ",";
		for (auto node : l[src])
		{
			if (!visited[node])
				dfshelper(node, visited);
		}
		return;
	}

	void dfs(int src)
	{
		bool *visited = new bool[V] {false};
		dfshelper(src, visited);
	}

	bool cycleDetectionUG()
	{

	}

};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.printAdjList();
	g.bfs(0);*/

	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);
	//g.bfs(1);
	//g.bfsSingleSourceShortestPath(1, 6);
	g.dfs(1);

	return 0;
}