#include <bits/stdc++.h>

using namespace std;

/*
TC -
2 ^ 1 + 2 + 3 + ..... + n (no. of rows and no. of elements in every column and for every column we have 2 options)

SC -
Stack space - length of rows - O(N)

memoization -
TC - O(NxN) - not exactly NxN it will be summmation of number of columns present in every row
SC - O(N) -> Recursion stack space
*/

int minimumPathSum(vector<vector<int>>& triangle, int n, int col) {
	// Write your code here.
	if (n == 0 and col == 0) {
		// cout << triangle[n][col] << "<>" << triangle[n][n] << endl;
		return triangle[n][col];
	}
	if (n < 0 or col>n or col < 0)
		return 1e9;
	// cout << n << "-" << col << "-" << triangle[n][col] << "\n";
	int up = triangle[n][col] + minimumPathSum(triangle, n - 1, col);
	int left_up = triangle[n][col] + minimumPathSum(triangle, n - 1, col - 1);
	// cout << up << "<>" << left_up << "\n";
	return min(left_up, up);
}

int minimumPathSum(vector<vector<int>>& triangle, int row, int col, int n) {
	// Write your code here.
	// cout << "-" << row << "-" << endl;
	if (row == (n - 1)) {
		// cout << triangle[n][col] << "<>" << triangle[n][n] << endl;
		// cout << "<" << triangle[row][col] << ">" << endl;
		return triangle[row][col];
	}
	// if (row > n or col > n or col < 0)
	// return 1e9;
	// cout << row << "-" << col << "-" << triangle[row][col] << "\n";
	int down = triangle[row][col] + minimumPathSum(triangle, row + 1, col, n);
	int down_diagonal = triangle[row][col] + minimumPathSum(triangle, row + 1, col + 1, n);
	// cout << up << "<>" << left_up << "\n";
	return min(down, down_diagonal);
	// return 0;
}

// TC - O(NxN) - memoization
// SC - O(N) (recursion stack space) + O(NxN) (dp array)

int helper(vector<vector<int>> &triangle, int row, int col, int n, vector<vector<int>> &dp) {
	if (row == n - 1)
		return triangle[row][col];
	if (dp[row][col] != -1)
		return dp[row][col];

	int down = triangle[row][col] + helper(triangle, row + 1, col, n, dp);
	int down_diagonal = triangle[row][col] + helper(triangle, row + 1, col + 1, n, dp);

	return dp[row][col] = min(down, down_diagonal);
}

int minimumPathSumMemo(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return helper(triangle, 0, 0, n, dp);
}

int helper(vector<vector<int>> &triangle, int row, int col, int n) {
	if (row == n - 1)
		return triangle[row][col];
	int down = triangle[row][col] + helper(triangle, row + 1, col, n);
	int down_diagonal = triangle[row][col] + helper(triangle, row + 1, col + 1, n);

	return min(down, down_diagonal);
}

int minimumPathSumRecur(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	return helper(triangle, 0, 0, n);
}

int minimumPathSumTabulation(vector<vector<int>>& triangle, int n) {
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0) {
				dp[i][j] = triangle[i][j];
			}
			else {
				int up = INT_MAX, up_diagonal = INT_MAX;
				if (j > 0) {
					up_diagonal = dp[i - 1][j - 1];
				}
				if (j != i) {
					up = dp[i - 1][j];
				}
				dp[i][j] = triangle[i][j] + min(up, up_diagonal);
			}
		}
	}
	int answer = INT_MAX;
	for (int j = 0; j < n; j++) {
		answer = min(answer, dp[n - 1][j]);
	}
	return answer;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i].resize(i + 1);
			for (int j = 0; j <= i; j++) {
				cin >> arr[i][j];
				// cout << arr[i][j] << " ";
			}
			// cout << endl;
		}
		// int ans = INT_MAX;
		// for (int i = 0; i < n; i++) {
		// 	ans = min(ans, minimumPathSum(arr, n - 1, i));
		// 	cout << "(" << ans << ")" << endl;
		// }

		// cout << ans << endl;
		cout << minimumPathSum(arr, 0, 0, n) << endl;
		cout << minimumPathSumTabulation(arr, n) << endl;
	}
	return 0;
}

/*

3
1
-10
4
1
2 3
3 6 7
8 9 6 10
4
2
3 4
6 5 7
4 1 8 3

*/