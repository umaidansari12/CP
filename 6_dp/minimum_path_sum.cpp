int minCost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] +
               min(minCost(cost, m - 1, n - 1),
                   minCost(cost, m - 1, n),
                   minCost(cost, m, n - 1));
}


int minCost(int cost[R][C], int m, int n)
{
    int i, j;

    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memory to save space. The following line is
    // used to keep the program simple and make it working on all compilers.
    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1],
                           tc[i - 1][j],
                           tc[i][j - 1]) + cost[i][j];

    return tc[m][n];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int minSum = INT_MAX;
                if ((i - 1) >= 0)
                    minSum = min(minSum, dp[i - 1][j]);
                if ((j - 1) >= 0)
                    minSum = min(minSum, dp[i][j - 1]);
                dp[i][j] = minSum + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};