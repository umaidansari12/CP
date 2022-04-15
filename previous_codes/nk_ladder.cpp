#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int nkladders(int n, int k, vector<int>&dp)
{
	if (dp[n] != -1)
		return dp[n];
	if (n == 0)
		return dp[n] = 1;
	if (n < 0)
		return 0;
	int count = 0;
	for (int i = 1; i <= k; i++)
	{
		if (n - i >= 0)
			count += nkladders(n - i, k, dp);
	}
	return dp[n] = count;
}

//O(n*k) we're iterating k steps backward to calculate value of current ladder
//Recurrence Relation = F[n]=F[n-1]+F[n-2]+....+F[n-k];
int nkladdersBottomup(int n, int k)
{
	int dp[n + 1] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		// for (int j = i; j >= (i - k) and j >= 0; j--)
		// {
		// 	dp[i] += dp[j];
		// }
		for (int j = 1; j <= k; j++)
		{
			if (i - j >= 0)
				dp[i] += dp[i - j];
		}
	}
	for (auto i : dp)
		cout << i << " ";
	cout << endl;
	return dp[n];
}

//O(n+k) approach
int nkladdersBottomupOpt(int n, int k)
{
	int dp[n + 1] = {0};
	dp[0] = dp[1] = 1;
	// remove one cell from backward i.e dp[n-k-1] add current window sum stored at dp[n-1] got the window sum now include the forward element which is at index dp[n-1]
	//Recurrence Relation for optimised approach is based on prefixsum and calculating sum of windows
	// F[n] = F[n-1]//adding previous window sum - F[n-(k+1)] equivalent to F[n-k-1] + F[n-1] to calculate prefix sum
	//to handle the case where (n-k-1) is -ve either we can divide the solution into two parts
	// for i<=k f[i]=2*f[i-1] or it can be calculated by prefixsum
	// for i>k f[i]=2*f[i-1]-f[n-k-1];
	/*for (int i = 2; i <= k; i++)
	{
		dp[i] = 2 * dp[i - 1];
	}
	for (int i = k + 1; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
	}*/
	for (int i = 2; i <= n; i++)
	{
		if (i <= k)
		{
			dp[i] = 2 * dp[i - 1];
		}
		else
		{
			dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
		}
	}
	return dp[n];
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
		int n, k;
		cin >> n >> k;
		cout << nkladdersBottomupOpt(n, k) << endl;
	}


	return 0;
}