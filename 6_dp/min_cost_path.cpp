#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isValid(int row, int col, int n, int m)
	{
		if (n >= 0 and n<row and m >= 0 and m < col)
			return true;
		return false;
	}
	// int solve(int row, int col, int n, int m, vector<vector<int>>&grid, int *dx, int *dy)
	// {
	// 	if (n<0 or n >= row )
	// 		return INT_MAX;
	// 	if (m<0 or m >= col)
	// 		return INT_MAX;
	// 	if (n == 0 and m == 0)
	// 		return grid[n][m];
	// 	//cout << n << " " << m << endl;
	// 	int ans = INT_MAX;
	// 	ans = min(ans, min(solve(row, col, n, m - 1, grid, dx, dy), min(solve(row, col, n, m + 1, grid, dx, dy), min(solve(row, col, n - 1, m, grid, dx, dy), solve(row, col, n + 1, m, grid, dx, dy)))));

	// 	return ans + grid[n][m];
	// }

	// int minimumCostPath(vector<vector<int>>& grid)
	// {
	// 	// Code here
	// 	int dx[4] = {0, 0, -1, 1};
	// 	int dy[4] = { -1, 1, 0, 0};
	// 	int n = grid.size(), m = grid[0].size();
	// 	//cout << n << " " << m << endl;
	// 	return solve(n, m, n - 1, m - 1, grid, dx, dy);

	// }
	int minimumCostPath(vector<vector<int>>& grid)
	{
		// Code here
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
		dp[0][0] = grid[0][0];
		p.push({grid[0][0], {0, 0}});
		int dx [] = {0, 0, -1, 1};
		int dy [] = {1, -1, 0, 0};
		while (!p.empty())
		{
			int distCurrent = p.top().first;
			int row = p.top().second.first;
			int col = p.top().second.second;
			p.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextRow = row + dx[i];
				int nextCol = col + dy[i];
				if (isValid(n, m, nextRow, nextCol) and dp[nextRow][nextCol] > (dp[row][col] + grid[nextRow][nextCol]))
				{
					dp[nextRow][nextCol] = dp[row][col] + grid[nextRow][nextCol];
					p.push({dp[nextRow][nextCol], {nextRow, nextCol}});
				}
			}

		}
		return dp[n - 1][m - 1];
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends