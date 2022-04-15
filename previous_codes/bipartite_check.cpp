#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool bfs(vector<int> a[], vector<int>&color, int node)
{
	color[node] = 1;
	queue<int> q;
	q.push(node);
	while (!q.empty())
	{
		int curr = q.front();

		q.pop();
		for (int i : a[curr])
		{
			if (color[i] == color[curr])
				return false;
			if (color[i] == -1)
			{
				color[i] = 1 - color[curr];
				q.push(i);
			}
		}
	}
	return true;
}
bool isBipartite(int G[][MAX], int V)
{
	//Your code here
	vector<int> a[V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (G[i][j] == 1)
				a[i].push_back(j);
		}
	}
	vector<int> color(V, -1);
	for (int i = 0; i < V; i++)
	{
		if (color[i] == -1)
		{
			if (!bfs(a, color, i))
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int v;
		cin >> v;
	}


	return 0;
}

class Solution {
public:
	bool bfs(vector<int> a[], vector<int>&color, int node)
	{
		color[node] = 1;
		queue<int> q;
		q.push(node);
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			for (int child : a[curr])
			{
				if (color[child] == color[curr])
					return false;
				if (color[child] == -1)
				{
					color[child] = 1 - color[curr];
					q.push(child);
				}
			}
		}
		return true;
	}
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<int> color(N + 1, -1);
		vector<int> a[N + 1];
		for (int i = 0; i < dislikes.size(); i++)
		{
			a[dislikes[i][0]].push_back(dislikes[i][1]);
			a[dislikes[i][1]].push_back(dislikes[i][0]);
		}
		for (int i = 1; i <= N; i++)
		{
			if (color[i] == -1)
			{
				if (!bfs(a, color, i))
					return false;
			}
		}
		return true;
	}
};