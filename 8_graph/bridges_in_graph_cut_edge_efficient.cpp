#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Time Complexity : O(N+E) i.e the complexity of a DFS
// Space Complexity : O(N+E) (graph) + O(N) (visited) + O(N) (discovery time) + O(N) (lowest time) + O(N) (Auxilliary stack space)

void dfs(int curr, int par, vector<int> adj[], vector<bool> &vis, vector<int> &disc, vector<int> &low, int &time, vector<pair<int, int>> &bridges)
{
	vis[curr] = true;
	disc[curr] = low[curr] = time++;//intially discovery and lowest time will be same equal to time which at the node is visited
	for (auto neighbour : adj[curr])
	{
		if (!vis[neighbour])
		{
			//if node is not visited then visit because after we have calculated lowest and disc time of childs then only we can calculate minimum of low[curr]
			dfs(neighbour, curr, adj, vis, disc, low, time, bridges);
			// we know low and disc of x because firstly we have moved down and calculated low  of childs then come to curr to calculate it low

			low[curr] = min(low[curr], low[neighbour]);
			//if a neighbour node has greater lowest time than discovery of current node that means we cant reach above curr through any of the path from neighbour then it is a bridge edge
			if (low[neighbour] > disc[curr])
			{
				bridges.push_back({curr, neighbour});
			}
		}
		else if (neighbour != par)
		{
			//we have found a backedge now we need to check if how many level above from curr we can reach by traversing the backedge from neighbour
			// now we have found a backedge and we need to check how much from the curr node we can reach i.e stored in disc[neighbour]  whichever edge  curr is pointing to we need its discovery time
			low[curr] = min(low[curr], disc[neighbour]);
		}
	}
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, e, u, v, time = 0;//time stores the time at which a particular node visits used to allocate the discovery time of every node
		cin >> n >> e;
		vector<int> adj[n + 1];
		for (int i = 0; i < e; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<bool> vis(n + 1, false);
		vector<int> disc(n + 1, 0); // stores discovery time of every node while traversing the DFS tree
		vector<int> low(n + 1, 0); // stores lowest time of every node i.e if there is backedge from this node then what minimum level node we can visit by traversing this backedge.
		vector<pair<int, int>> bridges; // stores  the bridges if there is a bridge in the graph

		//for(int i=0;i<=n;i++) if the graph nodes start from 0 to n
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				//dfs(i, -1, adj, vis, disc, low, time, bridges); if the graph nodes start from 0 then pass parent as -1 else 0
				dfs(i, 0, adj, vis, disc, low, time, bridges);
			}
		}
		for (auto bridge : bridges)
		{
			cout << bridge.first << " " << bridge.second << endl;
		}

	}


	return 0;
}