#include <bits/stdc++.h>

using namespace std;

int main() {
	int T = 1;
	// cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		if ((a + b + (a * b)) == 111)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}