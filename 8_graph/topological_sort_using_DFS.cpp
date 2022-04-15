#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node, vector<int> adj[], vector<bool>&vis, vector<int>&stack)
	{
		vis[node] = true;
		for (auto neighbour : adj[node])
		{
			if (!vis[neighbour])
				dfs(neighbour, adj, vis, stack);
		}
		stack.push_back(node);
	}
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> stack;
		vector<bool> vis(V, false);
		for (int i = 0; i < V; i++)
		{
			if (!vis[i])
			{
				dfs(i, adj, vis, stack);
			}
		}
		reverse(stack.begin(), stack.end());
		return stack;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

	if (V != res.size())
		return 0;

	vector<int> map(V, -1);
	for (int i = 0; i < V; i++) {
		map[res[i]] = i;
	}
	for (int i = 0; i < V; i++) {
		for (int v : adj[i]) {
			if (map[i] > map[v]) return 0;
		}
	}
	return 1;
}

void dfs(vector<int> adj[], bool* vis, int node, stack<int>&s)
{
	vis[node] = true;
	for (auto i : adj[node])
	{
		if (!vis[i])
		{
			dfs(adj, vis, i, s);
		}
	}
	s.push(node);//taking stack to push all the adjacent nodes first into the stack then after  the node which have called the dfs will be pushed inside the stack
}
vector<int> topoSort(int V, vector<int> adj[]) {
	// Your code here
	bool vis[V] = {false};
	vector<int> r;
	stack<int> s;
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			dfs(adj, vis, i, s);
		}
	}
	while (!s.empty())
	{
		r.push_back(s.top());
		s.pop();
	}
	return r;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, E;
		cin >> E >> N;
		int u, v;

		vector<int> adj[N];

		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
		}

		Solution obj;
		vector <int> res = obj.topoSort(N, adj);

		cout << check(N, res, adj) << endl;
	}

	return 0;
}  // } Driver Code Ends