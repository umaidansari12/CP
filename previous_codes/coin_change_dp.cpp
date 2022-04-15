#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
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
	int solve(vector<int>c, int s, int m, int i, vector<vector<int>>&dp)
	{
		if (i >= m || s < 0)
			return 0;
		if (s == 0)
			return 1;
		if (dp[i][s] != -1)
			return dp[i][s];
		return dp[i][s] = solve(c, s - c[i], m, i, dp) + solve(c, s, m, i + 1, dp);
	}
	int change(int amount, vector<int>& coins) {
		if (coins.size() == 0 && amount == 0)
			return 1;
		if (coins.size() == 0)
			return 0;
		vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
		return solve(coins, amount, coins.size(), 0, dp);

	}
};

//right but tle
void countWays(vector<int>&a, int s, int m, int i, vector<int>&r, vector<vector<int>>&res)
{
	if (s < 0)
		return;
	if (s == 0)
	{
		res.push_back(r);
		//r.clear();
		return;
	}
	while (i < m)
	{
		r.push_back(a[i]);
		countWays(a, s - a[i], m, i, r, res);
		i++;
		r.pop_back();
	}
	return;
}
long long coinChangeDp(vector<int>&a, int n, int m, int ind)
{
	if (n == 0)
		return 1;
	if (ind >= m || n < 0)
		return 0;
	return coinChangeDp(a, n - a[ind], m, ind) + coinChangeDp(a, n, m, ind + 1);
}
long long int count(vector<int>&a, int n, int m)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (m <= 0 && n >= 1)
		return 0;
	return count(a, n - a[m - 1], m) + count(a, n, m - 1);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		for (int i = 0; i < m; i++)
			cin >> a[i];
		vector<int> r;
		vector<vector<int>> res;
		int i = 0;
		/*countWays(a, n, m, i, r, res);
		for (auto i : res)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}*/
		cout << count(a, n, m) << endl;
	}


	return 0;
}