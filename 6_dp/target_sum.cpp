#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int targetSum(int arr[], int s1, int i, int n, int sum)
{
	if (i == n)
	{
		if (sum == s1)
			return 1;
		else
			return 0;
	}
	return targetSum(arr, s1 + arr[i], i + 1, n, sum) + targetSum(arr, s1 - arr[i], i + 1, n, sum);
}

class Solution {
public:
    int solve(vector<int> nums,int i,int n,int sum,int s,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(sum==s)
                return 1;
            else
                return 0;
        }
        if(dp[i][sum+1000]!=-1)
            return dp[i][sum+1000];
        return dp[i][sum+1000]=solve(nums,i+1,n,sum+nums[i],s,dp)+solve(nums,i+1,n,sum-nums[i],s,dp);
    }
    int findTargetSumWaysTopDown(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));
        return solve(nums,0,n,0,target,dp);
    }
};

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, sum;
		cin >> n >> sum;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << targetSum(a, 0, 0, n, sum) << endl;
	}


	return 0;
}