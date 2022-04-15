#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find minimum time required to rot all oranges.
    bool isSafe(int i, int j, int row, int col) {
        if (i >= 0 and j >= 0 and i < row and j < col)
            return true;
        return false;
    }
    int dx[4] = { -1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size(), col = grid[0].size(), no = 2, changed = 0;
        while (true) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == no) {
                        for (int k = 0; k < 4; k++) {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if (isSafe(x, y, row, col) and grid[x][y] == 1)
                            {
                                grid[x][y] = grid[i][j] + 1;
                                changed = 1;
                            }
                        }
                    }
                }
            }
            if (!changed)
                break;
            changed = 0;
            no++;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return no - 2;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size(), col = grid[0].size(), no = 2, changed = 0;
        while (true) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (grid[i][j] == no) {
                        if (isSafe(i + 1, j, row, col) and grid[i + 1][j] == 1) {
                            grid[i + 1][j] = grid[i][j] + 1;
                            changed = 1;
                        }
                        if (isSafe(i - 1, j, row, col) and grid[i - 1][j] == 1) {
                            grid[i - 1][j] = grid[i][j] + 1;
                            changed = 1;
                        }
                        if (isSafe(i, j + 1, row, col) and grid[i][j + 1] == 1) {
                            grid[i][j + 1] = grid[i][j] + 1;
                            changed = 1;
                        } if (isSafe(i, j - 1, row, col) and grid[i][j - 1] == 1) {
                            grid[i][j - 1] = grid[i][j] + 1;
                            changed = 1;
                        }
                    }
                }
            }
            if (!changed)
                break;
            changed = 0;
            no++;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return no - 2;
    }
    bool isSafe(int i, int j, int row, int col) {
        if (i >= 0 and j >= 0 and i < row and j < col)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        if (grid.empty())
            return 0;
        queue<pair<int, int>> rotten;
        int row = grid.size(), col = grid[0].size(), total_rotten = 0, days = 0, total = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 0) {
                    total++;
                }
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
        int dx[4] = { -1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!rotten.empty()) {
            int k = rotten.size();
            total_rotten += k;
            while (k--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!isSafe(nx, ny, row, col) or grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if (!rotten.empty())
                days++;
        }
        return total_rotten == total ? days : -1;
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
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends