#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPalindrome(string s)
{
	string rev = s;
	reverse(s.begin(), s.end());
	return rev == s;
}

string longestPalin (string s) {
	// code here
	int ans = 0, n = s.size(), start = -1;
	for (int i = 0; i < n; i++)
	{
		string temp;
		for (int j = i; j < n; j++)
		{
			temp += s[j];
			//cout << temp << endl;
			if (isPalindrome(temp))
			{
				int n = temp.size();
				if (ans < n)
				{
					ans = n;
					start = i;
				}
			}
		}
	}
	return s.substr(start, ans);
}

int longestPalindrome(string s)
{
	int n = s.size(), maxLength = 1;
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			maxLength = max(maxLength, 2);
		}
	}
	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i < (n - k + 1); i++)
		{
			int j = i + k - 1;
			if (s[i] == s[j] and dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				maxLength = max(maxLength, k);
			}
		}
	}
	return maxLength;
}

string longestPalindrome1(string s)
{
	int n = s.size(), maxLength = 1, start = 0;
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			maxLength = max(maxLength, 2);
			start = i;
		}
	}
	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i < (n - k + 1); i++)
		{
			int j = i + k - 1;
			if (s[i] == s[j] and dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				if (maxLength < k)
				{
					maxLength = max(maxLength, k);
					start = i;
				}
			}
		}
	}
	return s.substr(start, maxLength);
}

int lengthOfLongestPalindromicSubstring(string s, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string temp;
		for (int j = i; j < n; j++)
		{
			temp += s[j];
			//cout << temp << endl;
			if (isPalindrome(temp))
			{
				int n = temp.size();
				ans = max(ans, n);
			}
		}
	}
	return ans;
}

void solve() {
	string s; cin >> s;
	int n = s.size();
	int dp[n][2] = {0};
	int x1 = 0, y1 = -1;
	int x2 = 0, y2 = -1;
	int mx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		if (i > y1) k = 1;
		else k = min(dp[x1 + y1 - i][0], y1 - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
		dp[i][0] = k--;
		if (i + k > y1) x1 = i - k, y1 = i + k;
		if (2 * dp[i][0] - 1 > mx) ans = i - k, mx = 2 * dp[i][0] - 1;
		k = 0;
		if (i <= y2) k = min(dp[x2 + y2 - i + 1][1], y2 - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
		dp[i][1] = k--;
		if (i + k > y2) x2 = i - k - 1, y2 = i + k;
		if (2 * dp[i][1] > mx) ans = i - k - 1, mx = 2 * dp[i][1];
	}
	cout << s.substr(ans, mx);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	// int t;
	// cin >> t;
	// while (t--)
	// {
	// int n;
	// cin >> n;
	// string s;
	//cin >> s;
	// getline(cin, s);
	//cout << longestPalindrome1(s) << endl;
	//cout << longestPalin(s) << endl;
	// }


	return 0;
}