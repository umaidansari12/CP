#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
		if (s.size() > 10)
		{
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
		}
		else
			cout << s << endl;
	}

	return 0;
}