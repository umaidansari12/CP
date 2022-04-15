#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int n = nums.size(), count = 0;
		for (int i = 0; i < n; i++)
		{
			long long int pro = 1;
			for (int j = i; j < n; j++)
			{
				pro *= nums[j];
				if (pro < k)
					count++;
			}
		}
		return count;

	}
};

class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k == 0)
			return 0;
		int n = nums.size(), count = 0, left = 0;
		int prod = 1;
		for (int right = 0; right < n; right++)
		{
			prod *= nums[right];
			while (prod >= k && left <= right)
				prod /= nums[left++];
			count += (right - left + 1);
		}
		return count;

	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}