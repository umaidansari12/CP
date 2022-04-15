#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find unit area of the largest region of 1s.

    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};

    bool isSafe(int row, int col, int n, int m) {
        if (row >= 0 and row<n and col >= 0 and col < m)
            return true;
        return false;
    }

    int dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited) {
        visited[row][col] = 1;
        int count = 1;
        for (int i = 0; i < 8; i++) {
            int nxtRow = row + dx[i];
            int nxtCol = col + dy[i];
            if (isSafe(nxtRow, nxtCol, n, m) and grid[nxtRow][nxtCol] == 1 and !visited[nxtRow][nxtCol])
            {
                count += dfs(nxtRow, nxtCol, n, m, grid, visited);
            }
        }
        return count;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] and !visited[i][j]) {
                    ans = max(ans, dfs(i, j, n, m, grid, visited));
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