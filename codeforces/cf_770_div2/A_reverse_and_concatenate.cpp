#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(string s, int n, int k, map<string, int> &m) {
	if (k == 0) {
		m[s]++;
		return;
	}

	string a = s;
	reverse(a.begin(), a.end());
	solve(s + a, n, k - 1, m);
	solve(a + s, n, k - 1, m);
}

bool palindrome(string s, int n) {
	for (int i = 0; i <= (n / 2); i++) {
		if (s[i] != s[n - i - 1])
			return false;
	}

	return true;

}

void solve1(string s, int n, int k) {
	if (k == 0) {
		cout << 1 << endl;
		return;
	}

	if (palindrome(s, n)) {
		cout << 1 << endl;
		return;
	}
	cout << 2 << endl;

}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		//map<string, int> m;
		//solve(s, n, k, m);
		//cout << m.size() << endl;
		solve1(s, n, k);
	}


	return 0;
}