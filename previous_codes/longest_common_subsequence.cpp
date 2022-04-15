#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int longestCommonSubsequence(string s1, string s2, int x, int y, int i, int j)
{
	if (i == x || j == y)
		return 0;
	else if (s1[i] == s2[j])
		return 1 + longestCommonSubsequence(s1, s2, x, y, i + 1, j + 1);
	else
		return max(longestCommonSubsequence(s1, s2, x, y, i + 1, j), longestCommonSubsequence(s1, s2, x, y, i, j + 1));
}

int lcsr(string s1, string s2, int i, int j, vector<vector<int>>&dp)
{
	if (i == 0 || j == 0)
		return dp[i][j] = 0;
	else if (s1[i] == s2[j])
		return dp[i][j] = 1 + lcsr(s1, s2, i - 1, j - 1, dp);
	else
		return dp[i][j] = max(lcsr(s1, s2, i - 1, j, dp), lcsr(s1, s2, i, j - 1, dp));
}

int lcs(int x, int y, string s1, string s2) {

	// your code here
	vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int len = dp[x][y], j = y, i = x;
	vector<char>res;
	while (len > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			res.push_back(s1[i - 1]);
			len--;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}

	}
	reverse(res.begin(), res.end());
	for (auto i : res)
		cout << i << " ";
	cout << endl;
	return dp[x][y];
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
		string s1, s2;
		cin >> s1 >> s2;
		int x = s1.size(), y = s2.size();
		vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
		//longestCommonSubsequence(s1, s2, s1.size(), s2.size(), 0, 0, dp);
		//lcsr(s1, s2, x, y, dp);
		cout << lcs(x, y, s1, s2) << endl;
		//cout << dp[x][y] << endl;
	}


	return 0;
}