#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	//Function to find unit area of the largest region of 1s.
	int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&visited, int *dx, int *dy, int n, int m)
	{
		visited[i][j] = true;
		//cout << "hello" << i << " " << j << endl;
		int count = 1;
		for (int k = 0; k < 8; k++)
		{
			int cx = i + dx[k];
			int cy = j + dy[k];
			if (cx >= 0 and cx<n and cy >= 0 and cy < m)
				if (grid[cx][cy] == 1 and !visited[cx][cy])
					count += dfs(cx, cy, grid, visited, dx, dy, n, m);
		}
		return count;
	}
	int findMaxArea(vector<vector<int>>& grid) {
		// Code here
		int n = grid.size(), m = grid[0].size(), ans = 0;
		int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
		int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1 && !visited[i][j])
				{
					ans = max(ans, dfs(i, j, grid, visited, dx, dy, n, m));
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends