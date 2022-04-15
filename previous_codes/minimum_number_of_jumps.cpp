#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(vector<int>arr, int i, int n, int step, int &ans)
{
	if (i >= n - 1)
	{
		ans = min(ans, step);
		return ;
	}
	if (arr[i] == 0)
		return ;
	for (int j = arr[i]; j >= 1; j--)
	{
		solve(arr, i + j, n, step + 1, ans);
	}
}

int solvedp(vector<int>arr, int i, int n, int step, vector<int>&dp)
{
	if (dp[i] != -1)
		return dp[i];
	if (i >= n - 1)
	{
		dp[i] = min(dp[i], step);
		return dp[i];
	}
	if (arr[i] == 0)
		return INT_MAX;
	for (int j = arr[i]; j >= 1; j--)
	{
		dp[i + j] = min(dp[i + j], solvedp(arr, i + j, n, step + 1, dp));
	}
	return dp[i];
}

int solveBottomUp(vector<int>arr, int n)
{
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (dp[j] != INT_MAX and arr[j] + j >= i)
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[n - 1] != INT_MAX ? dp[n - 1] : -1;
}
int solveOn(vector<int> arr, int n)
{
	int maxReach = a[0];
	int step = a[0];
	int jump = 1;
	if (n == 1)
		return 0;
	else if (arr[0] == 0)
		return -1;
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (i == n - 1)
				return jump;
			maxReach = max(maxReach, i + arr[i]);
			step--;
			if (step == 0)
			{
				jump++;
				if (i >= maxReach)
					return -1;
				step = maxReach - i;
			}
		}
	}


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
		int n, ans = INT_MAX, step = 0;
		cin >> n;
		vector<int> a(n), dp(n, INT_MAX);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << solveBottomUp(a, n) << endl;


	}



	return 0;
}