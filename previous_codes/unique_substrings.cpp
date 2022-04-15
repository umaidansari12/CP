#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string uniqueSubstringsBrute(string s, int n)
{
	string res;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		set<char> se;
		for (int j = i; j < n; j++)
		{
			if (se.find(s[j]) == se.end())
			{
				if (ans < (j - i + 1))
				{
					ans = j - i + 1;
					res = s.substr(i, j - i + 1);
				}
			}
			else
				break;
			se.insert(s[j]);
		}
	}
	return res;
}

string uniqueSubstrings(string str, int n)
{
	int window_len = 0, max_window_len = 0, start_window = -1;
	string res;
	int i = 0, j = 0;
	unordered_map<char, int> cnt;
	while (j < n)
	{
		if (cnt.count(str[j]) and cnt[str[j]] >= i)
		{
			i = cnt[str[j]] + 1;
			window_len = j - i;
		}
		cnt[str[j]] = j;
		j++;
		window_len++;
		if (window_len > max_window_len)
		{
			max_window_len = window_len;
			start_window = i;
		}
	}
	return str.substr(start_window, max_window_len);
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size(), ans = 0;
		cout << uniqueSubstrings(s, n) << endl;

	}


	return 0;
}