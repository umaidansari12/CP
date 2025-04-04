#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N <= 10) {
			cout << "Lower Double\n";
		}
		else if (N > 10 and N <= 15) {
			cout << "Lower Single\n";
		}
		else if (N > 15 and N <= 25) {
			cout << "Upper Double\n";
		}
		else {
			cout << "Upper Single\n";
		}
	}
}