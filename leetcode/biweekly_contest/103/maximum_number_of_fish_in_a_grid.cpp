#include<bits/stdc++.h>

using namespace std;

// -1, 0
// 0, -1 	0, 0		0, 1
// 1, 0

class Solution {
public:
	int helper(vector<vector<int>> &grid, int m, int n, int i, int j, vector<vector<int>> &visited) {
		if (i<0 or j<0 or i >= m or j >= n or visited[i][j] == 1 or grid[i][j] == 0) {
			return 0;
		}
		int directions[4][2] = {{1, 0}, {0, 1}, {0, -1}, { -1, 0}};

		visited[i][j] = 1;
		int op1 = helper(grid, m, n, i, j + 1, visited);
		int op2 = helper(grid, m, n, i + 1, j, visited);
		int op3 = helper(grid, m, n, i, j - 1, visited);
		int op4 = helper(grid, m, n, i - 1, j, visited);
		return op1 + op2 + op3 + op4 + grid[i][j];
	}

	int findMaxFish(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> visited(m, vector<int>(n, 0));
		int answer = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] > 0 and visited[i][j] == 0) {
					// cout << i << ":" << j << endl;
					int val = helper(grid, m, n, i, j, visited);
					answer = max(answer, val);
				}
			}
		}
		return answer;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution ob = Solution();
		cout << ob.findMaxFish(grid) << endl;
	}
}

// class Solution {
// public:
//     void helper(vector<vector<int>> &grid, int m, int n, int i, int j, int sum, int &max_sum, int directions[4][2]) {
// 		if (grid[i][j] == 0) {
// 			max_sum = max(max_sum, sum);
// 			return;
// 		}
// 		// cout << i << " -> " << endl;
// 		// cout << sum << endl;
// 		sum += grid[i][j];
// 		for (int i = 0; i < 4; i++) {
// 			helper(grid, m, n, i + directions[i][0], j + directions[i][1], sum, max_sum, directions);
// 		}
// 	}

// 	int findMaxFish(vector<vector<int>>& grid) {
// 		int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
// 		int m = grid.size(), n = grid[0].size();
// 		int answer = 0;
// 		for (int i = 0; i < m; i++) {
// 			for (int j = 0; j < n; j++) {
// 				if (grid[i][j] > 0) {
// 					int max_sum = 0;
// 					// cout << i << ":" << j << endl;
// 					helper(grid, m, n, i, j, 0, max_sum, directions);
// 					answer = max(answer, max_sum);
// 				}
// 			}
// 		}
// 		return answer;
// 	}
// };

// void helper(vector<vector<int>> &grid, int m, int n, int i, int j, int sum, int &max_sum, int directions[4][2], vector<vector<bool>> &visited) {

// 	sum += grid[i][j];
// 	// cout << sum << endl;
// 	// cout << i << "->" << j << endl;
// 	visited[i][j] = true;
// 	for (int idx = 0; idx < 4; idx++) {
// 		int nx = i + directions[idx][0];
// 		int ny = j + directions[idx][1];
// 		if (0 <= nx and nx <= m - 1 and 0 <= ny and ny <= n - 1 and !visited[nx][ny] and grid[nx][ny] > 0)
// 			helper(grid, m, n, nx, ny, sum, max_sum, directions, visited);
// 	}
// 	max_sum = max(max_sum, sum);
// 	visited[i][j] = false;
// }

// int findMaxFish(vector<vector<int>>& grid) {
// 	int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
// 	int m = grid.size(), n = grid[0].size();
// 	vector<vector<bool>> visited(m, vector<bool>(n, false));
// 	int answer = 0;
// 	for (int i = 0; i < m; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (grid[i][j] > 0) {
// 				int max_sum = 0;
// 				// cout << i << ":" << j << endl;
// 				helper(grid, m, n, i, j, 0, max_sum, directions, visited);
// 				answer = max(answer, max_sum);
// 			}
// 		}
// 	}
// 	return answer;
// }