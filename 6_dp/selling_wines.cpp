#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int sellingWines(vector<int>&a, int left, int right, int sum, int year)
{
	if (left > right)
		return sum;

	return max(sellingWines(a, left + 1, right, sum + (a[left] * year), year + 1), sellingWines(a, left, right - 1, sum + (a[right] * year), year + 1));
}

int sellingWinesTopDown(vector<int>&prices, int left, int right, int year, vector<vector<int>>&dp)
{
	if (left > right)
		return 0;
	if (dp[left][right] != 0)
		return dp[left][right];
	int pick_left = (year * prices[left]) + sellingWinesTopDown(prices, left + 1, right, year + 1, dp);
	int pick_right = (year * prices[right]) + sellingWinesTopDown(prices, left, right - 1, year + 1, dp);
	return dp[left][right] = max(pick_right, pick_left);
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<vector<int>> dp(n, vector<int>(n, 0));
		//cout << sellingWines(a, 0, n - 1, 0, 1);
		cout << sellingWinesTopDown(a, 0, n - 1, 1, dp) << endl;
		for (auto i : dp)
		{
			for (auto j : i)
				cout << j << " ";
			cout << endl;
		}
	}


	return 0;
}