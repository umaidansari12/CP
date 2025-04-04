#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> a(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		if (N <= 3)
			cout << 0 << endl;
		else {
			sort(a.begin(), a.end());
			int answer = min(a[N - 1] - a[2], min(a[N - 3] - a[0], a[N - 2] - a[1]));
			cout << answer << "\n";
		}
	}
}