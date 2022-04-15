#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Create a queue and enque the source node
POP a node from queue, print and mark it as visited
traverse all connected node to the POP node and check whether the node has already been visited or not
if not visited enque it
repeat the above step till queue isn't empty*/

vector <int> bfs(vector<int> g[], int N) {
	vector <bool> vis (N, false);
	int s = 0;
	vis[s] = true; // Initially mark source vertex as visited(true)
	vector <int> res;
	queue<int> q;
	q.push(s); // Push the source vertex to queue

	while (!q.empty()) // Till queue is not empty
	{
		int t = q.front();
		res.push_back (t);

		q.pop(); // Pop the queue front

		for (int v : g[t]) // Traverse through all the connected components of front
		{
			if (!vis[v]) { // If they are not visited, mark them visited and add
				// to queue
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return res;
}

void BFS(vector<vector<int>>&adj, int s, int n)
{
	bool visited[n] = {false};
	for (int i = 0; i < n; i++)
		visited[i] = false;
	list<int>queue;
	queue.push_back(s);
	visited[s] = true;
	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for (auto i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				queue.push_back(*i);
			}

		}
	}
	cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, e;
		cin >> n >> e;
		vector<vector<int>> adj(n);
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		int x = 0;
		BFS(adj, x, n);
	}


	return 0;
}