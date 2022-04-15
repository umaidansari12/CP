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