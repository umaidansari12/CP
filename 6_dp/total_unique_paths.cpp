#include <bits/stdc++.h>

using namespace std;

// TC - O(2^(mxn)) -> there are mxn boxes and for every box we"ve 2 options
// SC - O(path length) -> O(m-1)+O(n-1) -- recursion calls

int uniquePaths(int m, int n) {
	// Reached at the end point destination
	if (m == 0 and n == 0)
		return 1;
	// crossed the boundary, backtrack
	if (m < 0 or n < 0)
		return 0;
	// uniquePaths(m,n) -> total no. of unique paths from (0,0) -> (m-1,n-1)
	int up = uniquePaths(m - 1, n);
	int left = uniquePaths(m, n - 1);
	return up + left;
}

// TC - O(mxn) -> removed overlapping subproblems each state is calculated only once
// SC - O(path length) -> O(m-1)+O(n-1) -- recursion calls + O(mxn) - dp array

int uniquePaths(int m, int n, vector<vector<int>> &dp) {
	if (m == 0 and n == 0)
		return 1;
	// crossed the boundary, backtrack
	if (m < 0 or n < 0)
		return 0;
	if (dp[m][n] != -1)
		return dp[m][n];
	// uniquePaths(m,n) -> total no. of unique paths from (0,0) -> (m-1,n-1)
	int up = uniquePaths(m - 1, n);
	int left = uniquePaths(m, n - 1);
	return dp[m][n] = up + left;
}

// TC - O(mxn)
// SC - O(mxn)
// Logic - If we are on first row or first column we do have only 1 way to reach to the final destination

int uniquePathsTabulation(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if (row == 0 or col == 0) {
				dp[row][col] = 1;
			}
			else {
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		}
	}
	return dp[m - 1][n - 1];
}

int uniquePathsTabulation_2(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if (row == 0 and col == 0) {
				dp[row][col] = 1;
			}
			else {
				int up = 0, left = 0;
				if (row > 0)
					up = dp[row - 1][col];
				if (col > 0)
					left = dp[row][col - 1];
				dp[row][col] = up + left;
			}
		}
	}
	return dp[m - 1][n - 1];
}

int uniquePathsSpaceOptimization(int m, int n) {
	// Write your code here.
	// vector<int> prev_row(n, 0);
	// for (int row = 0; row < m; row++) {
	// 	vector<int> current_row(n, 0);
	// 	for (int col = 0; col < n; col++) {
	// 		if (row == 0 and col == 0) {
	// 			current_row[col] = 1;
	// 		}
	// 		else {

	// 			current_row[col] = prev_row[col] + current_row[col - 1];
	// 		}
	// 		prev_row = current_row;
	// 	}
	// }
	// return prev_row[n - 1];
	vector<int> prev_row(n, 0);
	for (int row = 0; row < m; row++) {
		vector<int> current_row(n, 0);
		for (int col = 0; col < n; col++) {
			if (row == 0 and col == 0) {
				current_row[col] = 1;
			}
			else {
				int up = 0, left = 0;
				if (row > 0)
					up = prev_row[col];
				if (col > 0)
					left = current_row[col - 1];
				current_row[col] = up + left;
			}
		}
		prev_row = current_row;
	}
	return prev_row[n - 1];
}





int main() {
	int T;
	cin >> T;
	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> dp(m, vector<int>(n, -1));
		cout << uniquePaths(m - 1, n - 1) << endl;
		cout << uniquePaths(m - 1, n - 1, dp) << endl;
		cout << uniquePathsTabulation(m, n) << endl;
		cout << uniquePathsSpaceOptimization(m, n) << endl;
	}
	return 0;
}