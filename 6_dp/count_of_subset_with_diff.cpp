#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countOfSubset(int arr[], int s1, int s2, int n, int diff)
{
	if (n == 0)
	{
		if ((s1 - s2) == diff)
			return 1;
		else
			return 0;
	}

	return countOfSubset(arr, s1, s2, n - 1, diff) + countOfSubset(arr, s1 + arr[n - 1], s2 - arr[n - 1], n - 1, diff);
}

int countOfSubset(int arr[], int sum, int n, int diff)
{
	int required_sum = (sum + diff) / 2;
	vector<vector<int>> dp(n + 1, vector<int>(required_sum + 1, -1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= required_sum; j++)
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
					dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	return dp[n][required_sum];
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
		int n, diff, sum = 0;
		cin >> n >> diff;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		cout << countOfSubset(a, 0, sum, n, diff) << endl;
	}


	return 0;
}