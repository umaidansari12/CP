class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), end = 0, start = 0, ans = INT_MAX, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans, i - start + 1);
                sum -= nums[start++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), end = 0, start = 0, ans = INT_MAX, sum = 0;
        while (end < n)
        {
            while (sum < target && end < n)
                sum += nums[end++];
            while (sum >= target && start < n)
            {
                sum -= nums[start++];
                ans = min(ans, end - start + 1);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};