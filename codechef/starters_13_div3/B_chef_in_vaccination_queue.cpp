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
		int n, p, x, y, time = 0, a = 0;
		cin >> n >> p >> x >> y;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (i < p) {
				if (a == 0)
					time += x;
				else
					time += y;
			}
		}
		cout << time << endl;
	}

	return 0;
}