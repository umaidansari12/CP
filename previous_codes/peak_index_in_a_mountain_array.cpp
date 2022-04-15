class Solution {
public:
	int peakIndexInMountainArray(vector<int>& nums) {
		int n = nums.size();
		for (int i = 1; i < n - 1; i++)
		{
			if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1])
				return i;
		}
		return 0;
	}
};