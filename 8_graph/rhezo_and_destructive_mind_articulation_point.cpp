#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Time Complexity : O(N+E) i.e the complexity of a DFS
// Space Complexity : O(N+E) (graph) + O(N) (visited) + O(N) (discovery time) + O(N) (lowest time) + O(N) (Auxilliary stack space)

void dfs(int curr, int par, vector<int> adj[], vector<bool> &vis, vector<int> &disc, vector<int> &low, int &time, set<int> &articulation_point)
{
	vis[curr] = true;
	disc[curr] = low[curr] = time++;//intially discovery and lowest time will be same equal to time which at the node is visited
	int child = 0;//calculating the child of the current node by traversing the dfs if each time we enncounter a node that is not visited we increment the counter of child
	for (auto neighbour : adj[curr])
	{
		if (!vis[neighbour])
		{
			//if node is not visited then visit because after we have calculated lowest and disc time of childs then only we can calculate minimum of low[curr]
			dfs(neighbour, curr, adj, vis, disc, low, time, articulation_point);
			child++;//incrementing to calculate the  child
			// we know low and disc of x because firstly we have moved down and calculated low  of childs then come to curr to calculate it low

			low[curr] = min(low[curr], low[neighbour]);
			//if a neighbour node has greater lowest time or equal to the discovery of current node that means we cant reach above curr through any of the path from neighbour then it is a articulation_point or if we reach to the curr node through the neighbour then there is no point because if we delete the curr node deleting all its adjacent edges then we cant  reach above current by traversing the backedge of neighbour
			if (par != -1 and low[neighbour] >= disc[curr])
			{
				articulation_point.insert(curr);
			}
		}
		else if (neighbour != par)
		{
			//we have found a backedge now we need to check if how many level above from curr we can reach by traversing the backedge from neighbour
			// now we have found a backedge and we need to check how much from the curr node we can reach i.e stored in disc[neighbour]  whichever edge  curr is pointing to we need its discovery time
			low[curr] = min(low[curr], disc[neighbour]);
		}
	}

	// checking special case for root node because we cant say that by traversing the backedge we can reach above root because  it is the first node in the level so we cant reach above it
	// by par == 0 we are checking if the node's parent is 0 that means it is a root node
	// if in the dfs tree of the root node there is only child then deleting root node will not affect the connected components but if there is more than one child that means children are connected through root and if we delete root then number of connected components will increase
	if (par == -1 and child >= 2)
	{
		articulation_point.insert(curr);
	}

}
int main()
{
	// ios_base :: sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	// int t;
	// cin >> t;
	// while (t--) {
	int n, e, u, v, time = 0;//time stores the time at which a particular node visits used to allocate the discovery time of every node
	cin >> n >> e;
	vector<int> adj[n + 5];
	for (int i = 0; i < e; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> vis(n + 5, false);
	vector<int> disc(n + 5, 0); // stores discovery time of every node while traversing the DFS tree
	vector<int> low(n + 5, 0); // stores lowest time of every node i.e if there is backedge from this node then what minimum level node we can visit by traversing this backedge.
	set<int> articulation_point; // stores  the articulation point if there is a articulation point in the graph
	// we are using set because for multiple edges there can be same articulation point so we are using set to store unique articulation point

	//for(int i=0;i<=n;i++) if the graph nodes start from 0 to n
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			//dfs(i, -1, adj, vis, disc, low, time, bridges); if the graph nodes start from 0 then pass parent as -1 else 0
			dfs(i, -1, adj, vis, disc, low, time, articulation_point);
		}
	}
	//dfs(1, -1, adj, vis, disc, low, time, articulation_point);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> u;
		if (articulation_point.find(u) == articulation_point.end())
			cout << "Not Satisfied\n";
		else
			cout << "Satisfied " << adj[u].size() << "\n";
	}
	// }


	return 0;
}