#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int solve(int i, int j, int m, int n, vector<vector<int>>&a, vector<vector<int>>&dp)
	{
		if (i == m - 1 && j == n - 1)
			return 1;
		if (i >= m || j >= n)
			return 0;
		if (a[i][j] == 1)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		return dp[i][j] = solve(i + 1, j, m, n, a, dp) + solve(i, j + 1, m, n, a, dp);
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		if (obstacleGrid[m - 1][n - 1] == 1)
			return 0;
		return solve(0, 0, m, n, obstacleGrid, dp);

	}
};

int solve(vector<vector<int>>&mat, int i, int j, int m, int n)
{
	if (i == m - 1 && j == n - 1 && mat[i][j] == 0)
		return 1;
	if (i >= m || j >= n)
		return 0;
	if (mat[i][j] == 1)
		return 0;
	return solve(mat, i + 1, j, m, n) + solve(mat, i, j + 1, m, n);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		vector<vector<int>> mat(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
			}
		}
		int r = solve(mat, 0, 0, m, n);
		cout << r << endl;
	}


	return 0;
}