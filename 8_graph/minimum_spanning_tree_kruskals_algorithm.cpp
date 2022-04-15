#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int node, vector<int> &parent, vector<int>&rank)
	{
		if (parent[node] == node)
			return node;

		return parent[node] = find(parent[node], parent, rank);
	}

	void unionn(int u, int v, vector<int>&parent, vector<int>&rank)
	{
		u = find(u, parent, rank);
		v = find(v, parent, rank);
		if (rank[u] < rank[v])
		{
			parent[u] = v;
		}
		else if (rank[v] < rank[u])
		{
			parent[v] = u;
		}
		else
		{
			parent[u] = v;
			rank[v]++;
		}
	}
	static bool comp(vector<int> a, vector<int> b)
	{
		return a[0] < b[0];
	}
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		// code here
		vector<vector<int>> edges;//linear data structures to store the graph in the form wt u v instead of taking adjacency list because we want to take greedily the edge weight in a sorted order
		for (int i = 0; i < V; i++)
		{
			for (auto neighbour : adj[i])//traversing the graph in every vertex and storing in linear ds in (wt,u,v) form
			{
				int v = neighbour[0];
				int wt = neighbour[1];
				edges.push_back({wt, i, v});
			}
		}
		sort(edges.begin(), edges.end());//sorting the ds on the basis of weight
		vector<int> parent(V + 1, -1), rank(V + 1, 0);//initializing every node as a parent of itself and rank as 0
		for (int i = 0; i <= V; i++)
		{
			parent[i] = i;
			rank[i] = 0;
		}
		int cost = 0;
		//vector<pair<int,int>> mst; // this is used to take the edges in mst
		for (auto edge : edges)
		{
			//traversing the edges and greedily pick the minimum edge first maintaining minimum property of MST
			int wt = edge[0];
			int u = edge[1];
			int v = edge[2];
			//checking if both the nodes are not in the same component if they are in the same component then mst will have cycle which is not possible
			// if they are in diff component then mst will not have cycle maintaining spanning tree property of MST then only we union them if they are in diff component
			if (find(u, parent, rank) != find(v, parent, rank))
			{
				cost += wt;
				//mst.push_back({u,v});
				unionn(u, v, parent, rank);
			}
		}
		return cost;
	}
};

// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while (t--) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>> adj[V];
		int i = 0;
		while (i++ < E) {
			int u, v, w;
			cin >> u >> v >> w;
			vector<int> t1, t2;
			t1.push_back(v);
			t1.push_back(w);
			adj[u].push_back(t1);
			t2.push_back(u);
			t2.push_back(w);
			adj[v].push_back(t2);
		}

		Solution obj;
		cout << obj.spanningTree(V, adj) << "\n";
	}

	return 0;
}

// } Driver Code Ends