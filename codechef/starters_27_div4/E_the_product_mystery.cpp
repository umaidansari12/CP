#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long int solve(long long int b, long long int c) {
	for (long long int a = 1; a <= 1e9; a++) {
		if ((a * b) % (long long int)c == 0) {
			return a;
		}
	}
	return 0;
}

long long int solve1(long long int b, long long int c) {

	return c / __gcd(b, c);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long int a, b, c;
		cin >> b >> c;
		cout << solve1(b, c) << endl;

	}


	return 0;
}