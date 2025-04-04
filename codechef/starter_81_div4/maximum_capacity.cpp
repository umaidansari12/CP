#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x <= 8 and (x * y) <= 500) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
