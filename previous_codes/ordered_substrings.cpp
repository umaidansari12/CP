#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int orderedSubstring(string x)
{
	int n = x.size();
	set<string> se;
	for (int i = 0; i < n; i++)
	{
		string s;
		for (int j = i; j < n; j++)
		{
			s += x[j];
			se.insert(s);
		}
	}
	int cnt = 0;
	for (auto i : se)
	{
		if (i == x)
			return cnt + 1;
		cnt++;
	}
	return 0;
}

bool comp(string a, string b)
{
	return a < b;
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
		string x;
		cin >> x;
		cout << orderedSubstring(x) << endl;

	}


	return 0;
}