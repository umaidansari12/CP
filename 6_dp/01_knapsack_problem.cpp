#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
	//Function to return max value that can be put in knapsack of capacity W.
	int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
	{
		if (dp[n][W] != -1)
			return dp[n][W];
		if (n == 0 or W == 0)
			return 0;
		if (wt[n - 1] <= W)
		{
			dp[n][W] = max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1, dp), solve(W, wt, val, n - 1, dp));
		}
		else
		{
			dp[n][W] = solve(W, wt, val, n - 1, dp);
		}
		return dp[n][W];
	}
	int knapSackTopDown(int W, int wt[], int val[], int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
		return helper(W, wt, val, n, dp);
	}
	int knapSack(int W, int wt[], int val[], int n)
	{
		// Your code here
		if (n == 0 or W == 0)
			return 0;
		if (wt[n - 1] <= W)
		{
			return max((val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1)), knapSack(W, wt, val, n - 1));
		}
		else if (wt[n - 1] > W)
			return knapSack(W, wt, val, n - 1);
		return 0;

	}
	int knapSackBottomUp(int W, int wt[], int val[], int n)
	{
		// Your code here
		int dp[n + 1][W + 1];
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (i == 0 or j == 0)
					dp[i][j] = 0;
				else
				{
					if (wt[i - 1] <= j)
					{
						dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
					}
					else
					{
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}
		return dp[n][W];
	}
};

// { Driver Code Starts.

int main()
{
	//taking total testcases
	int t;
	cin >> t;
	while (t--)
	{
		//reading number of elements and weight
		int n, w;
		cin >> n >> w;

		int val[n];
		int wt[n];

		//inserting the values
		for (int i = 0; i < n; i++)
			cin >> val[i];

		//inserting the weights
		for (int i = 0; i < n; i++)
			cin >> wt[i];
		Solution ob;
		//calling method knapSack()
		cout << ob.knapSack(w, wt, val, n) << endl;

	}
	return 0;
}  // } Driver Code Ends