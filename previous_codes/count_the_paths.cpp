#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	void dfs(vector<int> adj[], int source, bool *visited, int d, vector<int>&r, vector<vector<int>>&res)
	{
		visited[source] = true;
		r.push_back(source);
		if (source == d)
		{
			res.push_back(r);
		}
		for (auto i : adj[source])
		{
			if (!visited[i])
			{
				dfs(adj, i , visited, d, r, res);
			}
		}
		visited[source] = false;
		r.pop_back();
	}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d) {
		// Code here
		vector<int> adj[n];
		for (int i = 0; i < edges.size(); i++)
		{
			adj[edges[i][0]].push_back(edges[i][1]);
		}
		bool visited[n] = {false};
		vector<int> r;
		vector<vector<int>> res;
		dfs(adj, s, visited, d, r, res);
		return res.size();

	}
#include<bits/stdc++.h>
	using namespace std;

// } Driver Code Ends
	class Solution {
	public:
		void dfs(vector<int> adj[], int source, bool *visited, int d, vector<int>&r, vector<vector<int>>&res)
		{
			visited[source] = true;
			r.push_back(source);
			if (source == d)
			{
				res.push_back(r);
			}
			for (auto i : adj[source])
			{
				if (!visited[i])
				{
					dfs(adj, i , visited, d, r, res);
				}
			}
			visited[source] = false;
			r.pop_back();
		}
		int possible_paths(vector<vector<int>>edges, int n, int s, int d) {
			// Code here
			vector<int> adj[n];
			for (int i = 0; i < edges.size(); i++)
			{
				adj[edges[i][0]].push_back(edges[i][1]);
			}
			bool visited[n] = {false};
			vector<int> r;
			vector<vector<int>> res;
			dfs(adj, s, visited, d, r, res);
			return res.size();

		}
	};

// { Driver Code Starts.
	int main() {
		int tc;
		cin >> tc;
		while (tc--) {
			int n, m, s, d;
			cin >> n >> m >> s >> d;
			vector<vector<int>>edges;
			for (int i = 0; i < m; i++) {
				int u, v;
				cin >> u >> v;
				edges.push_back({u, v});
			}
			Solution obj;
			int ans = obj.possible_paths(edges, n, s, d);
			cout << ans << "\n";
		}
		return 0;
	}  // } Driver Code End
	swe
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends