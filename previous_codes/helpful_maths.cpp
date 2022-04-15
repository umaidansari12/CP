#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	map<char, int> m;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '+')
			m[s[i]]++;
	}
	s = "";
	for (auto i : m)
	{
		while (i.second--)
			s = s + i.first + '+';
	}
	cout << s.substr(0, s.length() - 1) << endl;


	return 0;
}