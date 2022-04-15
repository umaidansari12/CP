#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
	//Function to find the number of islands.
	bool isSafe(vector<int>A[], vector<vector<int>>&vis, int n, int m, int row, int col)
	{
		if (row >= 0 && col >= 0 && row < n && col < m && (A[row][col] && !vis[row][col]))
			return true;
		return false;
	}

	void dfs(vector<int> A[], vector<vector<int>>& vis, int n, int m, int row, int col)
	{
		static int rn[] = { -1, -1, -1, 0, 1, 1, 1, 0};
		static int cn[] = { -1, 0, 1, 1, 1, 0, -1, -1};
		vis[row][col] = 1;
		for (int k = 0; k < 8; k++)
		{
			if (isSafe(A, vis, n, m, row + rn[k], col + cn[k]))
				dfs(A, vis, n, m, row + rn[k], col + cn[k]);
		}
	}
	int findIslands(vector<int> A[], int N, int M) {

		// You.r code here
		vector<vector<int>>vis(N, vector<int>(M, 0));
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (A[i][j] && !vis[i][j])
				{
					dfs(A, vis, N, M, i, j);
					count++;
				}
			}
		}
		return count;
	}

	void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<bool>>&visited, int *dx, int *dy, int n, int m)
	{
		visited[i][j] = true;
		//cout << "hello" << i << " " << j << endl;
		//int count = 1;
		for (int k = 0; k < 8; k++)
		{
			int cx = i + dx[k];
			int cy = j + dy[k];
			if (cx >= 0 and cx<n and cy >= 0 and cy < m)
				if (grid[cx][cy] == '1' and !visited[cx][cy])
					dfs(cx, cy, grid, visited, dx, dy, n, m);
		}

	}
	int numIslands(vector<vector<char>>& grid)
	{
		// Code here
		int n = grid.size(), m = grid[0].size(), ans = 0;
		int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
		int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					ans++;
					dfs(i, j, grid, visited, dx, dy, n, m);
				}
			}
		}
		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans << '\n';
	}
	return 0;
}  // } Driver Code Ends