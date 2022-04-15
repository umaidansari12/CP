class RangeSum {
public:
    vector<int> dp;
    RangeSum(vector<int>& nums) {
        dp.resize(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] + nums[i];
        }
    }

    int total(int i, int j) {
        if (i == 0)
            return dp[j - 1];
        else
            return dp[j - 1] - dp[i - 1];
    }
};