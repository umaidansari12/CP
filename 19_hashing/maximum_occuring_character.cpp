#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char maximumOccurringCharacter(string text) {
	map<char, int> m;
	int n = text.size(), _max = 0;
	for (int i = 0; i < n; i++) {
		m[text[i]]++;
		_max = max(_max, m[text[i]]);
	}

	for (char i : m) {
		if (i.second == _max)
			return i.first;
	}
	return 'a';
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

	}

	return 0;
}