#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	bool bfs(vector<int> a[], vector<int>&color, int node)
	{
		color[node] = 1;
		queue<int> q;
		q.push(node);
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			for (int child : a[curr])
			{
				if (color[child] == color[curr])
					return false;
				if (color[child] == -1)
				{
					color[child] = 1 - color[curr];
					q.push(child);
				}
			}
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> a[n];
		vector<int> color(n, -1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				a[i].push_back(graph[i][j]);
				a[graph[i][j]].push_back(i);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (color[i] == -1)
			{
				if (!bfs(a, color, i))
					return false;
			}
		}
		return true;
	}
};
class Solution {
public:
	bool checkBipartite(vector<int> adj[], vector<int> &color, int currNode)
	{
		queue<int> q;
		q.push(currNode);
		color[currNode] = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto neighbour : adj[node])
			{
				if (color[neighbour] == -1) //means the node hasnt been visited  and colored yet
				{
					color[neighbour] = 1 - color[node]; //coloring the adjacent node in opposite color
					q.push(neighbour);
				}
				else if (color[neighbour] == color[node]) // if the adjacent node has been colored previously and has  same color as its parent then it is not a bipartite
					return false;
			}
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		// Code here
		vector<int> color(V, -1);
		for (int i = 0; i < V; i++)
		{
			if (color[i] == -1)
			{
				if (!checkBipartite(adj, color, i))
					return false;
			}
		}
		return true;


	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if (ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends