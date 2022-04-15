#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int value(char c)
{
	if (c == 'I')
		return 1;
	if (c == 'V')
		return 5;
	if (c == 'X')
		return 10;
	if (c == 'L')
		return 50;
	if (c == 'C')
		return 100;
	if (c == 'D')
		return 500;
	if (c == 'M')
		return 1000;
	return 0;
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
		string s;
		cin >> s;
		int res = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int s1 = value(s[i]), s2;
			if (i + 1 < s.size())
			{
				s2 = value(s[i + 1]);
				if (s1 >= s2)
				{
					res += s1;
				}
				else
				{
					res = res + s2 - s1;
					i++;
				}
			}
			else
			{
				res += s1;
			}
		}
		cout << res << endl;
	}



	return 0;
}

class Solution {
public:
	int value(char c)
	{
		if (c == 'I')
			return 1;
		if (c == 'V')
			return 5;
		if (c == 'X')
			return 10;
		if (c == 'L')
			return 50;
		if (c == 'C')
			return 100;
		if (c == 'D')
			return 500;
		if (c == 'M')
			return 1000;
		return 0;
	}

	int romanToInt(string s) {
		int n = s.size(), r = 0;
		for (int i = 0; i < n; i++)
		{
			int s1 = value(s[i]), s2;
			if (i + 1 < n)
			{
				s2 = value(s[i + 1]);
				if (s1 >= s2)
				{
					r += s1;
				}
				else
				{
					r = r + s2 - s1;
					i++;
				}
			}
			else
			{
				r += s1;
			}
		}
		return r;
	}
};