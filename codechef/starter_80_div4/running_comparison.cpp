#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
		int n, cnt = 0;
		cin >> n;
		vector<int> a(n, 0), b(n, 0), happy_a(n, 1), happy_b(n, 1);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++) {
			if ((2 * a[i]) < b[i]) {
				happy_a[i] = 0;
			}
			if ((2 * b[i]) < a[i]) {
				happy_b[i] = 0;
			}
			cnt += (happy_a[i] == happy_b[i]);
		}
		cout << cnt << "\n";
	}
	return 0;
}
