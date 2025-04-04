#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int lengthAfterTransformations(string s, int t) {
		int _size = s.size(), cnt = 0;
		for (int i = 0; i < _size; i++) {
			if ((s[i] + t) % 26 > 122)
				cnt += (s[i] + t) / 26;
		}
		return _size + cnt;
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		int t;
		cin >> t;
		Solution ob;
		cout << ob.lengthAfterTransformations(S, t) << endl;
	}
}