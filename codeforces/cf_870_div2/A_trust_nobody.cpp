#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, l, equal = 0, not_equal = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> l;
			if (l == n)
				equal++;
			else
				not_equal++;
		}
		if (equal == n)
			cout << -1 << endl;
		else
			cout << n - not_equal << endl;
	}
}

