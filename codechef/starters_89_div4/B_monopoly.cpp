#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int p, q, r, s;
		cin >> p >> q >> r >> s;
		if (p > (q + r + s) or q > (p + r + s) or r > (p + q + s) or s > (p + q + r))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}