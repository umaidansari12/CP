#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string getSmallestString(string s, int k) {
		int n = s.size();
		for (int i = 0; i < n; i++) {
			int _min_distance = min(s[i] - 'a', 26 - (s[i] - 'a'));
			if (k >= _min_distance) {
				k -= _min_distance;
				s[i] = 'a';
			}
			else {
				s[i] = s[i] - k;
				k = 0;
			}
			// cout << s[i] << endl;
			// cout << s[i] - 'a' << endl;
			// cout << (26 - (s[i] - 'a')) << endl;

		}
		return s;

	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		int k;
		cin >> s;
		cin >> k;
		Solution ob = Solution();
		cout << ob.getSmallestString(s, k) << endl;
	}
}

/*
I:
3
zbbz
3
xaxcd
4
lol
0
O:
aaaz
aawcd
lol

*/