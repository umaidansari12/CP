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
		long long int n;
		cin >> n;
		if (n == 1 or n == 2) {
			cout << 1 << "\n";
		}
		else {
			cout << (long long)(n - 1)*(n - 2) + 1 << "\n";
		}
		// long long int n;
		// scanf("%lld", &n);
		// long long int sum = 1;
		// for (long long int i = 2; i < n; i += 2) {
		// 	sum += i;
		// }
		//long long int sum = ((n - 2) * (n - 1)) + 1;
		// cout << sum << endl;
		//printf("%lld\n", sum);
	}


	return 0;
}