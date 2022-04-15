#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Approach #1: Sliding Window [Accepted]
Intuition and Algorithm

Every (continuous) increasing subsequence is disjoint, and the boundary of each such subsequence
occurs whenever nums[i-1] >= nums[i].
When it does, it marks the start of a new increasing subsequence at nums[i],
and we store such i in the variable anchor.

For example, if nums = [7, 8, 9, 1, 2, 3], then anchor starts at 0
(nums[anchor] = 7) and gets set again to anchor = 3 (nums[anchor] = 1).
Regardless of the value of anchor, we record a candidate answer of i - anchor + 1,
the length of the subarray nums[anchor], nums[anchor+1], ..., nums[i]; and our answer gets
updated appropriately.

Complexity Analysis

Time Complexity: O(N)O(N), where NN is the length of nums. We perform one loop through nums.

Space Complexity: O(1)O(1), the space used by anchor and ans.
*/

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int n = nums.size(), count = 0, anchor = 0;
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && nums[i - 1] >= nums[i]) anchor = i;
			count = max(count, i - anchor + 1);
		}
		return count;

	}
};
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)


		return 0;
}