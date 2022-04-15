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
		int n, x, count = 8;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == 6 or x == 7 or x == 13 or x == 14 or x == 20 or x == 21 or x == 27 or x == 28)
				continue;
			else
				count++;
		}

		cout << count << endl;
	}

	return 0;
}