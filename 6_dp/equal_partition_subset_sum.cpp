// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution {
public:
	int equalPartitionBottomUp(int N, int arr[])
	{
		// code here
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i];
		if (sum % 2)
			return 0;
		vector<vector<int>> dp(N + 1, vector<int>((sum / 2) + 1, -1));
		for (int i = 0; i <= N; i++)
		{
			for (int j = 0; j <= (sum / 2); j++)
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
					else if (arr[i - 1] > j)
					{
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}
		return dp[N][sum / 2];
	}
	bool isSubsetSum(int N, int arr[], int sum, vector<vector<int>> &dp)
	{
		if (sum == 0)
			return true;
		if (N == 0)
			return false;
		if (dp[N][sum] != -1)
			return dp[N][sum];
		if (arr[N - 1] <= sum)
			return dp[N][sum] = isSubsetSum(N - 1, arr, sum - arr[N - 1], dp) or isSubsetSum(N - 1, arr, sum, dp);
		else if (arr[N - 1] > sum)
			return dp[N][sum] = isSubsetSum(N - 1, arr, sum, dp);
	}
	int equalPartition2(int N, int arr[])
	{
		// code here
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i];
		if (sum % 2)
			return 0;
		vector<vector<int>> dp(N + 1, vector<int>((sum / 2) + 1, -1));
		return isSubsetSum(N, arr, sum / 2, dp);
	}
	bool isSubsetSum(int N, int arr[], int sum)
	{
		if (sum == 0)
			return true;
		if (N == 0)
			return false;
		if (arr[N - 1] <= sum)
			return isSubsetSum(N - 1, arr, sum - arr[N - 1]) or isSubsetSum(N - 1, arr, sum);
		else if (arr[N - 1] > sum)
			return isSubsetSum(N - 1, arr, sum);
	}
	int equalPartition1(int N, int arr[])
	{
		// code here
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i];
		if (sum % 2)
			return 0;
		return isSubsetSum(N, arr, sum / 2);
	}
	int solve(int *a, int n, int sum, int i, vector<vector<int>>&dp)
	{
		if (sum == 0)
			return 1;
		if (i >= n || sum < 0)
			return 0;
		if (dp[i][sum] != -1)
			return dp[i][sum];
		return dp[i][sum] = solve(a, n, sum - a[i], i + 1, dp) || solve(a, n, sum, i + 1, dp);
	}
	int equalPartition(int N, int arr[])
	{
		// code here
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr[i];
		sum /= 2;
		vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
		return solve(arr, N, sum, 0, dp);
	}
};



// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int arr[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		Solution ob;
		if (ob.equalPartition(N, arr))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}  // } Driver Code Ends