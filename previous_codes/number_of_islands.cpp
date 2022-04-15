#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isSafe(vector<vector<int>> a, vector<vector<int>> vis, int row, int col, int n, int m)
{
	if (row >= 0 && col >= 0 && row < n && col < m && (a[row][col] && !vis[row][col]))
		return true;
	return false;
}

void dfs(vector<vector<int>> a, vector<vector<int>>&vis, int row, int col, int n, int m)
{
	static int rowNum[] = { -1, -1, -1, 0, 1, 1, 1, 0};
	static int colNum[] = { -1, 0, 1, 1, 1, 0, -1, -1};
	vis[row][col] = 1;
	for (int k = 0; k < 8; k++)
	{
		if (isSafe(a, vis, row + rowNum[k], col + colNum[k], n, m))
			dfs(a, vis, row + rowNum[k], col + colNum[k], n, m);
	}
}



int numberOfIslands(vector<vector<int>> a, int n, int m)
{
	vector < vector <int>> vis(n, vector<int>(m, 0));
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] && !vis[i][j])
			{
				dfs(a, vis, i, j, n, m);
				count++;
			}
		}
	}
	return count;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		cout << numberOfIslands(a, n, m) << endl;
	}


	return 0;
}

/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

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

class Solution {
public:
	bool isSafe(vector<vector<char>>grid, vector<vector<int>>&v, int row, int col, int n, int m)
	{
		if (row >= 0 && row < n && col >= 0 && col < m && (grid[row][col] == '1' && !v[row][col]))
			return true;
		return false;
	}

	void DFS(vector<vector<char>>&grid, int x, int y)
	{
		grid[x][y] = '0';
		if (x > 0 && grid[x - 1][y] == '1')
			DFS(grid, x - 1, y);
		if (x < grid.size() - 1 && grid[x + 1][y] == '1')
			DFS(grid, x + 1, y);
		if (y > 0 && grid[x][y - 1] == '1')
			DFS(grid, x, y - 1);
		if (y < grid[0].size() - 1 && grid[x][y + 1] == '1')
			DFS(grid, x, y + 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;
		int n = grid.size(), m = grid[0].size(), count = 0;

		vector<vector<int>> vis(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1' && !vis[i][j])
				{
					count++;
					DFS(grid, i, j);

				}
			}
		}
		return count;

	}
};