#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void maxPath(vector<vector<int>> a, int r, int c, int n, int m, int sum, int &ans)
{
	ans = max(ans, sum);
	if ((r + 1) < n and (c + 1) < m)
		maxPath(a, r + 1, c + 1, n, m, sum + a[r + 1][c + 1], ans);
	if ((r + 1) < n and (c - 1) >= 0)
		maxPath(a, r + 1, c - 1, n, m, sum + a[r + 1][c - 1], ans);
}

int maximumPath(int N, vector<vector<int>> Matrix)
{
	// code here
	int n = Matrix.size();
	//vector<vector<int>> dp(n,0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != 0)
			{
				int val = Matrix[i - 1][j];
				if ((j - 1) >= 0)
					val = max(val, Matrix[i - 1][j - 1]);
				if ((j + 1) < n)
					val = max(val, Matrix[i - 1][j + 1]);
				Matrix[i][j] = Matrix[i][j] + val;
			}
		}
	}
	int ans = 0;
	for (auto i : Matrix[n - 1])
		ans = max(ans, i);
	return ans;
}

int maxPathBottomUp(vector<vector<int>>a, int n, int m)
{
	vector<vector<int>> dp(n, vector<int>(n, 0));
	if (n == 1)
		return a[0][0];
	int ans = INT_MIN;
	for (int j = 0; j < n; j++)
		dp[0][j] = a[0][j];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int maxSum = INT_MIN;
			if ((j - 1) >= 0 and maxSum < dp[i - 1][j - 1])
			{
				maxSum = dp[i - 1][j - 1];
			}
			if ((j + 1) < m and maxSum < dp[i - 1][j + 1])
			{
				maxSum = dp[i - 1][j + 1];
			}
			dp[i][j] = maxSum + a[i][j];
		}
	}
	for (int i = 0; i < m; i++)
		ans = max(ans, dp[n - 1][i]);
	return ans;
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
		int n, m, ans = 0;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < m; i++)
		{
			maxPath(a, 0, i, n, m, a[0][i], ans);
		}
		cout << ans << endl;
		cout << maxPathBottomUp(a, n, m) << endl;
	}


	return 0;
}