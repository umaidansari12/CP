#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countSubstrings(string s) {
	map<char, int> m;
	m['a'] = 1;
	m['b'] = 1;
	m['c'] = 2;
	m['d'] = 2;
	m['e'] = 2;
	m['f'] = 3;
	m['g'] = 3;
	m['h'] = 3;
	m['i'] = 4;
	m['j'] = 4;
	m['k'] = 4;
	m['l'] = 5;
	m['m'] = 5;
	m['n'] = 5;
	m['o'] = 6;
	m['p'] = 6;
	m['q'] = 6;
	m['r'] = 7;
	m['s'] = 7;
	m['t'] = 7;
	m['u'] = 8;
	m['v'] = 8;
	m['w'] = 8;
	m['x'] = 9;
	m['y'] = 9;
	m['z'] = 9;
	cout << s << endl;
	int count = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		int mapped = 0;
		for (int j = i; j < n; j++) {
			char ch = s[j];
			mapped += m[ch];
			if ((mapped % ((j - i) + 1)) == 0)
				count++;
		}
	}
	return count;
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
		cout << countSubstrings(s) << endl;
	}


	return 0;
}