#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	void solve(vector<vector<int>> &grid, int i, int j, int n, int m, int k, int &ans, int steps, int *dx, int *dy, vector<vector<bool>> &visited) {
		if (k >= 0 and i == n - 1 and j == m - 1) {
			ans = min(ans, steps);
			return;
		}

		if (visited[i][j] == true)
			return;

		visited[i][j] = true;

		for (int dir = 0; dir < 4; dir++) {
			int nx = i + dx[dir];
			int ny = j + dy[dir];

			if (nx >= 0 and nx<n and ny >= 0 and ny < m and !visited[nx][ny] and k >= 0) {
				if (grid[nx][ny] == 1)
					solve(grid, nx, ny, n, m, k - 1, ans, steps + 1, dx, dy, visited);
				else
					solve(grid, nx, ny, n, m, k, ans, steps + 1, dx, dy, visited);
			}
		}
	}
	int shortestPath(vector<vector<int>>& grid, int k) {
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};

		int n = grid.size(), m = grid[0].size(), ans = INT_MAX, steps = 0;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		solve(grid, 0, 0, n, m, k, ans, steps, dx, dy, visited);

		if (ans == INT_MAX)
			return -1;
		return ans;

	}

	bool isSafe(int x, int y, int row, int col) {
		return x >= 0 and y >= 0 and x < row and y < col;
	}
	int shortestPath(vector<vector<int>>& grid, int k) {
		// the question asks for shortest path so we immeditely thought of the BFS because it returns the shortest path from source to destination
		// we will use queue to store a vector of x,y,steps,k and will use visited array to store the number of obstacles removed till now we will check if the number of obstacles removed till now in curr_x,curr_y is greater than curr_k we will store curr_k in visited curr_x and curr_y so as to maintain the condition of the minimum number of steps
		int ans = INT_MAX;
		int row = grid.size(), col = grid[0].size();
		if (row == 1 and col == 1)
			return 0;
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};
		// source is 0,0 and destination is row-1,col-1 and if we have enough amount of obstacles to be removed then Manhattan distance is the shortest distance (x2-x1)+(y2-y1)
		if (k >= (row - 1 + col - 1)) {
			return row + col - 2;
		}

		vector<vector<int>> visited(row, vector<int>(col, INT_MAX));

		queue<vector<int>> q;
		q.push({0, 0, 0, k});

		while (!q.empty()) {
			vector<int> cur = q.front();
			q.pop();
			if (cur[0] == row - 1 and cur[1] == col - 1) {
				ans = min(ans, cur[2]);
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = cur[0] + dx[i];
				int nextY = cur[1] + dy[i];
				if (isSafe(nextX, nextY, row, col) and visited[nextX][nextY] > k - cur[3]) {
					visited[nextX][nextY] = k - cur[3];
					if (grid[nextX][nextY] == 1 and cur[3] > 0) {
						q.push({nextX, nextY, cur[2] + 1, cur[3] - 1});
					}
					else if (grid[nextX][nextY] == 0) {
						q.push({nextX, nextY, cur[2] + 1, cur[3]});
					}
				}
			}
		}

		return ans == INT_MAX ? -1 : ans;
	}

	void solve(vector<vector<int>> &grid, int i, int j, int n, int m, int k, int &ans, int steps, int *dx, int *dy, vector<vector<int>> &visited, int &eliminate) {
		if (k >= 0 and i == n - 1 and j == m - 1) {
			ans = min(ans, steps);
			return;
		}


		for (int dir = 0; dir < 4; dir++) {
			int nx = i + dx[dir];
			int ny = j + dy[dir];

			if (nx >= 0 and nx<n and ny >= 0 and ny < m and visited[nx][ny]>eliminate - k) {
				visited[nx][ny] = eliminate - k;
				if (grid[nx][ny] == 1 and k > 0)
					solve(grid, nx, ny, n, m, k - 1, ans, steps + 1, dx, dy, visited, eliminate);
				else
					solve(grid, nx, ny, n, m, k, ans, steps + 1, dx, dy, visited, eliminate);
			}
		}
	}
	int shortestPath(vector<vector<int>>& grid, int k) {
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};

		int n = grid.size(), m = grid[0].size(), ans = INT_MAX, steps = 0;
		vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
		solve(grid, 0, 0, n, m, k, ans, steps, dx, dy, visited, k);

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
		int n, m, k;
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