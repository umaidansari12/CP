#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool bfs(vector<int> adj[], vector<bool> &vis, int node)
{
	queue<pair<int, int>> q;
	q.push({node, -1});
	vis[node] = true;
	while (!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for (auto neighbour : adj[node])
		{
			if (!vis[neighbour])
			{
				vis[neighbour] = true;
				q.push({neighbour, node});
			}
			else if (neighbour != parent)
				return true;
		}
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
		if (!vis[i])
		{
			if (bfs(adj, vis, i))
				return true;
		}

	}
	return false;
}



class Solution
{
public:
	//Function to detect cycle in an undirected graph.

	bool checkCycle(int node, int parent, vector<bool>&vis, vector<int>adj[])
	{
		queue<pair<int, int>> q;
		vis[node] = true;
		q.push({node, parent});
		while (!q.empty())
		{
			pair<int, int> curr = q.front();
			q.pop();
			vis[curr.first] = true;
			for (auto neighbour : adj[curr.first])
			{
				if (!vis[neighbour])
				{
					q.push({neighbour, curr.first});
				}
				else if (neighbour != curr.second)
				{
					return true;
				}
			}
		}
		return false;

		/*
		queue<pair<int, int>> q;
		vis[node] = true;
		q.push({node, parent});
		while (!q.empty())
		{
			int node = q.front().first;
			int parent = q.front().second;
			q.pop();
			for (auto neighbour : adj[node])
			{
				if (!vis[neighbour])
				{
					vis[neighbour] = true;
					q.push({neighbour, node});
				}
				else if (neighbour != parent)
				{
					return true;
				}
			}
		}
		return false;

		*/
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