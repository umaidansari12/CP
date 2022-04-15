#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	long long int n;
	cin >> n;
	for (long long int i = -n; i <= n; i++) {
		long long int sum = 0;
		for (long long int low = i; low <= n; low++) {
			sum += low;
			if (sum == n) {
				cout << i << " " << low << endl;
				return;
			}
		}

	}
}

void solve1() {
	long long int n;
	cin >> n;
	cout << -(n - 1) << " " << n << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve1();

	}

	return 0;
}