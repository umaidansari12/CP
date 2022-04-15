#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, x = 0;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		if (s[0] == '+' or s[s.size() - 1] == '+')
			x++;
		else if (s[0] == '-' or s[s.size() - 1] == '-')
			x--;
	}
	cout << x << endl;


	return 0;
}