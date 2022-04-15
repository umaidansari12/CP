#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int ans = nums[n - 1] * nums[n - 2] * nums[n - 3];
		ans = max(ans, nums[0] * nums[1] * nums[n - 1]);
		return ans;
//         int n=nums.size(),ans=INT_MIN;

//         for(int i=0;i<n-2;i++)
//         {
//             ans=max(ans,nums[i]*nums[i+1]*nums[i+2]);
//             ans=max(ans,nums[0]*nums[1]*nums[2]);
//         }
//         return ans;
	}
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	return 0;
}