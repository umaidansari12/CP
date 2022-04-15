#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define mod 1000000007

int countOfSubset(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (arr[n - 1] <= sum)
		return ((countOfSubset(arr, n - 1, sum - arr[n - 1]) % mod) + (countOfSubset(arr, n - 1, sum) % mod));
	else if (arr[n - 1] > sum)
		return ((countOfSubset(arr, n - 1, sum) % mod));
	return 0;
}

int countOfSubsetBottomUp(int arr[], int n, int sum)
{
	// Your code goes here
	int mod = 1000000007;
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (i == 0 and j == 0)
			{
				dp[i][j] = 1;
			}
			else if (i == 0)
			{
				dp[i][j] = 0;
			}
			else if (j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				if (arr[i - 1] <= j)
				{
					dp[i][j] = (((dp[i - 1][j - arr[i - 1]]) % mod) + ((dp[i - 1][j]) % mod)) % mod;
				}
				else if (arr[i - 1] > j)
				{
					dp[i][j] = dp[i - 1][j] % mod;
				}
			}
		}
	}
	return dp[n][sum];
}

int countOfSubsetTopDown(int arr[], int n, int sum, vector<vector<int>>&dp)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (dp[n][sum] != -1)
		return dp[n][sum];
	if (arr[n - 1] <= sum)
		return dp[n][sum] = ((countOfSubset(arr, n - 1, sum - arr[n - 1], dp) % mod) + (countOfSubset(arr, n - 1, sum, dp) % mod)) % mod;
	else if (arr[n - 1] > sum)
		return dp[n][sum] = ((countOfSubset(arr, n - 1, sum, dp) % mod));
}
int perfectSum(int arr[], int n, int sum)
{
	// Your code goes here
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
	return countOfSubsetTopDown(arr, n, sum, dp);
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
		int n, sum;
		cin >> n >> sum;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << countOfSubset(a, n, sum) << endl;
	}


	return 0;
}