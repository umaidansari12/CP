#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

class Solution {
public:
	long long int solve(int i, int j, int m, int n, vector<vector<long long int>>&dp)
	{
		if (i == m - 1 && j == n - 1)
			return 1;
		if (i >= m || j >= n)
			return 0;
		if (dp[i][j] != -1)
			return dp[i][j];
		return dp[i][j] = (solve(i + 1, j, m, n, dp) % 1000000007 + solve(i, j + 1, m, n, dp) % 1000000007) % 1000000007;
	}
	long long int numberOfPaths(int m, int n) {
		// code here
		vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, -1));
		return solve(0, 0, m, n, dp);
	}
};

int GridUniquePaths(vector<vector<int>> &dp, int m, int n)
{
	if (m == 1 || n == 1)
		return 1;
	if (dp[m][n] != -1)
		return dp[m][n];
	else return dp[m][n] = ((GridUniquePaths(dp, m - 1, n) % mod + GridUniquePaths(dp, m, n - 1) % mod) % mod);
}

int main() {
	//code
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;
		vector <vector<int>> dp(m + 1, vector<int> (n + 1, -1));
		cout << GridUniquePaths(dp, m, n) << endl;
	}
	return 0;
}