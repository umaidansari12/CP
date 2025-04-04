#include <bits/stdc++.h>

using namespace std;

// here recurrence (n,m) means minimum cost to reach from (0,0) -> (n,m)

// instead of INT_MAX, can return 1e9 which will overcome integer overflow with INT_MAX when adding with grid[n][m]

// TC - O(2^(N*M))
// SC - O(N*M) - deep calls
int minimize_path_sum(int n, int m, vector<vector<int>> &grid) {
	if (n == 0 and m == 0)
		return grid[n][m];
	if (n < 0 or m < 0)
		return INT_MAX;
	int up = minimize_path_sum(n - 1, m, grid);
	int left = minimize_path_sum(n, m - 1, grid);

	return min(up, left) + grid[n][m];
}

// TC - O(N*M)
// SC - O(N*M) + O(path length (m-1) + (n-1))

int minimize_path_sum(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
	if (n == 0 and m == 0)
		return grid[n][m];
	if (n < 0 or m < 0)
		return INT_MAX;
	if (dp[n][m] != -1)
		return dp[n][m];
	int up = minimize_path_sum(n - 1, m, grid);
	int left = minimize_path_sum(n, m - 1, grid);

	return dp[n][m] = min(up, left) + grid[n][m];
}

int minimize_path_sum_tabu(int n, int m, vector<vector<int>> &grid) {
	vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 and j == 0)
				dp[i][j] = grid[i][j];
			else {
				int up = INT_MAX, left = INT_MAX;
				if (i > 0)
					up = dp[i - 1][j];
				if (j > 0)
					left = dp[i][j - 1];
				dp[i][j] = min(min(up, left) + grid[i][j], dp[i][j]);
			}
		}
	}
	return dp[n - 1][m - 1];
}

int minimize_path_sum_space_optimization(int n, int m, vector<vector<int>> &grid) {
	vector<int> dp(m, INT_MAX);
	for (int i = 0; i < n; i++) {
		vector<int> temp(m, INT_MAX);
		for (int j = 0; j < m; j++) {
			if (i == 0 and j == 0)
				temp[j] = grid[i][j];
			else {
				int up = INT_MAX, left = INT_MAX;
				if (i > 0)
					up = dp[j];
				if (j > 0)
					left = temp[j - 1];
				temp[j] = min(min(up, left) + grid[i][j], temp[j]);
			}
		}
		dp = temp;
	}
	return dp[m - 1];
}






int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		cout << minimize_path_sum_space_optimization(n, m, a) << endl;
	}
}


/*
Input
4
2 3
5 9 6
11 5 2
1 1
5
2 2
5 6
1 2
3 3
1 2 3
4 5 4
7 5 9

Output
21
5
8
19

*/