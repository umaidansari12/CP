#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestIncreasingPathMatrix(vector<vector<int>> &a, int n, int m, int x, int y, vector<vector<int>> &dp) {
	if (dp[x][y] != -1)
		return dp[x][y];

	int result = 0;
	if (x == n - 1 and y == m - 1)
		return dp[x][y] = 1;
	if (x == n - 1 or y == m - 1)
		result = 1;
	if (x + 1 < n and a[x][y] < a[x + 1][y])
		result = 1 + longestIncreasingPathMatrix(a, n, m, x + 1, y, dp);
	if (y + 1 < m and a[x][y] < a[x][y + 1])
		result = max(result, 1 + longestIncreasingPathMatrix(a, n, m, x, y + 1, dp));
	return dp[x][y] = result;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		vector<vector<int>> dp(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << longestIncreasingPathMatrix(a, n, m, 0, 0, dp) << endl;

	}

	return 0;
}