#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool palindrome(string s) {

	int n = s.size();
	for (int i = 0; i <= (n / 2); i++) {
		if (s[i] != s[n - i - 1])
			return false;
	}
	return true;
}


bool solve(int idx, string s, int n, int k) {
	if (idx == n) {
		if (k == 0 and palindrome(s)) {
			//cout << s << endl;
			return true;
		}
		return false;
	}
	if (s[idx] == '1')
		s[idx] = '0';
	else
		s[idx] = '1';
	//s[idx] = (s[idx] + 1) % 1;
	bool ans1 = solve(idx + 1, s, n, k - 1);
	//s[idx] = (s[idx] + 1) % 1;
	if (s[idx] == '1')
		s[idx] = '0';
	else
		s[idx] = '1';
	bool ans2 = solve(idx + 1, s, n, k);

	return ans1 or ans2;
}


bool solve1(string s, int _size, int k) {
	for (int i = 0; i <= (_size / 2); i++) {
		if (s[i] != s[_size - i - 1]) {
			k--;
		}
	}

	return k == 0;
}

bool solve2(string s, int _size, int k) {
	for (int i = 0; i <= (_size / 2); i++) {
		if (s[i] != s[_size - i - 1]) {
			k--;
		}
	}

	if (k < 0)
		return false;
	else if (k >= 0 and (k % 2) == 0 and _size % 2 == 0)
		return true;
	else if (k >= 0 and (_size % 2) == 1)
		return true;
	return false;
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
		if (solve2(s, n, k))
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}