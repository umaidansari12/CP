#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int subsetsum(int N, int arr[], int sum, vector<vector<int>>&dp)
{
	if (sum == 0)
		return 1;
	if (N == 0)
		return 0;
	if (dp[N][sum] != -1)
		return dp[N][sum];
	if (arr[N - 1] <= sum)
		return dp[N][sum] = subsetsum(N - 1, arr, sum - arr[N - 1], dp) or subsetsum(N - 1, arr, sum, dp);
	else if (arr[N - 1] > sum)
		return dp[N][sum] = subsetsum(N - 1, arr, sum, dp);

}
bool isSubsetSum(int N, int arr[], int sum) {
	// code here
	vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));
	return subsetsum(N, arr, sum, dp);
}

bool isSubsetsum(int N, int arr[], int sum)
{
	if (sum == 0)
		return true;
	if (N == 0)
		return false;
	if (arr[N - 1] <= sum)
		return isSubsetsum(N - 1, arr, sum - arr[N - 1]) or isSubsetsum(N - 1, arr, sum);
	else if (arr[N - 1] > sum)
		return isSubsetsum(N - 1, arr, sum);
}

bool SubsetSum(int i, int N, int arr[], int sum, vector<vector<int>>&dp)
{
	if (sum == 0)
		return true;
	if (i == N)
		return false;
	if (dp[i][sum] != -1)
		return dp[i][sum];
	if (arr[i] <= sum)
	{
		dp[i][sum] = SubsetSum(i + 1, N, arr, sum - arr[i], dp) or SubsetSum(i + 1, N, arr, sum, dp);
	}
	else if (arr[i] > sum)
	{
		dp[i][sum] = SubsetSum(i + 1, N, arr, sum, dp);
	}
}
bool isSubsetSum(int N, int arr[], int sum) {
	// code here
	vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));
	return SubsetSum(0, N, arr, sum, dp);
}

bool isSubsetSumBottomUp(int N, int arr[], int sum) {
	// code here
	bool dp[N + 1][sum + 1];
	for (int i = 0; i <= sum; i++)
		dp[0][i] = false;
	for (int i = 0; i <= N; i++)
		dp[i][0] = true;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= sum; j++)
		{

			if (arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			}
			else if (arr[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[N][sum];
	/*
	bool dp[N+1][sum+1];
	    for(int i=0;i<=N;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0 and j==0)
	            {
	                dp[i][j]=true;
	            }
	            else if(i==0)
	            {
	                dp[i][j]=false;
	            }
	            else if(j==0)
	            {
	                dp[i][j]=true;
	            }
	            else
	            {
	                if(arr[i-1]<=j)
	                {
	                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	                }
	                else if(arr[i-1]>j)
	                {
	                    dp[i][j]=dp[i-1][j];
	                }
	            }
	        }
	    }
	    return dp[N][sum];
	    */
}

bool subsetSum(vector<int> &a, int n, int sum)
{
	if (sum < 0 or n == 0)
		return false;
	if (sum == 0)
		return true;
	return subsetSum(a, n - 1, sum - a[n - 1]) || subsetSum(a, n - 1, sum);
}

bool SubsetSum(int i, int N, int arr[], int sum)
{
	if (i == N or sum < 0)
		return false;
	if (sum == 0)
		return true;

	return SubsetSum(i + 1, N, arr, sum - arr[i]) or SubsetSum(i + 1, N, arr, sum);
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
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (isSubsetSum(a, n, sum))
			cout << "Yes\n";
		else
			cout << "No\n";

	}


	return 0;
}