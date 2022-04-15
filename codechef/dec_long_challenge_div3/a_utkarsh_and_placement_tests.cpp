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
		char c[3], x, y;
		for (int i = 0; i < 3; i++) {
			cin >> c[i];
		}
		cin >> x >> y;
		int idx_x = -1, idx_y = -1;
		for (int i = 0; i < 3; i++) {
			if (c[i] == x)
				idx_x = i;
			if (c[i] == y)
				idx_y = i;
		}
		if (idx_x < idx_y) {
			cout << x << endl;
		}
		else
			cout << y << endl;
	}


	return 0;
}