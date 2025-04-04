#include <bits/stdc++.h>

using namespace std;

int brute(int n, int k) {
	int count = 0;
	while (n > 0) {
		for (int i = k; i >= 0; i--) {
			if ((n % 2) == 0 and (i % 2) == 0) {
				n -= i;
				break;
			}
			else if ((n % 2) != 0 and (i % 2) != 0) {
				n -= i;
				break;
			}
		}
		count++;
	}
	return count;
}

int optimal(int n, int k) {
	return 0;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;

		cout << brute(n, k) << endl;

	}

}