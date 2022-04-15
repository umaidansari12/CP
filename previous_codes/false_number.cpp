#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string solve()
{
	string s;
	cin >> s;
	if (s[0] == '1')
	{
		s.insert(1, "0");
	}
	else
	{
		s.insert(0, "1");
	}
	return s;
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
		cout << solve() << endl;
	}


	return 0;
}