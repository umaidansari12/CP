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
		int n, ans = 0, x, left = 1, right = 0;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			if (a[i] == a[i + 1]) {
				left = i + 1;
			}
			else
				break;
		}

		for (int i = 0; i < n; i++) {

			if (a[i] == 0) {
				right = i + 1;
			}
		}
		//cout << right << " " << left << " ";
		cout << (right - left) + 1 << endl;

	}


	return 0;
}