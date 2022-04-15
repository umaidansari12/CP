class Solution {
public:
    int res = 0, empty = 1, sx, sy, n, m;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = { -1, 0, 1, 0};
    void dfs(vector<vector<int>> &grid, int x, int y) {
        if (x<0 or x >= n or y<0 or y >= m or grid[x][y] < 0)
            return;
        if (grid[x][y] == 2) {
            if (empty == 0)
                res++;
            return;
        }
        grid[x][y] = -2;
        empty--;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(grid, nx, ny);
        }
        grid[x][y] = 0;
        empty++;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    empty++;
                }
                else if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(grid, sx, sy);
        return res;
    }
};