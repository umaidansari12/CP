#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve(long long int x) {
	if (x == 0)
		return 1;
	else if (x == 1)
		return 2;
	else if (x == 2)
		return 2;
	else {
		long long int ans = 1;
		while (2 * ans < x)
			ans *= 2;
		if (ans == x) {
			return x;
		}
		else if (x == (2 * ans - 1))
			return x + 1;
		else
			return ans;
	}
	return -1;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int n, _or = 0;
		cin >> n;
		cout << solve(n) << endl;
		// for (long long int i = 0; i <= n; i++) {
		// 	_or |= i;
		// }
		// cout << _or << endl;
	}


	return 0;
}