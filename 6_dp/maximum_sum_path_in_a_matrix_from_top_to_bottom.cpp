#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[] = {1, 1};
int dy[] = { -1, 1};

bool isValid(int row, int col, int n, int m)
{
	if ((row >= 0 and row < n) and (col >= 0 and col < m))
		return true;
	return false;
}


int MaxPathSumRecurHelper(vector<vector<int>>&a, int row, int col, int n, int m)
{
	if (row == n - 1)
		return a[row][col];

	int maxSum = INT_MIN;
	for (int i = 0; i < 2; i++)
	{
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];
		if (isValid(nextRow, nextCol, n, m))
			maxSum = max(maxSum, MaxPathSumRecurHelper(a, nextRow, nextCol, n, m));
	}
	return maxSum + a[row][col];
}

int MaxPathSumRecur(vector<vector<int>>&a, int n, int m)
{
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
		ans = max(ans, MaxPathSumRecurHelper(a, 0, i, n, m));
	return ans;
}

int MaxPathSumTopDownHelper(vector<vector<int>>&a, int row, int col, int n, int m, vector<vector<int>>&dp)
{
	if (row == n - 1)
		return a[row][col];

	if (dp[row][col] != INT_MIN)
		return dp[row][col];

	int maxSum = INT_MIN;
	for (int i = 0; i < 2; i++)
	{
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];
		if (isValid(nextRow, nextCol, n, m))
			maxSum = max(maxSum, MaxPathSumTopDownHelper(a, nextRow, nextCol, n, m, dp));
	}
	return dp[row][col] = maxSum + a[row][col];
}

int MaxPathSumTopDown(vector<vector<int>>&a, int n, int m)
{
	int ans = INT_MIN;
	vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
	for (int i = 0; i < n; i++)
		ans = max(ans, MaxPathSumTopDownHelper(a, 0, i, n, m, dp));
	return ans;
}

int MaxPathSumBottomUp(vector<vector<int>>&a, int n, int m)
{
	for (int row = 1; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			int maxValue = INT_MIN;
			if (isValid(row - 1, col - 1, n, m))
				maxValue = max(maxValue, a[row - 1][col - 1]);
			if (isValid(row - 1, col + 1, n, m))
				maxValue = max(maxValue, a[row - 1][col + 1]);
			a[row][col] = a[row][col] + maxValue;
		}
	}
	int ans = INT_MIN;

	for (int i = 0; i < m; i++)
		ans = max(ans, a[n - 1][i]);
	return ans;
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
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}


		cout << MaxPathSumBottomUp(a, n, m) << '\n';

	}



	return 0;
}