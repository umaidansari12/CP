#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int gcd(long long int x, long long int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

long long int lcm(long long int x, long long int y) {
	long long int _gcd = gcd(x, y);
	long long int lcm = (x * y) / _gcd;
	return lcm;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		long long int x, k;
		cin >> x >> k;
		cout << x * 2 << " " << lcm(x * k, (x * k) - 1) << endl;
	}

	return 0;
}