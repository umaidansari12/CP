#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// if character at ith and jth index match we dont do anything and recur for i-1 and j-1
// else 3 cases
// if insert decrease the size of 2nd string by 1 because we are inserting a character
// if remove decrease the size of 1st string by 1 because we are removing a character
// if replacing decrease the size of 1st string and 2nd string by 1 because we are replacing a character
class Solution {
public:
	int helper(string &s, string &t, int m, int n)
	{
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		if (s[m - 1] == t[n - 1])
			return helper(s, t, m - 1, n - 1);
		else
		{
			return 1 + min(helper(s, t, m, n - 1), min(helper(s, t, m - 1, n), helper(s, t, m - 1, n - 1)));
		}
		return 0;
	}

	int editDistanceRecur(string s, string t) {
		// Code here
		int m = s.size(), n = t.size();
		return helper(s, t, m, n);
	}
	int solve(string &s, string &t, int m, int n, vector<vector<int>> &dp)
	{
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		if (dp[m][n] != -1)
			return dp[m][n];
		if (s[m - 1] == t[n - 1])
		{
			if (dp[m - 1][n - 1] == -1)
				return dp[m][n] = solve(s, t, m - 1, n - 1, dp);
			else
				return dp[m][n] = dp[m - 1][n - 1];
		}
		else
		{
			int m1, m2, m3;
			if (dp[m - 1][n] != -1)
				m1 = dp[m - 1][n];
			else
				m1 = solve(s, t, m - 1, n, dp);
			if (dp[m][n - 1] != -1)
				m2 = dp[m][n - 1];
			else
				m2 = solve(s, t, m, n - 1, dp);
			if (dp[m - 1][n - 1] != -1)
				m3 = dp[m - 1][n - 1];
			else
				m3 = solve(s, t, m - 1, n - 1, dp);
			return dp[m][n] = 1 + min(m1, min(m2, m3));
		}
	}

	int editDistanceTopDown(string s, string t) {
		// Code here
		int m = s.size(), n = t.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
		return solve(s, t, m, n, dp);
	}
	int TopDownHelper(string &s, string &t, int m, int n, vector<vector<int>> &dp)
	{
		if (m == 0)
			return n;
		if (n == 0)
			return m;
		if (dp[m][n] != -1)
			return dp[m][n];
		if (s[m - 1] == t[n - 1])
		{
			return dp[m][n] = TopDownHelper(s, t, m - 1, n - 1, dp);
		}
		else
		{
			int m1, m2, m3;
			m1 = TopDownHelper(s, t, m - 1, n, dp);
			m2 = TopDownHelper(s, t, m, n - 1, dp);
			m3 = TopDownHelper(s, t, m - 1, n - 1, dp);
			return dp[m][n] = 1 + min(m1, min(m2, m3));
		}
	}

	int editDistance(string s, string t) {
		// Code here
		int m = s.size(), n = t.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
		return TopDownHelper(s, t, m, n, dp);
	}
	int editDistanceBottomUp(string s, string t) {
		// Code here
		int m = s.size(), n = t.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 and j == 0)
					dp[i][j] = 0;
				else if (i == 0)
					dp[i][j] = j;
				else if (j == 0)
					dp[i][j] = i;
				else
				{
					if (s[i - 1] == t[j - 1])
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
				}
			}
		}
		return dp[m][n];
	}
};

class SolutionLeetCode {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 and j == 0)
					dp[i][j] = 0;
				else if (i == 0)
					dp[i][j] = j;
				else if (j == 0)
					dp[i][j] = i;
				else
				{
					if (word1[i - 1] == word2[j - 1])
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
					}
				}
			}
		}
		return dp[m][n];


	}
};
// { Driver Code Starts.
int main() {
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;
		Solution ob;
		int ans = ob.editDistance(s, t);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends