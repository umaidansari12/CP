#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int N, K, L, m, l;
		cin >> N >> K >> L;
		set<long long int, greater<long long int>> playlist;
		for (int i = 0; i < N; i++) {
			cin >> m >> l;
			if (l == L) {
				playlist.insert(m);
			}
		}

		int _size = playlist.size();

		if (_size < K)
			cout << -1 << endl;
		else {
			auto it = playlist.begin();
			long long int sum = 0;
			while (K--) {
				sum += (*it);
				it++;
			}
			cout << sum << endl;
		}
		// long long int N, K, L, m, l;
		// cin >> N >> K >> L;
		// vector<long long int> playlist;
		// for (int i = 0; i < N; i++) {
		// 	cin >> m >> l;
		// 	if (l == L) {
		// 		playlist.push_back(m);
		// 	}
		// }

		// int _size = playlist.size();

		// if (_size < K)
		// 	cout << -1 << endl;
		// else {
		// 	sort(playlist.begin(), playlist.end(), greater<int>());
		// 	auto it = playlist.begin();
		// 	long long int sum = 0;
		// 	for (int i = 0; i < K; i++) {
		// 		sum += playlist[i];
		// 	}
		// 	cout << sum << endl;
		// }
	}
}