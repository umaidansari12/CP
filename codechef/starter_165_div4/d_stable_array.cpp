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
		vector<int> temp = a;
		sort(temp.begin(), temp.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (temp[i] != a[i])
				ans++;
		}
		cout << ans << endl;
	}
}