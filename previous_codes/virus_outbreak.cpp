#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve(string v)
{
	string s;
	cin >> s;
	int j = 0;
	for (int i = 0; i < v.length(); i++)
	{
		if (v[i] == s[j])
		{
			j++;
		}
	}
	if (j == s.length())
		return "POSITIVE";
	return "NEGATIVE";
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string v;
	cin >> v;
	int n;
	cin >> n;
	while (n--)
	{
		cout << solve(v) << endl;
	}


	return 0;
}