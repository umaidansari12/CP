#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(vector<int>a[], bool *vis, int node, stack<int>&s)
{
	vis[node] =	true;
	for (int child : a[node])
	{
		if (!vis[child])
			dfs(a, vis, child, s);
	}
	s.push(node);
}

void revdfs(vector<int> a[], bool* v, int node)
{
	v[node] = true;
	//cout << node << " ";
	for (int child : a[node])
	{
		if (!v[child])
			revdfs(a, v, child);
	}
}


int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, u, v;
		cin >> n >> m;
		vector<int> a[n + 1];
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			a[u].push_back(v);
		}
		bool vis[n] = {false};
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				dfs(a, vis, i, s);
			}
		}
		vector<int> tg[n];
		for (int i = 0; i < n; i++)
		{
			for (int child : a[i])
				tg[child].push_back(i);
		}
		bool vi[n] = {false};
		int count = 0;
		while (!s.empty())
		{
			int node = s.top();
			s.pop();
			if (!vi[node])
			{
				//cout << "SCC : ";
				revdfs(tg, vi, node);
				count++;
				//cout << endl;
			}
		}
		cout << count << endl;
	}


	return 0;
}

void dfs(vector<int> a[], bool *vis, int node, stack<int> &s)
{
	vis[node] = true;
	for (int child : a[node])
	{
		if (!vis[child])
			dfs(a, vis, child, s);
	}
	s.push(node);
}
void revdfs(vector<int> a[], bool *vis, int node)
{
	vis[node] = true;
	for (int child : a[node])
	{
		if (!vis[child])
			revdfs(a, vis, child);
	}
}
int kosaraju(int V, vector<int> adj[])
{
	// Your code here
	bool vis[V] = {false};
	stack<int> s;
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
			dfs(adj, vis, i, s);
	}
	bool v[V] = {false};
	vector<int> tg[V];
	for (int i = 0; i < V; i++)
	{
		for (int child : adj[i])
			tg[child].push_back(i);
	}
	int count = 0;
	while (!s.empty())
	{
		int node = s.top();
		s.pop();
		if (!v[node])
		{
			revdfs(tg, v, node);
			count++;
		}
	}
	return count;

}