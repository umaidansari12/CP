#include <bits/stdc++.h>

using namespace std;
using ll = long long;


//implementation of djikstra algorithm in grid

// class Node {
// public:
// 	int x, y, dist;
// 	Node(int x, int y, int dist)
// 	{
// 		this->x = x;
// 		this->y = y;
// 		this->dist = dist;
// 	}
// };

// class Compare {
// public:
// 	bool operator()(const Node &a, const Node &b)
// 	{
// 		return a.dist <= b.dist;
// 	}
// };

// int shortest_path(vector<vector<int> > grid) {
// 	//return the shortest path len
// 	int n = grid.size(), m = grid[0].size();
// 	vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
// 	set<Node, Compare> s;
// 	distances[0][0] = grid[0][0];
// 	s.insert(Node(0, 0, grid[0][0]));
// 	int dx[] = {0, 0, 1, -1};
// 	int dy[] = {1, -1, 0, 0};
// 	while (!s.empty())
// 	{
// 		auto i = s.begin();
// 		int cx = i->x;
// 		int cy = i->y;
// 		int cd = i->dist;
// 		for (int k = 0; k < 4; k++)
// 		{
// 			int nx = cx + dx[k];
// 			int ny = cy + dy[k];
// 			if (nx >= 0 and nx<n and ny >= 0 and ny < m)
// 			{
// 				if (cd + grid[nx][ny] < distances[nx][ny])
// 				{
// 					Node temp(nx, ny, distances[nx][ny]);
// 					auto f = s.find(temp);
// 					if (f != s.end())
// 					{
// 						s.erase(f);
// 					}
// 					distances[nx][ny] = cd + grid[nx][ny];
// 					s.insert(Node(nx, ny, distances[nx][ny]));
// 				}
// 			}
// 		}
// 	}
// 	return distances[n - 1][m - 1];
// }

int shortest_pathbrute(vector<vector<int> > grid) {
	//return the shortest path len
	int n = grid.size(), m = grid[0].size();
	int total_cost = grid[0][0];

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	int cx = 0, cy = 0;
	while (cx <= (n - 1) and cy <= (m - 1))
	{
		int nx = cx, ny = cy;
		int cost = INT_MAX;
		for (int k = 0; k < 4; k++)
		{
			if (nx + dx[k] >= 0 and nx + dx[k] < n and ny + dy[k] >= 0 and ny + dy[k] < m)
			{
				if (cost > grid[nx + dx[k]][ny + dy[k]])
				{
					cost = grid[nx + dx[k]][ny + dy[k]];
					cx = nx + dx[k];
					cy = ny + dy[k];
				}
				total_cost += cost;
			}
		}
	}
	return total_cost;


}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> v[i][j];
			}
		}
		cout << shortest_pathbrute(v) << endl;
	}


	return 0;
}