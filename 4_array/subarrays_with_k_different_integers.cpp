class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		int n = nums.size(), cnt = 0;
		for (int i = 0; i < n; i++)
		{
			map<int, int> m;
			for (int j = i; j < n; j++)
			{
				m[nums[j]]++;
				if (m.size() == k)
					cnt++;
				else if (m.size() > k)
					break;
			}
		}
		return cnt;

	}
};

class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		return atMostK(nums, k) - atMostK(nums, k - 1);
	}
	int atMostK(vector<int>&nums, int k)
	{
		int i = 0, res = 0;
		unordered_map<int, int> count;
		for (int j = 0; j < nums.size(); j++)
		{
			if (!count[nums[j]]++)
				k--;
			while (k < 0) {
				if (!--count[nums[i]])
					k++;
				i++;
			}
			res += (j - i + 1);
		}
		return res;
	}
};