#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
	int minDifferenceBottomUp(int arr[], int n)  {
		// Your code goes here
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
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
						dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];
					}
					else if (arr[i - 1] >= j)
					{
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}
		int ans = INT_MAX;
		for (int i = 0; i <= (sum / 2); i++)
		{
			if (dp[n][i] == 1)
			{
				ans = min(ans, sum - (2 * i));
			}
		}
		return ans;
	}
	int solve(int arr[], int n, int s1, int s2, vector<vector<int>> &dp)
	{
		if (n < 0)
			return abs(s1 - s2);
		if (dp[n][s1] != -1)
			return dp[n][s1];
		return dp[n][s1] = min(solve(arr, n - 1, s1, s2, dp), solve(arr, n - 1, s1 + arr[n], s2 - arr[n], dp));
	}
	int minDiffernce1(int arr[], int n)
	{
		// Your code goes here
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		return solve(arr, n - 1, 0, sum, dp);
	}
	int solve(int n, int s1, int sum, int arr[], vector<vector<int>>&dp)
	{
		if (n == 0)
			return abs(sum - (2 * s1));
		if (dp[n][s1] != -1)
			return dp[n][s1];
		return dp[n][s1] = min(solve(n - 1, s1 + arr[n - 1], sum, arr, dp), solve(n - 1, s1, sum, arr, dp));
	}
	int minDifference(int arr[], int n)  {
		// Your code goes here
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
		return solve(n, 0, sum, arr, dp);
	}
};


// { Driver Code Starts.
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.minDifference(a, n) << "\n";

	}
	return 0;
}  // } Driver Code Ends