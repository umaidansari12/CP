#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int GridUniquePaths(int m, int n, int i, int j)
{
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i >= n || j >= m)
		return 0;
	int left = GridUniquePaths(m, n, i + 1, j);
	int right = GridUniquePaths(m, n, i, j + 1);
	return left + right;
}
int DpGridUniquePaths(vector<vector<int>> &dp, int m, int n, int i, int j)
{
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i >= n || j >= m)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	else if (dp[i][j] == 0) return dp[i][j] = DpGridUniquePaths(dp, m, n, i + 1, j) + DpGridUniquePaths(dp, m, n, i, j + 1);
}

int uniquePaths(int m, int n) {
	int N = m + n - 2;
	int r = m - 1;
	double res = 1;
	for (int i = 1; i <= r; i++)
	{
		res *= (N - r + i);
		res /= i;
	}
	return (int)res;
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
		int m, n;
		cin >> m >> n;
		vector <vector<int>> dp(n, vector<int> (m, -1));
		cout << DpGridUniquePaths(dp, m, n, 0, 0) << endl;
	}


	return 0;
}