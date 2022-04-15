class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int reachable = 0;
		for (int i = 0; i < n; i++)
		{
			if (reachable < i)
				return false;
			reachable = max(reachable, i + nums[i]);
		}
		return true;

	}
};
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, -1);
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			int furthestJump = min(i + nums[i], n - 1);
			for (int j = i + 1; j <= furthestJump; j++)
			{
				if (dp[j] == 1)
				{
					dp[i] = 1;
					break;
				}
			}
		}

		return dp[0] == 1;
	}
};