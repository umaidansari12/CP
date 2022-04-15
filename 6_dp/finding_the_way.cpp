#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void printSubsequence(string s, string res, int idx)
{
	if (idx == s.size())
	{
		cout << res << '\n';
		return;
	}

	printSubsequence(s, res + s[idx], idx + 1);
	printSubsequence(s, res, idx + 1);
}

int solve(string s, int idx, int x, int y, int n, string r, set<string> &st)
{
	if (x == y and idx == n)
	{
		if (st.find(r) == st.end())
		{
			st.insert(r);
			return 1;
		}
		else
			return 0;
	}


	if (x > n or x < 0)
		return 0;
	if (idx >= n)
		return 0;
	int ans = 0;
	if (s[idx] == 'r')
		ans += solve(s, idx + 1, x + 1, y, n, r + s[idx], st);
	else if (s[idx] == 'l')
		ans += solve(s, idx + 1, x - 1, y, n, r + s[idx], st);

	ans += solve(s, idx + 1, x, y, n, r, st);
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
		string s;
		cin >> s;
		int x, y, n;
		cin >> n >> x >> y;
		set<string> st;
		cout << solve(s, 0, x, y, n, "", st) << endl;
		//printSubsequence(s, "", 0);

	}

	return 0;
}