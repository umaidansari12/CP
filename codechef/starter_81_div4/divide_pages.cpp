#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int n, a;
		long long int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		if (sum % 2 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
