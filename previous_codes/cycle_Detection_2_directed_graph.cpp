#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<int> adj[], bool *visited, bool *stack, int src)
{
	visited[src] = true;
	stack[src] = true;
	for (auto node : adj[src])
	{
		// if the neighbour is not visited so we call the dfs on it and if its neghbour return true we're going to return true
		//and true is returned when stack[node] is true that means we're going back to the node
		//from which the current node is being visited.
		if (!visited[node] and dfs(adj, visited, stack, node))
			return true;
		else if (stack[node])
			return true;
	}

	stack[src] = false;
	return false;
}

bool contains_cycle(int V, vector<pair<int, int> > edges) {
	//Complete this method
	vector<int> adj[V];
	int n = edges.size();
	for (int i = 0; i < n; i++)
	{
		adj[edges[i].first].push_back(edges[i].second);
		//adj[edges[i].second].push_back(edges[i].first);
	}
	bool *visited = new bool[V] {false};
	bool *stack = new bool[V] {false};
	return dfs(adj, visited, stack, edges[0].first);

}