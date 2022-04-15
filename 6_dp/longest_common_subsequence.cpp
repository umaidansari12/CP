#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestCommonSubsequence(string s1, string s2, int n, int m)
{
	if (n == 0 or m == 0)
		return 0;
	if (s1[n - 1] == s2[m - 1])
		return 1 + longestCommonSubsequence(s1, s2, n - 1, m - 1);
	else
		return max(longestCommonSubsequence(s1, s2, n, m - 1), longestCommonSubsequence(s1, s2, n - 1, m));
}

int longestCommonSubsequenceTopDown(string s1, string s2, int n, int m, vector<vector<int>>&dp)
{
	if (n == 0 or m == 0)
		return 0;
	if (dp[n - 1][m - 1] != -1)
		return dp[n - 1][m - 1];
	if (s1[n - 1] == s2[m - 1])
		return dp[n - 1][m - 1] = 1 + longestCommonSubsequenceTopDown(s1, s2, n - 1, m - 1, dp);
	else
		return dp[n - 1][m - 1] = max(longestCommonSubsequenceTopDown(s1, s2, n, m - 1, dp), longestCommonSubsequenceTopDown(s1, s2, n - 1, m, dp));
}

class Solution {
public:
	int longestCommonSubsequenceTopDown(string &s1, string &s2, int n, int m, vector<vector<int>>&dp)
	{
		if (n == 0 or m == 0)
			return 0;
		if (dp[n - 1][m - 1] != -1)
			return dp[n - 1][m - 1];
		if (s1[n - 1] == s2[m - 1])
			return dp[n - 1][m - 1] = 1 + longestCommonSubsequenceTopDown(s1, s2, n - 1, m - 1, dp);
		else
			return dp[n - 1][m - 1] = max(longestCommonSubsequenceTopDown(s1, s2, n, m - 1, dp), longestCommonSubsequenceTopDown(s1, s2, n - 1, m, dp));
	}
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
		return longestCommonSubsequenceTopDown(text1, text2, text1.size(), text2.size(), dp);

	}
};

int longestCommonSubsequenceBottomUp(string s1, string s2, int n, int m)
{
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 or j == 0)
				dp[i][j] = 0;
			else
			{
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
	}

	//print lcs
	int i = n, j = m;
	vector<char> res;
	while (i != 0 and j != 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else {
			res.push_back(s1[i - 1]);
			i--;
			j--;
		}
	}
	reverse(res.begin(), res.end());
	for (auto x : res)
		cout << x << " ";
	cout << endl;
	return dp[n][m];
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
		string s1, s2;
		cin >> s1 >> s2;
		vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
		//cout << longestCommonSubsequence(s1, s2, s1.size(), s2.size()) << endl;
		//cout << longestCommonSubsequenceTopDown(s1, s2, s1.size(), s2.size(), dp) << endl;
		cout << longestCommonSubsequenceBottomUp(s1, s2, s1.size(), s2.size()) << endl;
	}


	return 0;
}