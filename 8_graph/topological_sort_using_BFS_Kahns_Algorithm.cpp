#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> inDegree(V, 0), topo;
		for (int node = 0; node < V; node++)
		{
			for (auto neighbour : adj[node])
			{
				inDegree[neighbour]++;//maintaining indegree because we have to remove the dependencies and if there is no dependencies at first i.e indegree 0 then that means there is no incoming edge and all the nodes will appear after  this node in topological sorting
			}
		}
		queue<int> q;
		for (int node = 0; node < V; node++)
		{
			if (inDegree[node] == 0)
				q.push(node);
		}
		while (!q.empty())
		{
			int node = q.front();
			topo.push_back(node);
			q.pop();
			for (auto neighbour : adj[node])
			{
				if (inDegree[neighbour] - 1 >= 0)
				{
					inDegree[neighbour]--;
					if (inDegree[neighbour] == 0)
						q.push(neighbour);
				}
			}
		}
		return topo;
	}
	vector<int> topo(int N, vector<int> adj[]) {
		queue<int> q;
		vector<int> indegree(N, 0);
		for (int i = 0; i < N; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		for (int i = 0; i < N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node)
			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.push(it);
				}
			}
		}
		return topo;
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