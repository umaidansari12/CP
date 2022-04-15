
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution2
{
public:
	int solve(string s1, string s2, int i, int j, vector<vector<int>>& dp)
	{
		if (i < 0) return j + 1;
		if (j < 0) return i + 1;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (s1[i] == s2[j])
			return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);
		else
		{
			return dp[i][j] = 1 + min(solve(s1, s2, i, j - 1, dp), min(solve(s1, s2, i - 1, j, dp), solve(s1, s2, i - 1, j - 1, dp)));
		}
	}
	int editDistance(string s, string t)
	{
		// Code here
		vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
		return solve(s, t, s.size() - 1, t.size() - 1, dp);
	}
};

class Solution1
{
public:
	int solve(string s1, string s2, int i, int j)
	{
		if (i == s1.size()) return s2.size() - j;
		if (j == s2.size()) return s1.size() - i;
		if (s1[i] == s2[j])
			return solve(s1, s2, i + 1, j + 1);
		else
		{
			return 1 + min(solve(s1, s2, i, j + 1), min(solve(s1, s2, i + 1, j), solve(s1, s2, i + 1, j + 1)));
		}
	}
	int editDistance(string s, string t)
	{
		// Code here
		return solve(s, t, 0, 0);
	}
};

class Solution
{
public:
	int solve(string s1, string s2, int i, int j, vector<vector<int>>& dp)
	{
		if (i == s1.size()) return s2.size() - j;
		if (j == s2.size()) return s1.size() - i;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (s1[i] == s2[j])
			return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
		else
		{
			return dp[i][j] = 1 + min(solve(s1, s2, i, j + 1, dp), min(solve(s1, s2, i + 1, j, dp), solve(s1, s2, i + 1, j + 1, dp)));
		}
	}
	int editDistance(string s, string t)
	{
		// Code here
		vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
		return solve(s, t, 0, 0, dp);
	}
};

// { Driver Code Starts.
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		Solution ob;
		int ans = ob.editDistance(s, t);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends