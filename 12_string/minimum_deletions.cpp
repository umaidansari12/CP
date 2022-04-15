#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool palindrome(string empty) {
	int n = empty.size();
	for (int i = 0; i <= (n / 2); i++) {
		if (empty[i] != empty[n - i - 1])
			return false;
	}

	return true;
}

void solve(int idx, string s, string empty, int &_min) {
	//logic is find the biggest palindrome after finding the biggest palindrome out of the current string such its deletion should be minimum
	if (idx == s.size()) {
		if (palindrome(empty)) {
			//cout << empty << endl;
			_min = min(_min, (int)s.size() - (int) empty.size());
		}
		return;
	}

	solve(idx + 1, s, empty, _min);
	solve(idx + 1, s, empty + s[idx], _min);
}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s, empty;
		cin >> s;
		int _min = INT_MAX;
		solve(0, s, empty, _min);
		cout << _min << endl;
	}

	return 0;
}