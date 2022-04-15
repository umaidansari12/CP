#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[])
	{
		// code here
		queue<int> q;
		vector<int> inDegree(V, 0);
		for (int node = 0; node < V; node++)
		{
			for (auto neighbour : adj[node])
			{
				inDegree[neighbour]++;
			}
		}
		for (int node = 0; node < V; node++)
		{
			if (inDegree[node] == 0)
				q.push(node);
		}
		int cnt = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			cnt++;
			for (auto neighbour : adj[node])
			{
				inDegree[neighbour]--;
				if (inDegree[neighbour] == 0)
					q.push(neighbour);
			}
		}
		if (cnt == V)
			return false;
		return true;
	}
};

// { Driver Code Starts.


int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int V, E;
		cin >> V >> E;

		vector<int> adj[V];

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		cout << obj.isCyclic(V, adj) << "\n";
	}

	return 0;
}

// } Driver Code Ends