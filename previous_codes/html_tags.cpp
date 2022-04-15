#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve()
{
	string s;
	cin >> s;
	if (s.size() < 4)
		return false;
	if (s[0] != '<' or s[1] != '/' or s[s.size() - 1] != '>')
		return false;

	for (int i = 2; i < s.size() - 1; i++)
	{
		if (!((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= '0' and s[i] <= '9')))
		{
			return false;
		}
	}

	return true;
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
		if (solve())
			cout << "Success\n";
		else
			cout << "Error\n";
	}


	return 0;
}