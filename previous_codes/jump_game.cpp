#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
	bool solve(vector<int>&nums, int position, int n)
	{
		if (position == n - 1)
			return true;
		int farthestPos = min(position + nums[position], n - 1);
		for (int nextPos = position + 1; nextPos <= farthestPos; nextPos++)
		{
			if (solve(nums, nextPos, n))
				return true;
		}
		return false;
	}
	bool canJump(vector<int>& nums) {
		return solve(nums, 0, nums.size());

	}
};

class SolutionBottomUp {
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
		for (auto i : dp)
			cout << i << " ";
		cout << endl;
		return dp[0] == 1;
	}
};
class SolutionDpTopDownMemo {
public:
	bool solve(vector<int>&nums, int position, int n, vector<int>&dp)
	{
		if (dp[position] != -1)
			return dp[position];
		if (position == n - 1)
			return true;
		int farthestPos = min(position + nums[position], n - 1);
		for (int nextPos = position + 1; nextPos <= farthestPos; nextPos++)
		{
			if (solve(nums, nextPos, n, dp))
			{
				dp[position] = 1;
				return true;
			}

		}
		dp[position] = 0;
		return false;
	}
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, -1);
		return solve(nums, 0, nums.size(), dp);

	}
};
// [2,0] failed case because i'm not calculating the case where my current position takes a step which is beyond the
// the position of last array base case never reached when started by taking 2 steps from
bool solve(vector<int>arr, int i, int n)
{
	if (i >= n - 1) //(i==n-1) this condition was creating buffer overflow
		return true;
	if (arr[i] == 0)
		return false;
	bool ans = false;
	for (int j = arr[i]; j >= 1; j--)
	{
		ans = ans || solve(arr, i + j, n);
	}
	return ans;
}

bool solvedp(vector<int>arr, int i, int n, vector<int>&dp)
{
	if (dp[i] != -1)
		return dp[i];
	if (i >= n - 1)
		return true;
	if (arr[i] == 0)
		return false;
	int ans = 0;
	for (int j = arr[i]; j >= 1; j--)
	{
		ans = ans || solvedp(arr, i + j, n, dp);
	}
	return dp[i] = ans;
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), dp(n, -1);
		SolutionBottomUp ob;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (ob.canJump(a))
			cout << "Yes\n";
		else
			cout << "No\n";
		/*for (auto i : dp)
			cout << i << " ";
		cout << endl;*/
		/*int i = 0, steps = 0;
		while (i < n - 1)
		{
			if(arr[i]==0)
		    return -1;
			i += a[i];
			steps++;
		}
		cout << steps << endl;*/
	}



	return 0;
}