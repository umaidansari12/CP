#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// log properties
// a^b => log ab (x) =
// a^b => b*log(a)


void solve(long long int a, long long int b, long long int c, long int d) {
	long long int ab, cd;

	ab = pow(a, b);
	cd = pow(c, d);
	if (ab > cd)
		cout << "YES\n";
	else
		cout << "NO\n";

}

void solve1(long long int a, long long int b, long long int c, long long int d) {
	long long int ab = 1, cd = 1;
	for (int i = 1; i <= b; i++) {
		ab *= a;
	}
	for (int i = 1; i <= d; i++) {
		cd *= c;
	}
	if (ab > cd)
		cout << "YES\n";
	else
		cout << "NO\n";
}

void solve2(long long int a, long long int b, long long int c, long long int d) {
	double ab = b * log(a), cd = d * log(c);
	if (ab > cd)
		cout << "YES\n";
	else
		cout << "NO\n";

}


int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int a, b, c, d, ab, cd;
	cin >> a >> b >> c >> d;
	solve2(a, b, c, d);


	return 0;
}