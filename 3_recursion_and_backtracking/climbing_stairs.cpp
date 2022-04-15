class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

    }
    int climbingStairs(int n, vector<int>& dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 0;
        }
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = climbingStairs(n - 1, dp) + climbingStairs(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        climbingStairs(n, dp);
        return dp[n];
    }
};