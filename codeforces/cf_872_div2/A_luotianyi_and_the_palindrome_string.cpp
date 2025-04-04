#include <bits/stdc++.h>

using namespace std;


bool checkPalindrome(string s) {
	int n = s.size();
	for (int i = 0; i <= (n / 2); i++) {
		if (s[i] != s[n - i - 1])
			return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int _size = s.size();
		unordered_map<char, int> freq;
		for (int i = 0; i < _size; i++) {
			freq[s[i]]++;
		}
		if (_size % 2 == 0) {
			cout << -1 << endl;
		}
		else {
			if (freq[s[(_size / 2)]] == 1) {
				cout << _size - 1 << endl;
			}
			else
				cout << -1 << endl;
		}
	}
}

