#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		if (x >= (n / 2.0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}