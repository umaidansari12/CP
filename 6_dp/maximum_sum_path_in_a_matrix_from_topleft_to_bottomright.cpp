#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void maxPath(vector<vector<int>> a, int r, int c, int n, int m, int sum, int &ans)
{
	ans = max(ans, sum);
	if ((r) < n and (c + 1) < m)
		maxPath(a, r , c + 1, n, m, sum + a[r][c + 1], ans);
	if ((r + 1) < n and (c) >= 0)
		maxPath(a, r + 1, c , n, m, sum + a[r + 1][c], ans);
}
void maxPath(vector<vector<int>>&a, int n, int m, int sum, int &ans)
{
	if (n == 0 or m == 0)
		return ;
	ans = max(ans, sum);
	maxPath(a, n, m - 1, sum + a[n - 1][m - 1], ans);
	maxPath(a, n - 1, m, sum + a[n - 1][m - 1], ans);
}

int maxPath(vector<vector<int>>&a, int n, int m)
{
	vector<vector<int>> dp(n, vector<int> (m, 0));
	dp[0][0] = a[0][0];
	for (int i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + a[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int maxSum = INT_MIN;
			if ((j - 1) >= 0)
				maxSum = max(maxSum, dp[i][j - 1]);
			if ((i - 1) >= 0)
				maxSum = max(maxSum, dp[i - 1][j]);
			dp[i][j] = a[i][j] + maxSum;
		}
	}
	return dp[n - 1][m - 1];
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		// int ans = 0;
		// maxPath(a, 0, 0, n, m, a[0][0], ans);
		// cout << ans << endl;
		cout << maxPath(a, n, m) << endl;
	}

	return 0;
}