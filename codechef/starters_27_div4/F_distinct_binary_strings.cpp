#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(string s, int n) {
	unordered_set<string> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		if (i == 0) {
			a = "";
		}
		else
			a = s.substr(0, i);
		if (i == n - 1)
			b = "";
		else
			b = s.substr(i + 1);

		//cout << a << ":" << b << endl;
		m.insert(a + b);
	}

	return m.size();
}

int upSolve(string s, int n) {
	int continuous_blocks = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[i + 1]) {
			continuous_blocks++;
		}
	}

	return continuous_blocks;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		cout << upSolve(s, n) << endl;

	}


	return 0;
}