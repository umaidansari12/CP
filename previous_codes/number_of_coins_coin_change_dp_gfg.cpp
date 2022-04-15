#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
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