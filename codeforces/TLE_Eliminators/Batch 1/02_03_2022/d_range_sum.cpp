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
		long long int l, r, sum = 0;
		cin >> l >> r;
		if (l > r)
			swap(l, r);
		// for (ll i = l; i <= r; i++) {
		// 	sum += i;
		// }
		// cout << sum << "\n";

		long long int sumRight = (r * (r + 1)) / (long long int)2 ;
		long long int sumLeft =  (l * (l - 1)) / (long long int)2;
		long long int ans = sumRight - sumLeft;
		cout << ans << "\n";
	}

	return 0;
}