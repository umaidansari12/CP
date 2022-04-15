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
		long long int a, b, _max, _min;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << endl;
		}
		else if (a < b) {
			long long int diff = b - a;
			if (diff % 2 == 0) {
				cout << diff / 2 << endl;
			}
			else {
				cout << ((diff + 1) / 2) + 1 << endl;
			}
		}
		else if (a > b) {
			cout << a - b << endl;
		}
		// _max = max(a, b);
		// _min = min(b, a);
		// long long int diff = b - a;
		// if (diff % 2 == 0) {
		// 	cout << diff / 2 << endl;
		// }
		// else {
		// 	cout << ((diff + 1) / 2) + 1 << endl;
		// }
	}

	return 0;
}
