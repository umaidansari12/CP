#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*Try to come up with a DP solution.

What can be possible states and transition in matrix?
Dynamic programming FTW.
If you look at a cell, there are atmost 2 ways to reach it. From the cell left and up.
If the cell does not have an obstacle, then the number of ways to reach this cell would
be the summation of the number of ways to reach the immediate neighbors preceding it ( left and up ).*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int uniquePaths[m + 1][n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                uniquePaths[i][j] = 0;
                if (obstacleGrid[i][j]) continue;
                if (i == 0 && j == 0) uniquePaths[i][j] = 1;
                if (i > 0) uniquePaths[i][j] += uniquePaths[i - 1][j];
                if (j > 0) uniquePaths[i][j] += uniquePaths[i][j - 1];
            }
        }
        return uniquePaths[m - 1][n - 1];
    }
};

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    dp[0][0] = A[0][0] ^ 1;
    for (int i = 1; i < A.size(); ++i) {
        if (!A[i][0]) dp[i][0] += dp[i - 1][0];
        else dp[i][0] = 0;
    }
    for (int i = 1; i < A[0].size(); ++i) {
        if (!A[0][i]) dp[0][i] += dp[0][i - 1];
        else dp[0][i] = 0;
    }
    for (int i = 1; i < A.size(); ++i)
        for (int j = 1; j < A[0].size(); ++j) {
            if (A[i][j]) continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    return dp[(int)A.size() - 1][(int)A[0].size() - 1];
}


int solve(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<int>>&dp)
{
    if (i == n - 1 && j == m - 1 && a[i][j] == 0)
        return 1;
    if (i >= n || j >= m || a[i][j] == 1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = solve(i, j + 1, n, m, a, dp) + solve(i + 1, j, n, m, a, dp);
}


int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), i = 0, j = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, n, m, A, dp);
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    return 0;
}