#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	void solve(vector<vector<int>> &grid, int i, int j, int n, int m, int k, int &ans, int steps, int *dx, int *dy) {
		if (k >= 0 and i == n - 1 and j == m - 1) {
			ans = min(ans, steps);
			return;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = i + dx[dir];
			int ny = j + dy[dir];

			if (nx >= 0 and nx<n and ny >= 0 and ny<m and k >= 0) {
				if (grid[nx][ny] == 1)
					solve(grid, nx, ny, n, m, k - 1, ans, steps + 1, dx, dy);
				else
					solve(grid, nx, ny, n, m, k, ans, steps + 1, dx, dy);
			}
		}
	}
	int shortestPath(vector<vector<int>>& grid, int k) {
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};

		int n = grid.size(), m = grid[0].size(), ans = INT_MAX, steps = 0;

		solve(grid, 0, 0, n, m, k, ans, steps, dx, dy);

		if (ans == INT_MAX)
			return -1;
		return ans;

	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin	>> n >> m >> k;
		vector<vector<int>> grid(n, vector<int>(m, 0));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution ob;
		cout << ob.shortestPath(grid, k) << endl;

	}


	return 0;
}