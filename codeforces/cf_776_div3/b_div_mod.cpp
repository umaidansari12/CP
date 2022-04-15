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
		long long int l, r, a, ans = 0;
		cin >> l >> r >> a;
		if (r % a == 0) {
			r -= 1;
		}
		ans = (r / a) + (r % a);
		cout << ans << endl;
	}


	return 0;
}