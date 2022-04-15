class Solution {
public:
    int solve(vector<int>&a, int i, int n, int sum)
    {
        if (sum == 0)
        {
            return 1;
        }
        int count = 0;
        for (int l = i; l < n; l++)
        {
            if (sum - a[l] >= 0)
            {
                count += solve(a, i, n, sum - a[l]);
            }
        }
        return count;


    }
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0, i = 0, n = nums.size();
        return solve(nums, i, n, target);

    }
};

class Solution {
public:
    int solve(vector<int>&a, int i, int n, int sum)
    {
        if (sum == 0)
        {
            return 1;
        }
        int count = 0;
        for (int l = i; l < n; l++)
        {
            if (sum - a[l] >= 0)
            {
                count += solve(a, i, n, sum - a[l]);
            }
        }
        return count;


    }
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0, i = 0, n = nums.size();
        return solve(nums, i, n, target);

    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int n : nums)
            {
                if (i >= n)
                    dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};