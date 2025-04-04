#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, cost = 0;
		cin >> N;
		vector<int> a(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < N; i++) {
			cost += max(a[i] - i, 0);
		}
		cout << cost << endl;
	}
}