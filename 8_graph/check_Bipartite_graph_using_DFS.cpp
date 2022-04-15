#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool checkBipartite(vector<int> adj[], vector<int> &color, int node)
	{
		if (color[node] == -1)//if first time visited color it
			color[node] = 0;
		for (auto neighbour : adj[node])
		{
			if (color[neighbour] == -1) //means the node hasnt been visited  and colored yet
			{
				color[neighbour] = 1 - color[node]; //coloring the adjacent node in opposite color
				if (!checkBipartite(adj, color, neighbour))
					return false;
			}
			else if (color[neighbour] == color[node]) // if the adjacent node has been colored previously and has  same color as its parent then it is not a bipartite
				return false;
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		// Code here
		vector<int> color(V, -1);
		for (int i = 0; i < V; i++) //checking for every component
		{
			if (color[i] == -1)
			{
				if (!checkBipartite(adj, color, i))
				{
					return false;
				}
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