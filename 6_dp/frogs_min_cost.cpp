#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(vector<int>&heights, int idx)
{
	if (idx < 0)
		return INT_MAX;
	if (idx == 0)
		return 0;
	if (idx == 1)
		return abs(heights[1] - heights[0]);

	int ans = 0;
	if (idx - 1 >= 0 and idx - 2 >= 0) {
		int height1 = abs(heights[idx] - heights[idx - 1]);
		int height2 = abs(heights[idx] - heights[idx - 2]);
		ans = min(solve(heights, idx - 1) + height1, solve(heights, idx - 2) + height2);
	}
	else
	{
		int height1 = abs(heights[idx] - heights[idx - 1]);
		ans = min(ans, solve(heights, idx - 1) + height1);
	}

	return ans;
}

int getMinCost(vector<int>&heights, int n)
{
	vector<int> dp(n, 0);
	dp[0] = 0;
	dp[1] = abs(heights[1] - heights[0]);
	for (int i = 2; i < n; i++)
	{

		int op1 = abs(heights[i] - heights[i - 1]);
		int op2 = abs(heights[i] - heights[i - 2]);
		dp[i] = min(dp[i - 1] + op1, dp[i - 2] + op2);

	}
	return dp[n - 1];
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
		int n, cost = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << getMinCost(a, n) << endl;
	}


	return 0;
}