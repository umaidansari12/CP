#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N % 2 == 0) {
			for (int i = N; i >= 1; i--)
				cout << i << " ";
			cout << endl;
		}
		else
			cout << -1 << endl;
	}
}