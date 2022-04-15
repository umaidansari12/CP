class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int d, int f, int target, vector<vector<int>> &dp) {
        if (d == 0 and target == 0) {
            return 1;
        }
        if (d <= 0 or target <= 0)
        {
            return 0;
        }

        if (dp[d][target] != -1)
            return dp[d][target];

        int res = 0;
        for (int i = 1; i <= f; i++) {
            res = (res % mod + solve(d - 1, f, target - i, dp) % mod) % mod;
        }

        dp[d][target] = res;
        return res;
    }
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, -1));
        return solve(d, f, target, dp);
    }
};