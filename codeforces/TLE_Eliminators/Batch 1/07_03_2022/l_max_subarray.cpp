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
		int n;
		cin >> n;
		int a[n] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {

			for (int j = i; j < n; j++) {
				int _max = INT_MIN;
				for (int k = i; k <= j; k++) {
					_max = max(a[k], _max);
				}
				cout << _max << " ";
			}
		}

		cout << endl;
	}


	return 0;
}