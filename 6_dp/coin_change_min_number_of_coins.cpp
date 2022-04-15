#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution1 {
public:
	int solve(vector<int>coins, int m, int n)
	{
		if (n == 0)
			return 0;
		if (n < 0)
			return INT_MAX;
		int c = INT_MAX;
		for (int i = 0; i < m; i++)
		{
			int res = solve(coins, m, n - coins[i]);
			if (res != INT_MAX)
				c = min(c, res + 1);
		}
		return c;
	}
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			int res = INT_MAX;
			for (int c = 0; c < coins.size(); c++)
			{
				if (i - coins[c] >= 0)
					res = dp[i - coins[c]];
				if (res != INT_MAX)
					dp[i] = min(dp[i], res + 1);
			}
		}
		return dp[amount] == INT_MAX ? -1 : dp[amount];

	}
};
class Solution {

public:
	int minCoins(int coins[], int M, int V)
	{
		// Your code goes here
		vector<vector<int>> dp(M + 1, vector<int>(V + 1, INT_MAX - 1));
		for (int i = 0; i <= V; i++)
		{
			dp[0][i] = INT_MAX - 1;
		}
		for (int i = 0; i <= M; i++)
		{
			dp[i][0] = 0;
		}
		for (int i = 1; i <= V; i++)
		{
			if ((i % coins[0]) == 0)
				dp[1][i] = i / coins[0];
			else
				dp[1][i] = INT_MAX - 1;
		}
		for (int i = 2; i <= M; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (coins[i - 1] <= j)
				{
					dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[M][V] == INT_MAX - 1 ? -1 : dp[M][V];
	}

	int minCoins(int coins[], int M, int V)
	{
		// Your code goes here
		vector<int> dp(V + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= V; i++)
		{
			int res = INT_MAX;
			for (int c = 0; c < M; c++)
			{
				if (i - coins[c] >= 0)
					res = dp[i - coins[c]];
				if (res != INT_MAX)
					dp[i] = min(dp[i], res + 1);
			}
		}
		return dp[V] == INT_MAX ? -1 : dp[V];
	}



};

// { Driver Code Starts.
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int v, m;
		cin >> v >> m;

		int coins[m];
		for (int i = 0; i < m; i++)
			cin >> coins[i];


		Solution ob;
		cout << ob.minCoins(coins, m, v) << "\n";

	}
	return 0;
}
// } Driver Code Ends