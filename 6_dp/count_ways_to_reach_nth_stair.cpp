#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countWays(int n)
{
	// your code here
	if (n == 0)
		return 1;
	int l = 0, r = 0;
	if (n - 1 >= 0)
		l = countWays(n - 1);
	if (n - 2 >= 0)
		r = countWays(n - 2);
	return l + r;
}

int solve(int n, vector<int>&dp)
{
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	if (n - 1 >= 0)
		dp[n - 1] = countWays(n - 1);
	if (n - 2 >= 0)
		dp[n - 2] = countWays(n - 2);
	return dp[n] = dp[n - 1] + dp[n - 2];
}
int countWaysTopDown(int n)
{
	// your code here
	vector<int> dp(n + 1, -1);
	return solve(n, dp);

}
int countWaysBottomUp(int n)
{
	// your code here
	int dp[n + 1] = {0};
	int mod = 1e9 + 7;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		if (i - 1 >= 0)
			sum += (dp[i - 1] % mod);
		if (i - 2 >= 0)
			sum += (dp[i - 2] % mod);
		dp[i] = (sum % mod);
	}
	return dp[n] % mod;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin	>> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << countWays(n) << endl;
	}


	return 0;
}