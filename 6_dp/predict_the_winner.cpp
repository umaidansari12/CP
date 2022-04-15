class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int dp[nums.size()][nums.size()];
        for (int gap = 0; gap < nums.size(); gap++)
        {
            for (int i = 0, j = gap; j < nums.size(); i++, j++)
            {
                if (gap == 0)
                    dp[i][j] = nums[i];
                else if (gap == 1)
                    dp[i][j] = max(nums[i], nums[j]);
                else
                {
                    int val1 = nums[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                    int val2 = nums[j] + min(dp[i][j - 2], dp[i + 1][j - 1]);
                    dp[i][j] = max(val1, val2);
                }
            }
        }
        //cout<<dp[0][nums.size()-1]<<endl;
        return (sum - dp[0][nums.size() - 1]) <= dp[0][nums.size() - 1];
    }
};