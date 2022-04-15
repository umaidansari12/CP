class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k == 0)
			return false;
		int i = 0, j = 0, curr_sum = nums[0];
		while (j < n - 1)
		{
			if (curr_sum + nums[j + 1] < k)
			{
				j++;
				curr_sum += nums[j];
			}
			else if (curr_sum + nums[j + 1] % k == 0)
			{
				return true;
			}
			else
			{
				curr_sum -= nums[i++];
			}
		}
		return false;
	}
};