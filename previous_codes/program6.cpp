#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	string s, ans = "";
	cin >> s;
	for (int i = 0; i < s.size(); i += 2)
	{
		if (i + 1 < s.size())
			ans += to_string(max(s[i] - '0', s[i + 1] - '0'));
		else
			ans += to_string(s[i] - '0');
	}

	cout << ans << endl;

	return 0;
}