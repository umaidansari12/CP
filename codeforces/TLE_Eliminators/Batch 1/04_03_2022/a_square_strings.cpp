#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve(string s) {
	int n = s.size();
	if (n % 2 != 0) return false;

	for (int i = 0; i < (n / 2); i++) {
		if (s[i] != s[i + (n / 2)])
			return false;
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
	while (t--) {
		string s;
		cin >> s;

		if (solve(s))
			cout << "YES\n";
		else
			cout << "NO\n";

	}


	return 0;
}