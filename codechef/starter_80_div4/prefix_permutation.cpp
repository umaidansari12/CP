#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
		/*		int n, sum = 1;
				cin >> n;
				int prev = 1;
				for (int i = 1; i <= n; i++) {
					if ((sum + prev) % i != 0) {
						prev++;
					}
					else {
						prev += 2;
					}
					sum += prev;
					cout << prev << " ";

				}
				cout << "\n";*/
		int n;
		cin >> n;
		if (n % 2 != 0) {
			cout << "-1";
		}
		else {
			for (int i = 1; i <= n; i += 2) {
				cout << i + 1 << " " << i << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
