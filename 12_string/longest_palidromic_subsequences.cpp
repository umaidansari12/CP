#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPalindrome(string s) {
	int _size = s.size();

	for (int i = 0; i <= (_size / 2); i++) {
		if (s[i] != s[_size - i - 1])
			return false;
	}

	return true;
}

long long int longestPalindromicSubsequence(string s) {
	long long int _max = 0;
	long long int _size = s.size();
	for (int i = 0; i < _size; i++) {
		string temp = "";
		for (int j = i; j < _size; j++) {
			temp += s[j];
			if (isPalindrome(temp)) {
				_max = max(_max, (long long int)temp.size());
			}
		}
	}

	return _max;
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
		cout << longestPalindromicSubsequence(s) << endl;
	}


	return 0;
}