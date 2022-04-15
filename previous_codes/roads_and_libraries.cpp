#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dfs(int node, vector<int> graph[], vector<bool>& visited)
{
	int count = 1;
	visited[node] = true;
	for (auto neighbour : graph[node])
		if (!visited[neighbour])
			count += dfs(neighbour, graph, visited);
	return count;
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
	vector<int> graph[n + 1];
	int a = cities.size();
	for (int i = 0; i < a; i++)
	{
		graph[cities[i][0]].push_back(cities[i][1]);
		graph[cities[i][1]].push_back(cities[i][0]);
	}
	vector<bool> visited(n + 1, false);
	vector<int> component;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			component.push_back(dfs(i, graph, visited));
		}
	}
	int m = component.size();

	long long ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans += min(((component[i] - 1) * c_road) + c_lib, component[i] * c_lib);
	}
	return ans;


}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	while (q--)
	{
		int n, m, c_lib, c_road, x, y;
		cin >> n >> m >> c_lib >> c_road;
		vector<int> graph[n + 1];
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		bool visited [n + 1] = {false};
		vector<int> components;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				components.push_back(dfs(i, graph, visited));
			}
		}
	}


	return 0;
}