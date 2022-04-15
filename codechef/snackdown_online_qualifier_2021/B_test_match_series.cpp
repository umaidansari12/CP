#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int india = 0, draw = 0, england = 0, x;
		for (int i = 0; i < 5; i++) {
			cin >> x;
			if (x == 0)
				draw++;
			else if (x == 1)
				india++;
			else if (x == 2)
				england++;
		}
		if (india > england) {
			cout << "INDIA\n";

		}
		else if (england > india) {
			cout << "ENGLAND\n";

		}
		else {
			cout << "DRAW\n";
		}

	}
	return 0;
}