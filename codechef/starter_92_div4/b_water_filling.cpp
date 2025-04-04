#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int b1, b2, b3;
		cin >> b1 >> b2 >> b3;
		if ((b1 == 0 and b2 == 0) or (b1 == 0 and b3 == 0) or (b2 == 0 and b3 == 0))
			cout << "Water filling time\n";
		else
			cout << "Not now\n";
	}
}