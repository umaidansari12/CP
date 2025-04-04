#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m = 1e9 + 7;
		cin >> n;
		vector<int> a(n, 0);
		vector<int> b(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int prod_sum = 0;
		for (int i = 0; i < n; i++) {
			prod_sum += ((a[i] * b[i]) / 2) % m;
		}
		cout << prod_sum << endl;
	}
}