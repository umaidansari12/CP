#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// find toposort
// now traverse the stack space and take out the element one by
// one and check for its adjacent and maintain minimum in a distance array

void topoSort(int node, vector<pair<int, int> > graph[], vector<bool>&vis, stack<int>&s)
{
	vis[node] = true;
	for (auto neighbour : graph[node])
	{
		if (!vis[neighbour.first])
		{
			topoSort(neighbour.first, graph, vis, s);
		}
	}
	s.push(node);
}

vector<int> shortestDistance(vector<pair<int, int>> graph[], int n, int src)
{
	vector<bool> vis(n, false);
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			topoSort(i, graph, vis, s);
		}
	}
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
	while (!s.empty())
	{
		int node = s.top();
		s.pop();
		//if the node has been reached previously then only you can reach its adjacent node
		if (dist[node] != INT_MAX)
		{
			for (auto neighbour : graph[node])
			{
				if (dist[node] + neighbour.second < dist[neighbour.first])
					dist[neighbour.first] = dist[node] + neighbour.second;
			}
		}
	}
	return dist;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y, src, wt;
		cin >> n >> m;
		vector<pair<int, int>> graph[n];
		vector<int> dist(n, INT_MAX);
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> wt;
			graph[x].push_back({y, wt});
		}
		cin >> src;
		vector<int> distances = shortestDistance(graph, n, src);
		for (auto distance : distances)
			cout << distance << " ";
		cout << endl;
		dist[src] = 0;
		queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			for (auto neighbour : graph[node])
			{
				if (dist[node] + neighbour.second < dist[neighbour.first]) {
					dist[neighbour.first] = dist[node] + neighbour.second;;
					q.push(neighbour.first);
				}
			}
		}

		// both algorithms works the same

		// queue<pair<int, int>> q;
		// q.push({src, 0});
		// while (!q.empty())
		// {
		// 	int node = q.front().first;
		// 	int weight = q.front().second;
		// 	q.pop();
		// 	for (auto neighbour : graph[node])
		// 	{
		// 		if (dist[node] + neighbour.second < dist[neighbour.first]) {
		// 			dist[neighbour.first] = dist[node] + neighbour.second;;
		// 			q.push({neighbour.first, dist[neighbour.first]});
		// 		}
		// 	}
		// }
		for (auto distance : dist)
			cout << distance << " ";
		cout << endl;
	}


	return 0;
}

/*

#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj);
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[])
{
	int vis[N] = {0};
	stack<int> st;
	for (int i = 0; i < N; i++)
		if (!vis[i])
			findTopoSort(i, vis, st, adj);

	int dist[N];
	for (int i = 0; i < N; i++)
		dist[i] = 1e9;
	dist[src] = 0;

	while(!st.empty())
	{
		int node = st.top();
		st.pop();

		if (dist[node] != INF) {
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second;
		        }
		    }
		}
	}

	for (int i = 0; i < N; i++)
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " ";
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt;
	    adj[u].push_back({v, wt});
	}

	shortestPath(0, n, adj);

	return 0;
}
*/