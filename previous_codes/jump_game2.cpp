class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] != INT_MAX and nums[j] + j >= i)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), maxR = 0, current = 0, jumps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxR = max(maxR, i + nums[i]);
            if (i == current)
            {
                jumps++;
                current = maxR;
            }
        }
        return jumps;
    }
};