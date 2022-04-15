#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int src, int parent, bool* visited)
{
	visited[src] = true;
	for (auto node : adj[src])
	{
		if (!visited[node])
		{
			if (dfs(adj, node, src, visited))
				return true;
		}
		else if (node != parent)
		{
			return true;
		}
	}
	return false;
}

bool bfs(vector<int> adj[], int src, vector<int> parent, bool* visited)
{
	visited[src] = true;
	queue<int> q;
	q.push(src);
	while (!q.empty())
	{
		int curr_node = q.front();
		q.pop();
		for (auto node : adj[curr_node])
		{
			if (!visited[node])
			{
				q.push(node);
				visited[node] = true;
				parent[node] = curr_node;
			}
			else if (parent[curr_node] != node)
			{
				return true;
			}
		}
	}
	return false;
}

bool contains_cycle(int n, vector<pair<int, int> > edges) {
	//Complete this method
	vector<int> adj[n];
	int m = edges.size();
	for (int i = 0; i < m; i++)
	{
		adj[edges[i].first].push_back(edges[i].second);
		adj[edges[i].second].push_back(edges[i].first);
	}
	bool *visited = new bool[n] {false};
	vector<int> parent(n, -1);
	return bfs(adj, edges[0].first, parent, visited);
	//return dfs(adj, edges[0].first, -1, visited);


}