#include <bits/stdc++.h>

using namespace std;

int main() {
	int T = 1;
	// cin >> T;
	while (T--) {
		int x, y, h;
		cin >> x >> y >> h;
		cout << (x + (h - 1)*y) << endl;
	}
}