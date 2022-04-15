#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool dfs(vector<int> adj[], vector<bool> &vis, int node, int parent)
{
	vis[node] = true;
	for (auto neighbour : adj[node])
	{
		if (!vis[neighbour])
		{
			if (dfs(adj, vis, neighbour, node))
				return true;
		}
		else if (neighbour != parent)
			return true;
	}
	return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
	vector<bool> vis(A + 1, false);
	vector<int> adj[A + 1];
	for (int i = 0; i < B.size(); i++)
	{
		adj[B[i][0]].push_back(B[i][1]);
		adj[B[i][1]].push_back(B[i][0]);
	}
	for (int i = 1; i <= A; i++)
	{
		if (!vis[i] && dfs(adj, vis, i, -1))
			return true;
	}
	return false;
}

class Solution
{
public:
	//Function to detect cycle in an undirected graph.

	bool checkCycle(int node, int parent, vector<bool>&vis, vector<int>adj[])
	{
		vis[node] = true; //marking the nodes as visited
		for (auto neighbour : adj[node])
		{
			if (!vis[neighbour]) //if adjacent nodes are not visited the visit it
			{
				if (checkCycle(neighbour, node, vis, adj)) //if the recursion calls return true that means it contains a cycle so we found and dont need to check for further
					return true;
			}
			else if (neighbour != parent) //if the adjacent node is visited and its not parent then return true because it contains a cycle
			{
				return true;
			}
		}
		return false;
	}
	bool isCycle(int V, vector<int>adj[])
	{
		// Code here
		vector<bool> vis(V, false);
		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
			{
				if (checkCycle(i, -1, vis, adj))
					return true;
			}
		}
		return false;
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
		bool ans = obj.isCycle(V, adj);
		if (ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends