#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string s1, string s2)
{
	if (s1.size() != s2.size())
	{
		return 0;
	}
	if (s1.compare(s2) == 0)
		return 0;
	int pos = -1;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			pos = i;
			break;
		}
	}
	for (int i = 0; i < s2.size(); i++)
	{
		if (s1[pos] == s2[i] && s1[i] == s2[pos])
			swap(s2[pos], s2[i]);
	}
	if (s1.compare(s2) == 0)
		return 1;
	else
		return 0;
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
		cin >> s1;
		cin.ignore();
		cin >> s2;
		if (solve(s1, s2))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}